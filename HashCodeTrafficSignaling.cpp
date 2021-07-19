// HashCodeTrafficSignaling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

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
    trafficNetwork.Step();
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
