#include "TrafficLight.h"

TrafficLight::TrafficLight(int duration)
{
    m_green_light_duration = duration;
}

int TrafficLight::GetGreenLightDuration()
{
    return m_green_light_duration;
}
