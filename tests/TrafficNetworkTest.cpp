#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <gtest/gtest.h>

#include "../TrafficLight.h"
#include "../Car.h"
#include "../Street.h"
#include "../Intersection.h"
#include "../TrafficNetwork.h"

// TODO Cars are copied as they are moved through the network. It might be more efficient to use pointers.
TEST(TrafficNetworkSuite, TrafficLightTest)
{
  TrafficLight tl;
  ASSERT_FALSE(tl.IsGreen()) << "The light should start red";
}

TEST(TrafficNetworkSuite, TrafficNetworkTest)
{
    uint32_t simulation_time_limit = 6;
    uint32_t number_of_streets = 5;


    TrafficNetwork tn;
    tn.BuildTrafficNetwork("../Input/a.txt");

    // Check time limit is initialized.
    ASSERT_EQ(simulation_time_limit, tn.GetTimeLimit());

    // Check that time left is equal to time limit
    ASSERT_EQ(simulation_time_limit, tn.GetTimeLeft());

    // Check initial street state.
    std::map<std::string, Street> network_street_state = tn.GetStreetState();
    ASSERT_EQ(number_of_streets, network_street_state.size());

    // Check that rue-de-londres has one car at the end of the street.
    ASSERT_TRUE(network_street_state.find("rue-de-londres") != network_street_state.end());
    ASSERT_EQ(1, network_street_state["rue-de-londres"].GetCarQueue()->size());
    ASSERT_TRUE(network_street_state["rue-de-londres"].GetFrontCar()->IsAtEndOfStreet(network_street_state["rue-de-londres"]));
    // Check car 1 assigned path
    Car* p_car_1 = network_street_state["rue-de-londres"].GetFrontCar();
    std::vector<std::string> expected_path_1 = { "rue-de-londres", "rue-d-amsterdam", "rue-de-moscou", "rue-de-rome" };
    ASSERT_EQ(expected_path_1, p_car_1->GetJourneyPath());
    ASSERT_TRUE(p_car_1->IsAtEndOfStreet(network_street_state["rue-de-londres"]));

    // Check that rue-d-athenes has one car at the end of the street.
    ASSERT_TRUE(network_street_state.find("rue-d-athenes") != network_street_state.end());
    ASSERT_EQ(1, network_street_state["rue-d-athenes"].GetCarQueue()->size());
    ASSERT_TRUE(network_street_state["rue-d-athenes"].GetFrontCar()->IsAtEndOfStreet(network_street_state["rue-d-athenes"]));
    // Check car 2 assigned path
    Car* p_car_2 = network_street_state["rue-d-athenes"].GetFrontCar();
    std::vector<std::string> expected_path_2 = { "rue-d-athenes", "rue-de-moscou", "rue-de-londres" };
    ASSERT_EQ(expected_path_2, p_car_2->GetJourneyPath());
    ASSERT_TRUE(p_car_2->IsAtEndOfStreet(network_street_state["rue-d-athenes"]));

    // Calculate traffic schedule from input solution file.
    tn.SetTrafficLights("../Input/a_solution.txt");

    // Validate intersection start states
    Intersection* p_intersection_0 = tn.GetIntersectionById(0);
    ASSERT_FALSE(p_intersection_0 == nullptr);
    ASSERT_TRUE(p_intersection_0->IsLightGreenAtStreet("rue-de-londres"));

    Intersection* p_intersection_1 = tn.GetIntersectionById(1);
    ASSERT_FALSE(p_intersection_1 == nullptr);
    ASSERT_TRUE(p_intersection_1->IsLightGreenAtStreet("rue-d-athenes"));
    ASSERT_FALSE(p_intersection_1->IsLightGreenAtStreet("rue-d-amsterdam"));

    // TODO Validate first time step.
    tn.Step();
    network_street_state = tn.GetStreetState(); // Get the new street state!
    EXPECT_EQ(0, network_street_state["rue-de-londres"].GetCarQueue()->size());
    ASSERT_EQ(1, network_street_state["rue-d-amsterdam"].GetCarQueue()->size());
    ASSERT_EQ(network_street_state["rue-d-amsterdam"].GetFrontCar()->GetJourneyPath(), expected_path_1);

    EXPECT_EQ(0, network_street_state["rue-d-athenes"].GetCarQueue()->size());
    ASSERT_EQ(1, network_street_state["rue-de-moscou"].GetCarQueue()->size());
    ASSERT_EQ(network_street_state["rue-de-moscou"].GetFrontCar()->GetJourneyPath(), expected_path_2);

    /*
    while (tn.GetTimeLeft() > 0)
    {
		tn.Step();
    }

    uint32_t expected_point_total = 1002;
	ASSERT_EQ(expected_point_total, tn.GetPoints());
    */
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
