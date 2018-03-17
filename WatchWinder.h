//
//  WatchWinder.h - Library for WatchWinder based on ESP8266.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHWINDER_H
#define WATCHWINDER_H

#include <FS.h>                   // this needs to be first, or it all crashes and burns...

#include <Arduino.h>
#include <ESP8266WiFi.h>          // ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            // Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     // Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          // https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson

#include "NTPClient.h"

#include "WatchMovementSupplier.h"

#include "Timesettings.h"

#include "data.h"
#include <time.h>

#define BUFFER_SIZE 10000


class WatchWinder
{
public:
    WatchWinder();
    
    void Setup();
    void Step();
    void AddWatchMovementSupplier();
    std::vector<WatchMovementSupplier> GetAllWatchMovementSuppliers();
private:
    void SetupWatchMovementSuppliers();
    void ReadConfig();
    void SetupWifiManager();
    void SetupMovement();
    void SetupNTPClient();
    bool InAllowedTimeFrameOfDay();
    void HandleRoot();
    void HandleSettingsHTML();
    void HandleWatchesHTML();
    void HandleInfoHTML();
    void HandleTimesettingsJS();
    void HandleWatchesJS();
    void HandleFunctionsJS();
    void HandleStyleCSS();
    void HandleTimesettingsJSON();
    void HandleTimesettingsSaveJSON();
    void HandleTimesettingsResetJSON();
    void HandleRestartESPJSON();
    void SaveConfigCallback();
    void SendFile(int code, String type, const char* adr, size_t len);
    void SendHeader(int code, String type, size_t _size);
    void SendBuffer();
    void SendToBuffer(String str);
    time_t ConvertEpochHourToUnixTimestamp(int hour, int relative_to_gmt);
	void ApplyTimesettings();

    WiFiManager wifi_manager_;
    ESP8266WebServer web_server_;
    
    Timesettings timesettings_;

    // define your default values here, if there are different values in config.json, they are overwritten.
    char mqtt_server_[40];
    char mqtt_port_[6];
    char blynk_token_[34];

    // default custom static IP
    char static_ip_[16];
    char static_gateway_[16];
    char static_subnet_[16];

    bool save_config_;
    
    std::vector<WatchMovementSupplier> watch_movement_suppliers_;
    time_t earliest_allowed_movement_;
    time_t latest_allowed_movement_;

    int buffer_counter_; //buffer counter;

    char data_website_buffer_[BUFFER_SIZE];
};

#endif // #ifndef WATCHWINDER_H
