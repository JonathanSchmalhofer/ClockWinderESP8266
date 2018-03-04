//
//  WatchWinder.cpp - Library for WatchWinder based on ESP8266.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "WatchWinder.h"

WatchWinder::WatchWinder()
    : wifi_manager_(),
      save_config_(false)
{
	strcpy(mqtt_port_, "8080");
	strcpy(blynk_token_, "YOUR_BLYNK_TOKEN");

	strcpy(static_ip_, "10.0.1.56");
	strcpy(static_gateway_, "10.0.1.1");
	strcpy(static_subnet_, "255.255.255.0");
}

void WatchWinder::Setup()
{
    if (SPIFFS.begin())
    {
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
						// Serial.println("no custom ip in config");
					}
				}
				else
				{
					// Serial.println("failed to load json config");
				}
			}
		}
    }
    else
    {
		// Serial.println("failed to mount FS");
    }
	// first parameter is name of access point, second is the password
    wifi_manager_.autoConnect("WatchWinderESP8266", "watchwinder");
}

void WatchWinder::Step()
{
}

void WatchWinder::SaveConfigCallback()
{
    save_config_ = true;
}
