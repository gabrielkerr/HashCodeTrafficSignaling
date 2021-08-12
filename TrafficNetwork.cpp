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
	,m_time_left(0)
	,m_car_arrival_bonus(0)
	,m_point_total(0)
	,m_is_network_empty(false)
{
}

/*
* Creates a TrafficNetwork from a text file with the format described here:
* https://storage.googleapis.com/coding-competitions.appspot.com/HC/2021/hashcode_2021_online_qualification_round.pdf
*/
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
			m_time_left = m_world_time_limit;
			std::cout << "Number of Intersections:\t" << I << std::endl;
			std::cout << "Number of Streets:\t\t" << S << std::endl;
			std::cout << "Number of Cars:\t\t\t" << V << std::endl;
			std::cout << "Bonus Points for Each Car:\t" << F <<  std::endl;
			m_car_arrival_bonus = F;

			// Build intersection map
			for (uint32_t i(0); i < I; ++i)
			{
				// Add in-streets to each intersection.
				Intersection intersection;
				m_intersections[i] = intersection;
			}
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
			Street street(B, E, L, street_name);

			// Add street to the network
			m_street_map.insert(std::pair<std::string, Street>(street_name, street));

			// Update intersections with appropriate in-street
			m_intersections[street.GetEndIntersectionID()].AddInStreet(street_name);
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

			// Add cars to streets
			Street &starting_street = m_street_map[car_path[0]];
			// Drive the car right up to the intersection at the end of the street.
			car.SetCurrentTravelTime(starting_street.GetTravelTimeSeconds());
			starting_street.AddCar(car);
			starting_street.Update();

		}

		// Do work above this line
		line_idx++;
	}
	std::cout << "Number of streets added to network: " << m_streets.size() << std::endl;
}

/*
* Advances the TrafficNetwork by a single time step.
*/
void TrafficNetwork::Step()
{
	// TODO Stop simulation early if all cars have arrived

	bool did_find_cars = false;
	// For each street, get the front car and advance it one step along its
	// journey path
	auto street_iter = m_street_map.begin();
	for (street_iter = m_street_map.begin(); street_iter != m_street_map.end(); ++street_iter)
	{
		Street& street = street_iter->second;
		Car* front_car = street.GetFrontCar();

		// Get intersection at the end of this street.
		Intersection& intersection = m_intersections[street.GetEndIntersectionID()];


		// Obey traffic rules. Only move the car forward if the light is green.
		if (front_car && intersection.IsLightGreenAtStreet(street.GetName()))
		{
			// Make sure the car's travel time is equal to the street's travel time
			// before moving it to the next street.
			std::string next_street = front_car->Drive(street);
			if (next_street != street_iter->first)
			{
				m_street_map[next_street].AddCar(*front_car);
				street.RemoveFrontCar();
			}
			// Remove the car from the traffic network if it has completed its journey.
			if (front_car->DidCompleteJourney())
			{
				street.RemoveFrontCar();
				// Accumulate points.
				m_point_total += (m_car_arrival_bonus + m_time_left);
			}
			// Advance any cars behind the front car on the same street.
			// TODO Make sure cars are being updated correctly, that the references
			// are correct, that the changes persist
			std::deque<Car>* street_cars = street.GetCarQueue();
			for (Car car : *street_cars)
			{
				car.Drive(street);
			}
		}
		if (front_car && !did_find_cars)
		{
			did_find_cars = true;
		}
	}

	// Update all streets.
	for (street_iter = m_street_map.begin(); street_iter != m_street_map.end(); ++street_iter)
	{
		street_iter->second.Update();
	}

	// Update all intersection lights
	for (auto intersection_iter = m_intersections.begin(); intersection_iter != m_intersections.end(); ++intersection_iter)
	{
		intersection_iter->second.Update();
	}

	if (m_time_left > 0)
	{
		m_time_left--;
	}

}

uint32_t TrafficNetwork::GetTimeLimit()
{
	return m_world_time_limit;
}

uint32_t TrafficNetwork::GetTimeLeft()
{
	return m_time_left;
}

std::map<std::string, Street> TrafficNetwork::GetStreetState()
{
	return m_street_map;
}