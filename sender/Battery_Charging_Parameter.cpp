#include "Battery_Charging_Parameter.hpp"

bool isBatteryParameterWithinLimits(float variable, float min, float max, std::string outputString)
{
  if (variable < min || variable > max)
  {
    
    return false;
  }
  else
  {
    return true;
  }
}
