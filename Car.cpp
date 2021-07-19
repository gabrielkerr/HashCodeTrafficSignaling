#include "Car.h"

Car::Car()
:m_current_street_travel_time_seconds(0)
,m_current_journey_index(0)
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

// TODO This should just increment the travel time.
std::string Car::Drive()
{
	// Update journey index.
	if (m_current_journey_index + 1 < m_journey_path.size())
	{
		m_current_journey_index++;
	}

	return m_journey_path[m_current_journey_index];
}

// TODO Create function to move to next street.
