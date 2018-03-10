#include "WatchWinder.h"

WatchWinder watch_winder;

void setup()
{
  Serial.begin(9600);
	// put your setup code here, to run once:
	watch_winder.Setup();
}

void loop()
{
	// put your main code here, to run repeatedly:
	watch_winder.Step();
}
