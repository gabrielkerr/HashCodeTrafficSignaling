#pragma once

#include <vector>
#include <string>

class Street;

class Car {
private:
	std::vector<std::string> m_journey_path;
	uint32_t m_current_street_travel_time_seconds;
	uint32_t m_current_journey_index;
	bool m_is_at_end_of_street;

public:
	Car();

	std::vector<std::string> GetJourneyPath();

	void SetJourneyPath(std::vector<std::string> journey_path);

	inline void SetCurrentTravelTime(uint32_t travel_time) { m_current_street_travel_time_seconds = travel_time; }
	inline uint32_t GetCurrentTravelTime() { return m_current_street_travel_time_seconds; }

	std::string Drive(const Street& street);

	bool DidCompleteJourney();

	bool IsAtEndOfStreet(const Street& street);
};
