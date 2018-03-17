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

#define SETTINGS_EEPROM_ADRESS_TIMEZONESHIFT   1024    // type int - +1 byte for next address enough
#define SETTINGS_EEPROM_ADRESS_EARLIESTALLOWED 1025 // type int - +1 byte for next address enough
#define SETTINGS_EEPROM_ADRESS_LATESTALLOWED   1026 // type int - +1 byte for next address enough

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
    int GetEarliestallowed();
    int GetLatestallowed();
    void SetTimezoneshift(int timezoneshift);
    void SetEarliestallowed(int earliestallowed);
    void SetLatestallowed(int latestallowed);
private:    
    int timezoneshift_;
    int earliestallowed_;
    int latestallowed_;
    bool timesettings_loaded_;    
};

#endif
