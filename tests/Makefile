CC = g++
CFLAGS = -std=c++11 -Wall -g

all: TrafficLight.o Car.o Street.o Intersection.o BasicTrafficScheduleCalculator.o TrafficNetwork.o TrafficNetworkTest.cpp
	$(CC) $(CFLAGS)  TrafficLight.o  Car.o Street.o Intersection.o TrafficNetwork.o TrafficNetworkTest.cpp -lgtest -lgtest_main -pthread -o testProgram

TrafficNetwork.o: ../TrafficNetwork.cpp
	$(CC) $(CFLAGS) -c ../TrafficNetwork.cpp

BasicTrafficScheduleCalculator.o: ../BasicTrafficScheduleCalculator.cpp ../TrafficScheduleCalculator.cpp
	$(CC) $(CFLAGS) -c ../BasicTrafficScheduleCalculator.cpp ../TrafficScheduleCalculator.cpp

Intersection.o: ../Intersection.cpp
	$(CC) $(CFLAGS) -c ../Intersection.cpp

Car.o: ../Car.cpp
	$(CC) $(CFLAGS) -c ../Car.cpp

Street.o: ../Street.cpp
	$(CC) $(CFLAGS) -c ../Street.cpp

TrafficLight.o: ../TrafficLight.cpp
	$(CC) $(CFLAGS) -c ../TrafficLight.cpp
