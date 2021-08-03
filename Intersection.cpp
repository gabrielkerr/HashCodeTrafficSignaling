#include "Intersection.h"
#include "TrafficLight.h"

Intersection::Intersection()
{
}

void Intersection::AddInStreet(std::string& street_name)
{
	m_in_street_names.insert(street_name);
	TrafficLight traffic_light;
	m_traffic_light_map[street_name] = traffic_light;
}

int Intersection::GetTrafficLightCount()
{
	return m_traffic_light_map.size();
}

bool Intersection::IsLightGreenAtStreet(const std::string& street_name)
{
	return m_traffic_light_map[street_name].IsGreen();
}

void Intersection::ToggleLightAtStreet(const std::string& street_name)
{
	m_traffic_light_map[street_name].Toggle();
}
