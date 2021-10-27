#pragma once

#include <deque>
#include <string>

class Car;

class Street {
private:
	std::deque<Car*> m_car_queue;
	std::deque<Car*> m_temporary_car_queue;
	uint32_t m_travel_time_seconds;
	uint32_t m_start_intersection_id;
	uint32_t m_end_intersection_id;
	std::string m_name;


public:
	Street();
	Street(uint32_t start_intersection_id,
		   uint32_t end_intersection_id,
		   uint32_t travel_time_seconds,
		   std::string name);
	~Street();
	void AddCar(Car* car);
	std::deque<Car*> GetCarQueue();
	bool IsEmpty();
	Car* GetFrontCar();
	void RemoveFrontCar();
	uint32_t GetTravelTimeSeconds() const;
	uint32_t GetStartIntersectionID();
	uint32_t GetEndIntersectionID();
	void Update();

	inline std::string GetName() { return m_name; }
};
