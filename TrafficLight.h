#pragma once

#include <string>
#include <vector>

class TrafficLight
{
private:
	int m_green_light_duration;
	std::vector<std::string> m_in_streets_names;
	bool m_is_green;

public:
	TrafficLight();
	TrafficLight(int duration);
	int GetGreenLightDuration();
	bool IsGreen();
	void Toggle();
	// TODO Advance time step on traffic light and toggle if needed.
	//void Update();
};
