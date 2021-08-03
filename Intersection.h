#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

#include "TrafficLight.h"

class Intersection
{
private:
	std::map<std::string, TrafficLight> m_traffic_light_map;
	std::set<std::string> m_in_street_names;

public:
	Intersection();

	// Adds street with traffic light to the intersection.
	void AddInStreet(std::string& street_name);

	int GetTrafficLightCount();

	bool IsLightGreenAtStreet(const std::string& street_name);

	void ToggleLightAtStreet(const std::string& street_name);

	// TODO Advance time on all traffic lights, toggling where appropriate.
	// void Update();
};
