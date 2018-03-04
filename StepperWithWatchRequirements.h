//
//  StepperWithWatchRequirements.h - Library for StepperWithWatchRequirements for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef STEPPERWITHWATCHREQUIREMENTS_H
#define STEPPERWITHWATCHREQUIREMENTS_H

#include "A4988.h"
#include "WatchRequirement.h"

class StepperWithWatchRequirements
{
public:
    StepperWithWatchRequirements();
	
	std::vector<WatchRequirement> GetAllRequirements();
	
private:
	std::vector<WatchRequirement> requirements_;
};

#endif // #ifndef STEPPERWITHWATCHREQUIREMENTS_H
