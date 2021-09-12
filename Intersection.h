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

	TrafficLight* GetTrafficLightAtStreet(const std::string& street_name);

	bool IsLightGreenAtStreet(const std::string& street_name);

	void ToggleLightAtStreet(const std::string& street_name);

	inline std::set<std::string> GetInStreetNames() { return m_in_street_names; }

	// Advance time on all traffic lights, toggling where appropriate.
	void Update();
};
