#include "Battery_Charging_Parameter.hpp"

int main()
{
  float min_Soc = 20.0;
  float max_Soc = 80.0;
  float min_Temperature = 0.0;
  float max_Temperature = 45.0;
  std::cout << "Battery_Charging_Parameter \n"
            << "SOC: " << batteryParameterReadings(min_Soc, max_Soc) << "\n";
  std::cout << "Battery_Charging_Parameter \n"
            << "Temperature: " <<batteryParameterReadings(min_Temperature, max_Temperature) << "\n";

  return 0;
}
