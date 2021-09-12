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

TrafficLight* Intersection::GetTrafficLightAtStreet(const std::string& street_name)
{
	if (m_traffic_light_map.find(street_name) != m_traffic_light_map.end())
	{
		return &(m_traffic_light_map[street_name]);
	}

	return nullptr;
}

bool Intersection::IsLightGreenAtStreet(const std::string& street_name)
{
	return m_traffic_light_map[street_name].IsGreen();
}

// TODO NOTE Maybe the intersection shouldn't toggle the light, but
// the light should govern itself
void Intersection::ToggleLightAtStreet(const std::string& street_name)
{
	m_traffic_light_map[street_name].Toggle();
}

// TODO This should make sure only one light is green at a time in the intersection.
void Intersection::Update()
{
	for (auto iter = m_traffic_light_map.begin(); iter != m_traffic_light_map.end(); ++iter)
	{
		iter->second.Update();
	}
}
