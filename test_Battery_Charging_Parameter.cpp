#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

#include "Battery_Charging_Parameter.hpp"

// include hpp file of battery charging parameter

TEST_CASE("Test case for Battery paramter within limits")
{
  float min_val = 0.0;
  float max_val = 45.0;

  std::vector<float> temperature_reading = { 0.0, 45.1, 45.0, -0.1 };
  std::vector<bool> validity_of_temperature_reading = { true, false, true, false };

  for (int iterator = 0; iterator < static_cast<int>(temperature_reading.size()); iterator++)
  {
    REQUIRE(isBatteryParameterWithinLimits(temperature_reading.at(iterator), min_val, max_val) ==
            validity_of_temperature_reading.at(iterator));
  }

  min_val = 20.0;
  max_val = 80.0;

  std::vector<float> soc_reading = { 20.0, 80.1, 80.0, 19.9 };
  std::vector<bool> validity_of_soc_reading = { true, false, true, false };

  for (int iterator = 0; iterator < static_cast<int>(soc_reading.size()); iterator++)
  {
    REQUIRE(isBatteryParameterWithinLimits(soc_reading.at(iterator), min_val, max_val) ==
            validity_of_soc_reading.at(iterator));
  }
}

TEST_CASE("Test case for generating random readings")
{
  float min = 0.0;
  float max = 45.0;
  std::vector<float> battery_parameters = generateRandomReading(min, max);

  REQUIRE(isReadinginRange(min, max, battery_parameters) == true);
}

TEST_CASE("Test case for string creation")
{
  REQUIRE(createString({}, 11.2) == ", 11.200000");
}

TEST_CASE("Test case for generateing final Output")
{
  std::vector<float> battery_parameter_readings = {
    3, 7, 8, 23, 56, 3, 3, 20.0, 80.1, 80.0, 19.9, 0.0, 45.1, 45.0, -1.1
  };

  std::string generatedString =
      "3.000000, 7.000000, 8.000000, 23.000000, 56.000000, 3.000000, 3.000000, 20.000000, 80.099998, 80.000000, "
      "19.900000, 0.000000, 45.099998, 45.000000, -1.100000";

  REQUIRE(generateOutput(battery_parameter_readings) == generatedString);
}

TEST_CASE("Test case Readings for battery parameter ")
{
}
