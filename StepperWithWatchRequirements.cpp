//
//  StepperWithWatchRequirements.cpp - Library for WatchMovementSupplier for a StepperWithWatchRequirements.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "StepperWithWatchRequirements.h"

StepperWithWatchRequirements::StepperWithWatchRequirements(short steps_per_revolution, short direction_pin_number, short step_pin_number)
    : stepper_(steps_per_revolution, direction_pin_number, step_pin_number)
{
	const short kfull_step = 1;
	const short krpm = 1;
	stepper_.begin(krpm, kfull_step);
}

std::vector<WatchRequirementTurningLikeStepper>& StepperWithWatchRequirements::GetAllRequirements()
{
	return requirements_;
}

A4988 StepperWithWatchRequirements::GetStepper()
{
	return stepper_;
}

short StepperWithWatchRequirements::GetRPM()
{
	return stepper_.getRPM();
}

void StepperWithWatchRequirements::SetRPM(short rpm)
{
	stepper_.setRPM(rpm);
}

void StepperWithWatchRequirements::Rotate(double degree)
{
	stepper_.rotate(degree);
}

void StepperWithWatchRequirements::RemoveRequirementAtIndex(int index)
{
	requirements_.erase( requirements_.begin() + index );
}
