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

public:
	TrafficLight();
	TrafficLight(int duration);
	int GetGreenLightDuration();
	bool IsGreen();
	void Toggle();
	// Advance time step on traffic light and toggle if needed.
	void Update();
};
