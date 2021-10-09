#include <iostream>
#include <gtest/gtest.h>

#include "../TrafficLight.h"

TEST(TrafficNetworkSuite, TrafficLightTest)
{
  TrafficLight tl;
  ASSERT_FALSE(tl.IsGreen()) << "The light should start red";
} 
/*
TEST(IntegerInputsSuite, oneElement)
{
  const int SIZE = 1;
  double arr[SIZE]  = {33};
  EXPECT_EQ(summer(arr, SIZE), 33) << "The sum is not correct for array of size 1";
}
TEST(DoubleInputsSuite, simpleSum)
{
  const int SIZE = 3;
  double arr[SIZE]  = {1.1, 1.1, 1};
  EXPECT_EQ(summer(arr, SIZE), 3.2) << "The sum is not correct using     double inputs";
}
*/
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
