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
	// TODO Stop simulation early if all cars have arrived
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

	cout << "Total Points:\t" << trafficNetwork.GetPoints() << endl;
}


/*
The first line must contain a single integer A (0 <= A <= I), the number of intersections
for which you specify the schedule.

Then, the submission file must describe the intersection schedules, in any order.
Each schedule must be described by multiple lines:
	- The first line containing a single integer i (0 <= i < I). The ID of the intersection.
	- The second line containing a single integer E_i (0 < E_i). The number of
	  incoming streets (of the intersection i) covered by this schedule.
	- E_i lines describing the order and duration of green lights. Each of those lines
	  must contain (separated by a single space):
	  - the street name
	  - an integer T (1 <= T <= D). How long each street will have a green light.
*/

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
