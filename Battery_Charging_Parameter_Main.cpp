#include "Battery_Charging_Parameter.hpp"

int main() {
    float min_Soc = 20.0;
    float max_Soc = 80.0;
    float min_Temperature = 0.0;
    float min_Temperature = 45.0;
    std::cout<<batteryParameterReadings(min_Soc, max_Soc);
  std::cout<<batteryParameterReadings(min_Temperature, min_Temperature);
  
    return 0;
}
