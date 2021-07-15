#pragma once

#include <deque>

class Car;

class Street {
private:
	std::deque<Car> m_car_queue;
	uint32_t m_travel_time_seconds;
	uint32_t m_start_intersection_id;
	uint32_t m_end_intersection_id;


public:
	Street(uint32_t start_intersection_id, 
		   uint32_t end_intersection_id, 
		   uint32_t travel_time_seconds);
	void AddCar(Car car);
	std::deque<Car> GetCarQueue();
	Car GetFrontCar();
	uint32_t GetTravelTimeSeconds();
	uint32_t GetStartIntersectionID();
	uint32_t GetEndIntersectionID();
};
