#pragma once

#include "TrafficScheduleCalculator.h" 

class StreetTravelTimeCalculator : public TrafficScheduleCalculator 
{
public:
	void Calculate(std::map<uint32_t, Intersection>& intersections, std::map<std::string, Street*>& street_map, uint32_t max_time_seconds);
};
