//
//  WatchRequirement.h - Library for WatchRequirements for a WatchWinder.
//  Created by Jonathan Bryan Schmalhofer, March 4th 2018
//  License: MIT
//
#ifndef WATCHREQUIREMENT_H
#define WATCHREQUIREMENT_H

enum TurningDirection
{
	CLOCKWISEONLY = 0,
	COUNTERCLOCKWISEONLY,
	BOTHDIRECTIONS
};

class WatchRequirement
{
public:
    WatchRequirement(TurningDirection turning_direction, int revolutions_per_day);
	
	TurningDirection GetTurningDirection();
	void SetTurningDirection(TurningDirection turning_direction);
	
	int GetRevolutionsPerDay();
	void SetRevolutionsPerDay(int revolutions_per_day);

private:
	int revolutions_per_day_;
	TurningDirection turning_direction_;
	
};

#endif // #ifndef WATCHREQUIREMENT_H
