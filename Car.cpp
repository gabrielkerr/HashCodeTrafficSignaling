#include "Car.h"

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
