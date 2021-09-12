#pragma once

#include <string>
#include <vector>

// TODO NOTE Consider making this a state machine?
class TrafficLight
{
private:
	int m_green_light_duration;
	std::vector<std::string> m_in_streets_names;
	bool m_is_green;
	int m_time_in_current_state;
	bool m_is_evergreen;

public:
	TrafficLight();
	TrafficLight(int duration);
	int GetGreenLightDuration();
	void SetGreenLightDuration(int green_light_duration);
	void SetIsEvergreen(bool is_evergreen);
	bool IsGreen();
	void Toggle();
	// Advance time step on traffic light and toggle if needed.
	void Update();
};
