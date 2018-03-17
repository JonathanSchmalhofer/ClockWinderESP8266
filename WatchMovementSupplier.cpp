//
//  WatchMovementSupplier.cpp - Library for WatchMovementSupplier for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "WatchMovementSupplier.h"

WatchMovementSupplier::WatchMovementSupplier()
    : stepper_(0, 0, 0)
{
    const short kfull_step = 1;
    const short krpm = 1;
    stepper_.begin(krpm, kfull_step);
}

A4988& WatchMovementSupplier::GetStepper()
{
    return stepper_;
}

void WatchMovementSupplier::SetStepper(A4988 stepper)
{
    stepper_ = stepper;
}

std::vector<WatchRequirementTurningLikeStepper>& WatchMovementSupplier::GetAllRequirements()
{
    return requirements_;
}

short WatchMovementSupplier::GetRPM()
{
    return stepper_.getRPM();
}

void WatchMovementSupplier::SetRPM(short rpm)
{
    stepper_.setRPM(rpm);
}

void WatchMovementSupplier::Rotate(double degree)
{
    stepper_.rotate(degree);
}

void WatchMovementSupplier::RemoveRequirementAtIndex(int index)
{
    requirements_.erase( requirements_.begin() + index );
}
