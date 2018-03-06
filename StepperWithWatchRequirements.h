//
//  StepperWithWatchRequirements.h - Library for StepperWithWatchRequirements for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef STEPPERWITHWATCHREQUIREMENTS_H
#define STEPPERWITHWATCHREQUIREMENTS_H

#include "A4988.h"
#include "WatchRequirement.h"

typedef std::pair<WatchRequirement, bool> WatchRequirementTurningLikeStepper;

class StepperWithWatchRequirements
{
public:
    StepperWithWatchRequirements(short steps_per_revolution, short direction_pin_number, short step_pin_number);
	
	std::vector<WatchRequirementTurningLikeStepper>& GetAllRequirements();
	A4988 GetStepper();
	short GetRPM();
	void SetRPM(short rpm);
	void Rotate(double degree);
	void RemoveRequirementAtIndex(int index);
	
private:
	std::vector<WatchRequirementTurningLikeStepper> requirements_;
	A4988 stepper_;
};

#endif // #ifndef STEPPERWITHWATCHREQUIREMENTS_H
