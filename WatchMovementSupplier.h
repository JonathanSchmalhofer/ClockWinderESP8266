//
//  WatchMovementSupplier.h - Library for WatchMovementSupplier for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHMOVEMENTSUPPLIER_H
#define WATCHMOVEMENTSUPPLIER_H

#include "StepperWithWatchRequirements.h"

class WatchMovementSupplier
{
public:
    WatchMovementSupplier();
	
	std::vector<StepperWithWatchRequirements>& GetAllSteppers();
	void AddStepper(StepperWithWatchRequirements stepper);
	
private:
	std::vector<StepperWithWatchRequirements> steppers_;
};

#endif // #ifndef WATCHMOVEMENTSUPPLIER_H
