//
//  WatchRequirement.h - Library for WatchRequirements for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHREQUIREMENT_H
#define WATCHREQUIREMENT_H

#include <Arduino.h>

enum TurningDirection
{
    CLOCKWISEONLY = 0,
    COUNTERCLOCKWISEONLY,
    BOTHDIRECTIONS
};

class WatchRequirement
{
public:
    WatchRequirement(String name, TurningDirection turning_direction, int revolutions_per_day);
    
    TurningDirection GetTurningDirection();
    void SetTurningDirection(TurningDirection turning_direction);
    
    int GetRevolutionsPerDay();
    void SetRevolutionsPerDay(int revolutions_per_day);
    
    String GetName();
    void SetName(String name);

private:
    String name_;
    int revolutions_per_day_;
    TurningDirection turning_direction_;
    
};

#endif // #ifndef WATCHREQUIREMENT_H
