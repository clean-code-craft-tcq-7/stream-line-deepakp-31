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
    REQUIRE(isBatterParamterValid(temperature_reading.at(iterator), min_val, max_val) ==
            validity_of_temperature_reading.at(iterator));
  }

  min_val = 20.0;
  max_val = 80.0;

  std::vector<float> soc_reading = { 20.0, 80.1, 80.0, 19.9 };
  std::vector<bool> validity_of_soc_reading = { true, false, true, false };

  for (int iterator = 0; iterator < static_cast<int>(soc_reading.size()); iterator++)
  {
    REQUIRE(isBatterParamterValid(soc_reading.at(iterator), min_val, max_val) == validity_of_soc_reading.at(iterator));
  }
}

TEST_CASE("Test case for generating random readings")
{
  float min = 0.0;
  float max = 45.0;
  std::vector<float> battery_parameters = generateRandomReading(min, max);

  REQUIRE(isReadinginRange(min, max, battery_parameters) == true);
}

// TEST_CASE("Test case for Print Output")
// {
//   printOutput(10.0, 11.2);
// }
