#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

#include "TrafficLight.h"

class Intersection
{
private:
	// Map of all street names flowing IN to the intersection and their respective traffic light.
	std::map<std::string, TrafficLight> m_traffic_light_map;

	// Set of all the street names that flow IN to this intersection.
	std::set<std::string> m_in_street_names;

	// Traffic light schedule goes in order from 0th street in the vector to last street in the vector. 
	std::vector<std::string> m_street_priority_vector;

	// Index of current active light
	size_t m_current_active_light_idx;

public:
	Intersection();

	// Adds street with traffic light to the intersection.
	void AddInStreet(std::string& street_name);

	int GetTrafficLightCount();

	TrafficLight* GetTrafficLightAtStreet(const std::string& street_name);

	bool IsLightGreenAtStreet(const std::string& street_name);

	void ToggleLightAtStreet(const std::string& street_name);
	
	void AddLightToSchedule(const std::string& street_name);

	inline std::set<std::string> GetInStreetNames() { return m_in_street_names; }

	// Advance time on all traffic lights, toggling where appropriate.
	void Update();
};
