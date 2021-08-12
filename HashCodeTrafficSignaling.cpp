// HashCodeTrafficSignaling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Car.h"
#include "Street.h"
#include "Intersection.h"
#include "TrafficLight.h"
#include "TrafficNetwork.h"
#include "HashCodeTrafficSignaling.h"

using namespace std;

int main()
{
    // Create the traffic network
    TrafficNetwork trafficNetwork;
    trafficNetwork.BuildTrafficNetwork("Input/a.txt");
	cout << "Begining traffic simulation." << endl << endl;
    while (trafficNetwork.GetTimeLeft() > 0)
    {
		trafficNetwork.Step();
		map<string, Street> street_map = trafficNetwork.GetStreetState();
		for (auto street_map_iter = street_map.begin(); street_map_iter != street_map.end(); ++street_map_iter)
		{
			cout << street_map_iter->first << " has " << street_map_iter->second.GetCarQueue()->size() << " cars" << endl;
		}
		cout << "----------" << endl;
    }
}

/*
General Questions:
- When to use pointers in a class definition?
- When to use pointers in general?
*/

/*
General Notes:
- When vector/deque complain about an unknown size or type, usually the .h
  files were out of order in the #includes and the type was "unknown". This
  happened with classes that had containers of other classes, such as Street
  which has a deque of Cars.
*/
