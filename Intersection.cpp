#include "Intersection.h"
#include "TrafficLight.h"

Intersection::Intersection()
{
}

Intersection::Intersection(std::vector<TrafficLight> traffic_lights)
{
	m_traffic_lights = traffic_lights;
}

void Intersection::AddTrafficLight(TrafficLight traffic_light)
{
	m_traffic_lights.push_back(traffic_light);
}

int Intersection::GetTrafficLightCount()
{
	return m_traffic_lights.size();
}
