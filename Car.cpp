#include "Car.h"
#include "Street.h"

Car::Car()
:m_current_street_travel_time_seconds(0)
,m_current_journey_index(0)
,m_is_at_end_of_street(false)
{
}

std::vector<std::string> Car::GetJourneyPath()
{
	return m_journey_path;
}

void Car::SetJourneyPath(std::vector<std::string> journey_path)
{
	for (auto path_item : journey_path)
	{
		m_journey_path.push_back(path_item);
	}
}

std::string Car::Drive(const Street& street)
{
	m_current_street_travel_time_seconds++;
	// Update journey index.
	if (m_current_street_travel_time_seconds > street.GetTravelTimeSeconds())
	{
		if (m_current_journey_index < m_journey_path.size() - 1)
		{
			m_current_journey_index++;
		}
	}

	return m_journey_path[m_current_journey_index];
}

bool Car::DidCompleteJourney()
{
	return (m_current_journey_index >= m_journey_path.size() - 1) && (m_is_at_end_of_street);
}

bool Car::IsAtEndOfStreet(const Street& street)
{
	m_is_at_end_of_street = (m_current_street_travel_time_seconds >= street.GetTravelTimeSeconds());
	return m_is_at_end_of_street;
}
