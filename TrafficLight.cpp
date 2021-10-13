#include "TrafficLight.h"

TrafficLight::TrafficLight()
:m_green_light_duration(0)
,m_is_green(false)
,m_time_in_current_state(0)
,m_is_evergreen(false)
{

}

TrafficLight::TrafficLight(int duration)
:m_is_green(false)
,m_time_in_current_state(0)
,m_is_evergreen(false)
{
    m_green_light_duration = duration;
}

int TrafficLight::GetGreenLightDuration()
{
    return m_green_light_duration;
}

void TrafficLight::SetGreenLightDuration(int green_light_duration)
{
    m_green_light_duration = green_light_duration;
}

void TrafficLight::SetGreen(bool is_green)
{
    m_is_green = is_green;
}


void TrafficLight::SetIsEvergreen(bool is_evergreen)
{
    m_is_evergreen = is_evergreen;
}

bool TrafficLight::IsGreen()
{
    return m_is_evergreen || m_is_green;
}

void TrafficLight::Toggle()
{
    m_is_green = !m_is_green;
}

void TrafficLight::Update()
{
    m_time_in_current_state++;
    if ((m_time_in_current_state >= m_green_light_duration) && (m_green_light_duration > 0))
    {
        Toggle();
        m_time_in_current_state = 0;
    }
}
