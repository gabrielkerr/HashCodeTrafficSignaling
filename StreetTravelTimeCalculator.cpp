#include "Car.h"
#include "Street.h"
#include "Intersection.h"
#include "StreetTravelTimeCalculator.h"

#include <iostream>

/*
* Takes traffic network intersection map and updates all the traffic lights.
*/
void StreetTravelTimeCalculator::Calculate(std::map<uint32_t, Intersection>& intersections, std::map<std::string, Street>& street_map, const uint32_t max_time_seconds)
{
	std::cout << "Calculating!" << std::endl;
	for (auto intersection_iter = intersections.begin(); intersection_iter != intersections.end(); ++intersection_iter)
	{
		Intersection& intersection = intersection_iter->second;
		uint32_t traffic_light_count = intersection.GetInStreetNames().size();
		// If there is only one in street, set the light to evergreen.
		if (traffic_light_count == 1)
		{
			std::string in_street_name = *(intersection.GetInStreetNames().begin());
			TrafficLight* p_traffic_light = intersection.GetTrafficLightAtStreet(in_street_name);
			if (p_traffic_light)
			{
				p_traffic_light->SetGreenLightDuration(max_time_seconds);
				p_traffic_light->SetIsEvergreen(true);
			}
		}
		else
		{
			// For each intersection, set the traffic light time equal to the incoming road travel time 
			// Otherwise, set it to the max simulation time. 
			for (auto street_name : intersection.GetInStreetNames())
			{
				TrafficLight* p_traffic_light = intersection.GetTrafficLightAtStreet(street_name);
				uint32_t traffic_light_time = max_time_seconds;
				if (street_map.find(street_name) != street_map.end())
				{
					traffic_light_time = street_map[street_name].GetTravelTimeSeconds();
				}

				if (p_traffic_light)
				{
					p_traffic_light->SetGreenLightDuration(traffic_light_time);
				}
			}
		}
	}
}
