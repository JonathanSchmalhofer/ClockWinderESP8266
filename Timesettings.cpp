#include "Timesettings.h"

Timesettings::Timesettings()
{
    CheckValidValues();
    timesettings_loaded_ = false;
}

//source: http://shelvin.de/eine-integer-zahl-in-das-arduiono-eeprom-schreiben/
void Timesettings::WriteIntegerToEEPROM(int adress, int value)
{
    byte low, high;
    low = value & 0xFF;
    high = (value >> 8) & 0xFF;
    EEPROM.write(adress, low);
    EEPROM.write(adress + 1, high);
    return;
}

int Timesettings::ReadIntegerFromEEPROM(int adress)
{
    byte low, high;
    low = EEPROM.read(adress);
    high = EEPROM.read(adress + 1);
    return low + ((high << 8) & 0xFF00);
}

void Timesettings::Load() {

    if (EEPROM.read(SETTINGS_EEPROM_ADRESS_CHECKNUM) != SETTINGS_CHECKNUM)
    {
        Reset();
        return;
    }

    timezoneshift_   = ReadIntegerFromEEPROM(SETTINGS_EEPROM_ADRESS_TIMEZONESHIFT);
    earliestallowed_ = ReadIntegerFromEEPROM(SETTINGS_EEPROM_ADRESS_EARLIESTALLOWED);
    latestallowed_   = ReadIntegerFromEEPROM(SETTINGS_EEPROM_ADRESS_LATESTALLOWED);
    CheckValidValues();
    timesettings_loaded_ = true;
}

void Timesettings::Reset()
{
    Serial.print("reset timesettings...");

    timezoneshift_   =  1; // Default shall be central european time, which is GMT+1
    earliestallowed_ = 10; // Default shall be 10:00 o'clock
    latestallowed_   = 20; // Default shall be 20:00 o'clock

    Serial.println("done");

    Save();
}

void Timesettings::Save()
{  
    CheckValidValues();
    WriteIntegerToEEPROM(SETTINGS_EEPROM_ADRESS_TIMEZONESHIFT,   timezoneshift_);
    WriteIntegerToEEPROM(SETTINGS_EEPROM_ADRESS_EARLIESTALLOWED, earliestallowed_);
    WriteIntegerToEEPROM(SETTINGS_EEPROM_ADRESS_LATESTALLOWED,   latestallowed_);
    EEPROM.write(SETTINGS_EEPROM_ADRESS_CHECKNUM, SETTINGS_CHECKNUM);
  
    Info();
    Serial.println("settings saved");
}

void Timesettings::Info()
{
    Serial.println("Settings:");
    Serial.println("Timezone shift: " + (String)timezoneshift_);
    Serial.println("Earliest Start: " + (String)earliestallowed_);
    Serial.println("Latest Start:   " + (String)latestallowed_);
}

String Timesettings::GetTimesettingsJSON()
{
    CheckValidValues();
    String json = "{";
    json += "\"timezoneshift\":"   + (String)(int)timezoneshift_   + ",";
    json += "\"earliestallowed\":" + (String)(int)earliestallowed_ + ",";
    json += "\"latestallowed\":"   + (String)(int)latestallowed_   + "}";
    
    return json;
}

size_t Timesettings::GetSize()
{
    String json = GetTimesettingsJSON();
    size_t json_size = json.length();
    return json_size;
}

void Timesettings::CheckValidValues()
{
    if (timezoneshift_ < 0)
    {
        timezoneshift_ = 0;
    }
    if (timezoneshift_ > 24)
    {
        timezoneshift_ = 24;
    }
    if (earliestallowed_ < 0)
    {
        earliestallowed_ = 0;
    }
    if (earliestallowed_ > 24)
    {
        earliestallowed_ = 24;
    }
    if (latestallowed_ < 0)
    {
        latestallowed_ = 0;
    }
    if (latestallowed_ > 24)
    {
        latestallowed_ = 24;
    }
    if (earliestallowed_ > latestallowed_)
    {
        latestallowed_ = earliestallowed_;
    }
}

int Timesettings::GetTimezoneshift()
{
    return timezoneshift_;
}

int Timesettings::GetEarliestallowed()
{
    return earliestallowed_;
}

int Timesettings::GetLatestallowed()
{
    return latestallowed_;
}

void Timesettings::SetTimezoneshift(int timezoneshift)
{
    timezoneshift_ = timezoneshift;
}

void Timesettings::SetEarliestallowed(int earliestallowed)
{
    earliestallowed_ = earliestallowed;
}

void Timesettings::SetLatestallowed(int latestallowed)
{
    latestallowed_ = latestallowed;
}
