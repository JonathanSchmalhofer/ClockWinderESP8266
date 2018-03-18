//
//  WatchRequirement.cpp - Library for WatchRequirements for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//

#include "WatchRequirement.h"

WatchRequirement::WatchRequirement(String name, TurningDirection turning_direction, int revolutions_per_day)
{
    name_ = name;
    turning_direction_ = turning_direction;
    revolutions_per_day_ = revolutions_per_day;
}

TurningDirection WatchRequirement::GetTurningDirection()
{
    return turning_direction_;
}

void WatchRequirement::SetTurningDirection(TurningDirection turning_direction)
{
    turning_direction_ = turning_direction;
}

int WatchRequirement::GetRevolutionsPerDay()
{
    return revolutions_per_day_;
}

void WatchRequirement::SetRevolutionsPerDay(int revolutions_per_day)
{
    revolutions_per_day_ = revolutions_per_day;
}

String WatchRequirement::GetName()
{
    return name_;
}

void WatchRequirement::SetName(String name)
{
    name_ = name;
}
