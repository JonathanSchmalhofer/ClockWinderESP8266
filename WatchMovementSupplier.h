//
//  WatchMovementSupplier.h - Library for WatchMovementSupplier for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHMOVEMENTSUPPLIER_H
#define WATCHMOVEMENTSUPPLIER_H

#include "A4988.h"
#include "WatchRequirement.h"

typedef std::pair<WatchRequirement, bool> WatchRequirementTurningLikeStepper;

class WatchMovementSupplier
{
public:
    WatchMovementSupplier();
	
	std::vector<WatchRequirementTurningLikeStepper>& GetAllRequirements();
	void SetStepper(A4988 stepper);
	A4988& GetStepper();
	short GetRPM();
	void SetRPM(short rpm);
	void Rotate(double degree);
	void RemoveRequirementAtIndex(int index);
	
private:
	std::vector<WatchRequirementTurningLikeStepper> requirements_;
	A4988 stepper_;
};

#endif // #ifndef WATCHMOVEMENTSUPPLIER_H
