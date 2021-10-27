#include "Car.h"
#include "Street.h"
#include "Intersection.h"
#include "BasicTrafficScheduleCalculator.h"

#include <iostream>

void BasicTrafficScheduleCalculator::Calculate(std::map<uint32_t, Intersection>& intersections, std::map<std::string, Street*>& street_map, uint32_t max_time_seconds)
{
	std::cout << "Calculating!" << std::endl;
	for (auto intersection_iter = intersections.begin(); intersection_iter != intersections.end(); ++intersection_iter)
	{
		Intersection& intersection = intersection_iter->second;
		for (auto street_name : intersection.GetInStreetNames())
		{
			TrafficLight* p_traffic_light = intersection.GetTrafficLightAtStreet(street_name);
			if (p_traffic_light)
			{
				p_traffic_light->SetGreenLightDuration(1);
			}
		}
	}
}
