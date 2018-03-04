//
//  WatchMovementSupplier.h - Library for WatchMovementSupplier for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHMOVEMENTSUPPLIER_H
#define WATCHMOVEMENTSUPPLIER_H

#include "A4988.h"
#include "WatchRequirement.h"

typedef std::pair<std::vector<WatchRequirement>, A4988> StepperWithRequirements;

class WatchMovementSupplier
{
public:
    WatchMovementSupplier();
	
	std::vector<StepperWithRequirements> GetAllSteppers();
	
private:
	std::vector<StepperWithRequirements> steppers_;
};

#endif // #ifndef WATCHMOVEMENTSUPPLIER_H
