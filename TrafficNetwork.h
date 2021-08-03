#pragma once

#include <vector>
#include <string>
#include <map>

class Intersection;
class Streets;

class TrafficNetwork
{
private:
	uint32_t m_world_time_limit;
	uint32_t m_time_left;
	uint32_t m_car_arrival_bonus;
	std::map<uint32_t, Intersection> m_intersections;
	std::vector<Street> m_streets;
	std::vector<Car> m_cars;
	uint32_t m_point_total;
	std::map<std::string, Street> m_street_map;
	bool m_is_network_empty;

public:
	TrafficNetwork();
	void BuildTrafficNetwork(const char* file_path);
	void Step();
	uint32_t GetTimeLimit();
	uint32_t GetTimeLeft();
	std::map<std::string, Street> GetStreetState();
};
