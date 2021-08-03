#include "Car.h"
#include "Street.h"


Street::Street()
:m_start_intersection_id(0)
,m_end_intersection_id(0)
,m_travel_time_seconds(0)
,m_name("")
{
}

Street::Street(uint32_t start_intersection_id, 
	           uint32_t end_intersection_id, 
	           uint32_t travel_time_seconds,
	           std::string name)
:m_start_intersection_id(start_intersection_id)
,m_end_intersection_id(end_intersection_id)
,m_travel_time_seconds(travel_time_seconds)
,m_name(name)
{
}

void Street::AddCar(Car car)
{
	m_temporary_car_queue.push_back(car);
}

std::deque<Car> Street::GetCarQueue()
{
	return m_car_queue;
}

bool Street::IsEmpty()
{
	return m_car_queue.empty();
}

Car* Street::GetFrontCar()
{
	Car* p_front_car = nullptr; 
	if (!m_car_queue.empty())
	{
		p_front_car = &(m_car_queue.front());
	}
	return p_front_car;
}

void Street::RemoveFrontCar()
{
	m_car_queue.pop_front();
}

uint32_t Street::GetTravelTimeSeconds()
{
	return m_travel_time_seconds;
}

uint32_t Street::GetStartIntersectionID()
{
	return m_start_intersection_id;
}

uint32_t Street::GetEndIntersectionID()
{
	return m_end_intersection_id;
}

void Street::Update()
{
	for (auto car : m_temporary_car_queue)
	{
		m_car_queue.push_back(car);
	}
	m_temporary_car_queue.clear();
}
