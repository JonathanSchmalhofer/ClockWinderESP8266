//
//  Timesettings.h - Class description for saving time settings.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef TIMESETTINGS_H
#define TIMESETTINGS_H

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define SETTINGS_EEPROM_ADRESS_TIMEZONESHIFT 1024

#define SETTINGS_EEPROM_ADRESS_CHECKNUM 2001
#define SETTINGS_CHECKNUM 16

class Timesettings
{
public:
    Timesettings();
    void Load();
    void Reset();
    void Save();
    void Info();
    size_t GetSize();
	String GetTimesettingsJSON();
	void WriteIntegerToEEPROM(int adress, int value);
	int ReadIntegerFromEEPROM(int adress);
	
	int GetTimezoneshift();
	void SetTimezoneshift(int timezoneshift);
private:	
    int timezoneshift_;
    bool timesettings_loaded_;    
};

#endif
