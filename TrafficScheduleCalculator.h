#pragma once

#include <map>
#include <string>

class Street;
class Intersection;

class TrafficScheduleCalculator
{
public:
	virtual void Calculate(std::map<uint32_t, Intersection>& intersections, std::map<std::string, Street>& street_map, uint32_t max_time_seconds) = 0;
};