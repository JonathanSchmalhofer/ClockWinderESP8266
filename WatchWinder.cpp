//
//  WatchWinder.cpp - Library for WatchWinder based on ESP8266.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "WatchWinder.h"

WatchWinder::WatchWinder()
    : wifi_manager_(),
	  web_server_(80),
      save_config_(true)
{
    strcpy(mqtt_port_, "8080");
    strcpy(blynk_token_, "YOUR_BLYNK_TOKEN");

    strcpy(static_ip_, "10.0.1.56");
    strcpy(static_gateway_, "10.0.1.1");
    strcpy(static_subnet_, "255.255.255.0");
}

void WatchWinder::Setup()
{
    Serial.println("###################################################");

    SetupWifiManager();
    SetupMovement();
    SetupNTPClient();
	web_server_.on("/", (std::bind(&WatchWinder::HandleRoot, this)));
	web_server_.begin();
    Serial.println("HTTP server started");
}

void WatchWinder::HandleRoot()
{
    web_server_.send(200, "text/plain", "hello from esp8266!");
}

void WatchWinder::ReadConfig()
{
    if (SPIFFS.begin())
    {
        if (SPIFFS.exists("/config.json"))
        {
          if (SPIFFS.remove("/config.json"))
          {
            Serial.println("Deleted /config.json");
          }
        }
        if (SPIFFS.exists("/config.json"))
        {
        //file exists, reading and loading
        File configFile = SPIFFS.open("/config.json", "r");
        if (configFile)
        {
            size_t size = configFile.size();
            // Allocate a buffer to store contents of the file.
            std::unique_ptr<char[]> buf(new char[size]);

            configFile.readBytes(buf.get(), size);
            DynamicJsonBuffer jsonBuffer;
            JsonObject& json = jsonBuffer.parseObject(buf.get());
            json.printTo(Serial);
                if (json.success())
                {
                    strcpy(mqtt_server_, json["mqtt_server"]);
                    strcpy(mqtt_port_, json["mqtt_port"]);
                    strcpy(blynk_token_, json["blynk_token"]);

                    if(json["ip"])
                    {
                        strcpy(static_ip_, json["ip"]);
                        strcpy(static_gateway_, json["gateway"]);
                        strcpy(static_subnet_, json["subnet"]);
                    }
                    else
                    {
                        Serial.println("no custom ip in config");
                    }
                }
                else
                {
                    Serial.println("failed to load json config");
                }
            }
        }
    }
    else
    {
        Serial.println("failed to mount FS");
    }
}

void WatchWinder::SetupWifiManager()
{
    ReadConfig();

    // The extra parameters to be configured (can be either global or just in the setup)
    // After connecting, parameter.getValue() will get you the configured value
    // id/name placeholder/prompt default length
    WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server_, 40);
    WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port_, 6);
    WiFiManagerParameter custom_blynk_token("blynk", "blynk token", blynk_token_, 32);
	
	  //set config save notify callback
    //TODO:wifi_manager_.setSaveConfigCallback((std::bind(&WatchWinder::SaveConfigCallback, this)));

    // set static ip
    //wifi_manager_.setSTAStaticIPConfig(IPAddress(10,0,1,99), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    // add all your parameters here
    wifi_manager_.addParameter(&custom_mqtt_server);
    wifi_manager_.addParameter(&custom_mqtt_port);
    wifi_manager_.addParameter(&custom_blynk_token);

    // reset settings - for testing
    //wifi_manager_.resetSettings();

    // set minimu quality of signal so it ignores AP's under that quality
    // defaults to 8%
    //wifi_manager_.setMinimumSignalQuality();

    // sets timeout until configuration portal gets turned off
    // useful to make it all retry or go to sleep
    // in seconds
    //wifi_manager_.setTimeout(120);

    // fetches ssid and pass and tries to connect
    // if it does not connect it starts an access point with the specified name
    // here  "WatchWinderESP8266"
    // and goes into a blocking loop awaiting configuration
    if (!wifi_manager_.autoConnect("WatchWinderESP8266", "watchwinder")) // first parameter is name of access point, second is the password
    {
        Serial.println("failed to connect and hit timeout");
        delay(3000);
        // reset and try again, or maybe put it to deep sleep
        ESP.reset();
        delay(5000);
    }

    // if you get here you have connected to the WiFi
    Serial.println("connected...");

    // read updated parameters
    strcpy(mqtt_server_, custom_mqtt_server.getValue());
    strcpy(mqtt_port_, custom_mqtt_port.getValue());
    strcpy(blynk_token_, custom_blynk_token.getValue());

    // save the custom parameters to FS
    if (save_config_)
    {
        Serial.println("saving config");
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.createObject();
        json["mqtt_server"] = mqtt_server_;
        json["mqtt_port"] = mqtt_port_;
        json["blynk_token"] = blynk_token_;

        File configFile = SPIFFS.open("/config.json", "w");
        if (!configFile)
        {
            Serial.println("failed to open config file for writing");
        }

        json.printTo(Serial);
        json.printTo(configFile);
        configFile.close();
        // end save
    }

    Serial.println("local ip");
    Serial.println(WiFi.localIP());

}

void WatchWinder::SetupMovement()
{
}

void WatchWinder::SetupNTPClient()
{
    NTP.init((char *)"de.pool.ntp.org", UTC0100); // hardcoded: German NTP Server, Central European Time (CET = UTC + 01:00)
    NTP.setPollingInterval(60); // Poll every minute

    NTP.onSyncEvent([](NTPSyncEvent_t ntpEvent)
    {
        switch (ntpEvent)
        {
            case NTP_EVENT_INIT:
                break;
            case NTP_EVENT_STOP:
                break;
            case NTP_EVENT_NO_RESPONSE:
                Serial.printf("NTP server not reachable.\n");
                break;
            case NTP_EVENT_SYNCHRONIZED:
                Serial.printf("Got NTP time: %s\n", NTP.getTimeDate(NTP.getLastSync()));
            break;
        }
    });
}
void WatchWinder::SaveConfigCallback()
{
	Serial.println("Should save config");
	save_config_ = true;
}

void WatchWinder::Step()
{
    if( InAllowedTimeFrameOfDay() )
    {
        for (auto& watch_movement : watch_movement_suppliers_)
        {
        }
    }
	web_server_.handleClient();
}

bool WatchWinder::InAllowedTimeFrameOfDay()
{
    if( hour(now()) >= hour(earliest_allowed_movement_) &&
        hour(now()) <= hour(latest_allowed_movement_) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<WatchMovementSupplier> WatchWinder::GetAllWatchMovementSuppliers()
{
    return watch_movement_suppliers_;
}

void WatchWinder::AddWatchMovementSupplier()
{
    watch_movement_suppliers_.push_back(WatchMovementSupplier());
}
