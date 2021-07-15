#pragma once

#include <vector>
#include <string>

class Intersection;
class Streets;

class TrafficNetwork
{
private:
	uint32_t m_world_time_limit;
	uint32_t m_car_arrival_bonus;
	std::vector<Intersection> m_intersections;
	std::vector<Street> m_streets;
	std::vector<Car> m_cars;
	uint32_t m_point_total;

public:
	TrafficNetwork();
	void BuildTrafficNetwork(const char* file_path);
};
