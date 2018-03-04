//
//  WatchMovementSupplier.cpp - Library for WatchMovementSupplier for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "WatchMovementSupplier.h"

WatchMovementSupplier::WatchMovementSupplier()
{
}

std::vector<StepperWithRequirements> WatchMovementSupplier::GetAllSteppers()
{
	return steppers_;
}
