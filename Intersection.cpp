#include "Intersection.h"
#include "TrafficLight.h"

Intersection::Intersection()
	:m_current_active_light_idx(0)
{
}

void Intersection::AddInStreet(std::string& street_name)
{
	m_in_street_names.insert(street_name);
	TrafficLight traffic_light;
	// Add entry to the street_name -> traffic_light map.
	m_traffic_light_map[street_name] = traffic_light;
}

int Intersection::GetTrafficLightCount() const
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

void Intersection::ToggleLightAtStreet(const std::string& street_name)
{
	m_traffic_light_map[street_name].Toggle();
}

void Intersection::AddLightToSchedule(const std::string& street_name)
{
	// Set the street to the lowest priority in the street order.
	m_street_priority_vector.push_back(street_name);

	// Set light to green if it's the first one in the order.
	if (m_street_priority_vector.size() == 1)
	{
		m_traffic_light_map[street_name].SetGreen(true);
	}
	else
	{
		m_traffic_light_map[street_name].SetGreen(false);
	}
}

void Intersection::Update()
{
	// Some intersections have no schedule and all lights are red. Skip this update.
	if (m_street_priority_vector.size() < 1)
	{
		return;
	}
	// Update the current active traffic light.
	std::string current_active_street = m_street_priority_vector[m_current_active_light_idx];
	TrafficLight* p_current_active_light = &(m_traffic_light_map[current_active_street]);
	if (!p_current_active_light) 
	{
		return;
	}
	p_current_active_light->Update();

	// If the current light has turned red, get the next light in the schedule and turn it on.
	// NOTE: If there is only one light at the intersection, that light will always be green.
	if (!p_current_active_light->IsGreen())
	{
		m_current_active_light_idx++;
		if (m_current_active_light_idx >= m_street_priority_vector.size())
		{
			m_current_active_light_idx = 0;
		}
		current_active_street = m_street_priority_vector[m_current_active_light_idx];
		// This should be going from RED to GREEN.
		m_traffic_light_map[current_active_street].SetGreen(true);
	}
}
