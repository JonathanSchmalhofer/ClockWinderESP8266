# WatchWinderESP8266
An ESP8266-based watch winder with browser accessible GUI for configuration.

STILL WORK IN PROGRESS

# Requirements

The following are required in order to build this project (in case any are missing, any help in completing the list is highly appreciated):

* arduino >= 1.8.5 (see [www.arduino.cc](http://www.arduino.cc))
* esp8266 >= 2.4.0 (see [sparkfun/esp8266](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon))
* WiFiManager >= 0.12.0 (see [tzapu/WiFiManager](https://github.com/tzapu/WiFiManager))
* ArduinoJson >= 5.13.0 (see [bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson))
* A4988 StepperDriver (is copied here from [laurb9/StepperDriver](https://github.com/laurb9/StepperDriver))

# Clone

Simply use the standard clone command

```{.sh}
git clone https://github.com/JonathanSchmalhofer/WatchWinderESP8266.git
```

# License on StepperDriver (A4988)

The following files have been copied from [laurb9/StepperDriver](https://github.com/laurb9/StepperDriver) from Laurentiu Badea:

```{.sh}
BasicStepperDriver.h
BasicStepperDriver.cpp
A4988.h
A4988.cpp
```

# License on Arduino Time Library

The following files have been copied from [stelgenhof/NTPClient](https://github.com/stelgenhof/NTPClient) from Sacha Telgenhof:

```{.sh}
NTPClient.h
NTPClient.cpp
```

# License on NTPClient

The following files have been copied from [PaulStoffregen/Time](https://github.com/PaulStoffregen/Time) from Michael Margolis/Paul Stoffregen:

```{.sh}
TimeLib.h
Time.h
Time.cpp
DateStrings.cpp
```

# License on WebServer Handling & Data Conversion

Large parts of how to handle requests to the ESP8266WebServer (e.g. SendHeader(), SendBuffer(), SendFile(), etc.) as well as how to convert files (e.g. HTML, CSS, JS) to hex werde copied from [spacehuhn/esp8266_deauther](https://github.com/spacehuhn/esp8266_deauther) from Stefan Kremser.
