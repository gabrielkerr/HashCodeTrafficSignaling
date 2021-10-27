#pragma once

#include "TrafficScheduleCalculator.h" 

/*
* This calculator sets each traffic light to a schedule of 1 second of green time before
* cycling to the next light in the intersection.
*/
class BasicTrafficScheduleCalculator : public TrafficScheduleCalculator 
{
public:
	void Calculate(std::map<uint32_t, Intersection>& intersections, std::map<std::string, Street*>& street_map, uint32_t max_time_seconds);
};
