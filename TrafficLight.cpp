#include "TrafficLight.h"

TrafficLight::TrafficLight()
:m_green_light_duration(1)
,m_is_green(true)
,m_time_in_current_state(0)
{

}

TrafficLight::TrafficLight(int duration)
:m_is_green(true)
,m_time_in_current_state(0)
{
    m_green_light_duration = duration;
}

int TrafficLight::GetGreenLightDuration()
{
    return m_green_light_duration;
}

bool TrafficLight::IsGreen()
{
    return m_is_green;
}

void TrafficLight::Toggle()
{
    m_is_green = !m_is_green;
}

void TrafficLight::Update()
{
    m_time_in_current_state++;
    if (m_time_in_current_state >= m_green_light_duration)
    {
        Toggle();
        m_time_in_current_state = 0;
    }
}
