//
//  WatchWinder.h - Library for WatchWinder based on ESP8266.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHWINDER_H
#define WATCHWINDER_H

#include <FS.h>                   //this needs to be first, or it all crashes and burns...

#include <Arduino.h>
#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include <ArduinoJson.h>          //https://github.com/bblanchon/ArduinoJson

class WatchWinder
{
public:
    WatchWinder();
	
	void Setup();
	void Step();
    void SaveConfigCallback();
private:
    WiFiManager wifi_manager_;

    //define your default values here, if there are different values in config.json, they are overwritten.
    char mqtt_server_[40];
    char mqtt_port_[6];
    char blynk_token_[34];

    //default custom static IP
    char static_ip_[16];
    char static_gw_[16];
    char static_sn_[16];

    bool save_config_;
};

#endif // #ifndef WATCHWINDER_H
