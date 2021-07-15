#pragma once

class TrafficLight
{
private:
	int m_green_light_duration;

public:
	TrafficLight(int duration);
	int GetGreenLightDuration();
};
