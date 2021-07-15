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
}

/*
General Questions:
- When to use pointers in a class definition?
- When to use pointers in general?
*/
