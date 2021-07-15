#pragma once

#include <vector>
#include <string>

class Car {
private:
	std::vector<std::string> m_journey_path;

public:
	std::vector<std::string> GetJourneyPath();

	void SetJourneyPath(std::vector<std::string> journey_path);
};
