#pragma once
#include <vector>
#include "TrafficLight.h"

class Intersection
{
private:
	std::vector<TrafficLight> m_traffic_lights;

public:
	Intersection();

	Intersection(std::vector<TrafficLight> traffic_lights);

	void AddTrafficLight(TrafficLight traffic_light);

	int GetTrafficLightCount();
};
