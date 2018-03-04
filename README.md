# WatchWinderESP8266
An ESP8266-based watch winder with browser accessible GUI for configuration.

# Requirements

The following are required in order to build this project (in case any are missing, any help in completing the list is highly appreciated):

* arduino >= 1.8.5 (see [www.arduino.cc](http://www.arduino.cc))
* esp8266 >= 2.4.0 (see [sparkfun/esp8266](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon))
* WiFiManager >= 0.12.0 (see [tzapu/WiFiManager](https://github.com/tzapu/WiFiManager))
* ArduinoJson >= 5.13.0 (see [bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson))

# Checkout with externals

Some external github dependencies are being used within this project. Please check them out properly as well.

To checkout this repository the first time, use the commands:

```{.sh}
git clone https://github.com/JonathanSchmalhofer/WatchWinderESP8266.git
git submodule update --init --recursive
```