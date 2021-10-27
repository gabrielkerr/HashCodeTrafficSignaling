#pragma once

#include <vector>
#include <string>
#include <map>

class TrafficScheduleCalculator;
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
	uint32_t m_point_total;
	std::map<std::string, Street*> m_street_map;
	//bool m_is_network_empty;

	void UpdateIntersections();

public:
	TrafficNetwork();
	~TrafficNetwork();
	void BuildTrafficNetwork(const char* file_path);
	void SetTrafficLights(TrafficScheduleCalculator* calculator);
	void SetTrafficLights(const char* solution_file_path);
	void Step();
	uint32_t GetTimeLimit();
	uint32_t GetTimeLeft();
	std::map<std::string, Street*> GetStreetState();
	int GetPoints();
	void PrintSchedule();
    Intersection* GetIntersectionById(uint32_t intersection_id);
	// TODO
	//void SaveScheduleToFile(const char* file_path);
};
