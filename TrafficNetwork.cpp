#include <string>
#include <vector>
#include <iostream>

#include "Car.h"
#include "Street.h"
#include "TrafficNetwork.h"
#include "Intersection.h"
#include "TrafficLight.h"

#include "Common.h"

TrafficNetwork::TrafficNetwork()
	:m_world_time_limit(1)
	,m_car_arrival_bonus(0)
	,m_point_total(0)
{
}

void TrafficNetwork::BuildTrafficNetwork(const char* file_path)
{
	std::cout << "Building traffic network from file " << file_path << "..." << std::endl;
	std::vector<std::string> lines = Common::ReadFile(file_path);
	uint32_t D, I, S, V, F, B, E, L, P;
	uint32_t line_idx = 0;
	while (line_idx < lines.size())
	{
		std::string line = lines[line_idx];

		// First line contains five numbers, D, I, S, V, F
		// D: Duration of the simulation in seconds
		// I: Number of intersections, with IDs from 0 to I-1
		// S: Number of streets
		// V: Number of cars
		// F: Bonus points for each car that reaches its destination before time D
		if (line_idx == 0)
		{
			std::vector<std::string> setup_var_tokens = Common::Split(line, ' ');
			// TODO Remove magic variable
			if (setup_var_tokens.size() != 5)
			{
				std::cout << "Unable to build traffic network! Expected 5 setup tokens but found " << setup_var_tokens.size() << std::endl;
				std::cout << "Setup tokens: " << line << std::endl;
				return;
			}

			D = stoi(setup_var_tokens[0]);
			I = stoi(setup_var_tokens[1]);
			S = stoi(setup_var_tokens[2]);
			V = stoi(setup_var_tokens[3]);
			F = stoi(setup_var_tokens[4]);

			std::cout << "Simulation Duration:\t\t" << D << " seconds" << std::endl;
			m_world_time_limit = D;
			std::cout << "Number of Intersections:\t" << I << std::endl;
			std::cout << "Number of Streets:\t\t" << S << std::endl;
			std::cout << "Number of Cars:\t\t\t" << V << std::endl;
			std::cout << "Bonus Points for Each Car:\t" << F <<  std::endl;
			m_car_arrival_bonus = F;
		}
		// The next S lines contain descriptions of streets.
		// Two integers B and E, intersection IDs at the start and end of the streets respectively
		// Street name
		// Integer L, time it takes to get from the beginning to the end of that street
		else if (line_idx <= S)
		{
			std::cout << "Processing street..." << std::endl;
			std::cout << line << std::endl;
			std::vector<std::string> street_info_tokens = Common::Split(line, ' ');
			B = atoi(street_info_tokens[0].c_str());
			E = atoi(street_info_tokens[1].c_str());
			std::string street_name = street_info_tokens[2];
			L = atoi(street_info_tokens[3].c_str());
			Street street(B, E, L);

			// TODO Add street to the network, make some sort of graph?
			m_streets.push_back(street);
		}
		// The next V lines describe the paths of each car
		// Integer P, number of streets the car wants to travel
		// Followed by P names of the streets
		else if (line_idx <= (S + V))
		{
			std::cout << "Processing car path..." << std::endl;
			std::vector<std::string> car_path;
			std::vector<std::string> car_path_tokens = Common::Split(line, ' ');
			P = atoi(car_path_tokens[0].c_str());
			for (size_t path_token_idx(1); path_token_idx <= P; ++path_token_idx)
			{
				car_path.push_back(car_path_tokens[path_token_idx]);
			}
			Car car;
			car.SetJourneyPath(car_path);
			m_cars.push_back(car);
		}

		// Do work above this line
		line_idx++;
	}
	std::cout << "Number of streets added to network: " << m_streets.size() << std::endl;
}
