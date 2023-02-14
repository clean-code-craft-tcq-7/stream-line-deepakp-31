#include "Battery_Charging_Parameter.hpp"

bool isBatteryParameterWithinLimits(float f_variable, float f_min, float f_max)
{
  if (f_variable < f_min || f_variable > f_max)
  {
    return false;
  }
  else
  {
    return true;
  }
}

std::vector<float> generateRandomReading(float f_min, float f_max)
{
  std::vector<float> battery_parameters{};
  for (int i = 0; i < 50; i++)
  {
    battery_parameters.push_back(f_min + static_cast<float>(rand()) * static_cast<float>(f_max - f_min) / RAND_MAX);
  }
  return battery_parameters;
}

bool isReadinginRange(float f_min, float f_max, std::vector<float> battery_parameters)
{
  bool inRange = true;
  for (auto battery_parameter : battery_parameters)
  {
    inRange = isBatteryParameterWithinLimits(battery_parameter, f_min, f_max);
  }
  return inRange;
}
