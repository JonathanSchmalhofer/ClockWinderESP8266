//
//  StepperWithWatchRequirements.cpp - Library for WatchMovementSupplier for a StepperWithWatchRequirements.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "StepperWithWatchRequirements.h"

StepperWithWatchRequirements::StepperWithWatchRequirements()
{
}

std::vector<WatchRequirement> StepperWithWatchRequirements::GetAllRequirements()
{
	return requirements_;
}
