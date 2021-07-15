#include "Car.h"
#include "Street.h"


Street::Street(uint32_t start_intersection_id, uint32_t end_intersection_id, uint32_t travel_time_seconds)
:m_start_intersection_id(start_intersection_id)
, m_end_intersection_id(end_intersection_id)
, m_travel_time_seconds(travel_time_seconds)
{
}

void Street::AddCar(Car car)
{
	m_car_queue.push_back(car);
}

std::deque<Car> Street::GetCarQueue()
{
	return m_car_queue;
}

Car Street::GetFrontCar()
{
	return m_car_queue.front();
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
