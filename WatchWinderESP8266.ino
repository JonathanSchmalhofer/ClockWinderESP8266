#include "WatchWinder.h"

WatchWinder watch_winder;

// using a 200-step motor (most common)
#define MOTOR_STEPS 200
// configure the pins connected
#define DIR 8
#define STEP 9
#define MS1 10
#define MS2 11
#define MS3 12
A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);

void setup()
{
	// put your setup code here, to run once:
	watch_winder.Setup();
}

void loop()
{
	// put your main code here, to run repeatedly:
	watch_winder.Step();
}
