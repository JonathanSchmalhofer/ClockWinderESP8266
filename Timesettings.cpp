#include "Timesettings.h"

Timesettings::Timesettings()
{
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

    timezoneshift_ = ReadIntegerFromEEPROM(SETTINGS_EEPROM_ADRESS_TIMEZONESHIFT);
    timesettings_loaded_ = true;
}

void Timesettings::Reset()
{
    Serial.print("reset timesettings...");

    timezoneshift_ = 1; // Default shall be central european time, which is GMT+1

    Serial.println("done");

    Save();
}

void Timesettings::Save()
{  
    WriteIntegerToEEPROM(SETTINGS_EEPROM_ADRESS_TIMEZONESHIFT, timezoneshift_);
    EEPROM.write(SETTINGS_EEPROM_ADRESS_CHECKNUM, SETTINGS_CHECKNUM);
  
    Info();
    Serial.println("settings saved");
}

void Timesettings::Info()
{
    Serial.println("Settings:");
    Serial.println("Timezone shift: " + (String)timezoneshift_);
}

String Timesettings::GetTimesettingsJSON()
{
    String json = "{";
    json += "\"timezoneshift\":" + (String)(int)timezoneshift_ + "}";
	
	return json;
}

size_t Timesettings::GetSize()
{
    String json = GetTimesettingsJSON();
    size_t json_size = json.length();
    return json_size;
}

int Timesettings::GetTimezoneshift()
{
    return timezoneshift_;
}

void Timesettings::SetTimezoneshift(int timezoneshift)
{
    timezoneshift_ = timezoneshift;
}
