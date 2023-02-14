#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

#include "Battery_Charging_Parameter.hpp"

// include hpp file of battery charging parameter

TEST_CASE("Test case for Batteryy paramter within limits")
{
    int max_val = 0.0;
    int min_val = 45.0;

    std::vector<float> temperature_reading = {0.0, 45.1, 45.0, -0.1};
    std::vector<bool> validity_of_temperature_reading = {true, false, true, false};

    for (int iterator = 0; iterator < static_cast<int>(temperature_reading.size()); iterator++)
    {
        REQUIRE(isBatterParamterValid(temperature_reading.at(iterator), min_val, max_val) == validity_of_temperature_reading.at(iterator));
    }

    max_val = 20.0;
    min_val = 80.0;

    std::vector<float> soc_reading = {20.0, 80.1, 80.0, 19.9};
    std::vector<bool> validity_of_soc_reading = {true, false, true, false};

    for (int iterator = 0; iterator < static_cast<int>(soc_reading.size()); iterator++)
    {
        REQUIRE(isBatterParamterValid(soc_reading.at(iterator), min_val, max_val) == validity_of_soc_reading.at(iterator));
    }
}