//
//  WatchMovementSupplier.cpp - Library for WatchMovementSupplier for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "WatchMovementSupplier.h"

WatchMovementSupplier::WatchMovementSupplier()
{
}

std::vector<StepperWithWatchRequirements>& WatchMovementSupplier::GetAllSteppers()
{
	return steppers_;
}

void WatchMovementSupplier::AddStepper(StepperWithWatchRequirements stepper)
{
	steppers_.push_back(stepper);
}
