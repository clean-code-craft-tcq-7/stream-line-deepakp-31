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

bool isReadinginRange(float f_min, float f_max, std::vector<float> f_battery_parameters)
{
  bool inRange = true;
  for (auto battery_parameter : f_battery_parameters)
  {
    inRange = isBatteryParameterWithinLimits(battery_parameter, f_min, f_max);
  }
  return inRange;
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

std::string createString(std::string f_output_string, float f_battery_parameter)
{
  return (f_output_string + ", " + std::to_string(f_battery_parameter));
}

std::string generateOutput(std::vector<float> f_battery_parameter_readings)
{
  std::string f_output_string = std::to_string(f_battery_parameter_readings.at(0));

  for (int i = 1; i < static_cast<int>((f_battery_parameter_readings.size())); i++)
  {
    f_output_string = createString(f_output_string, f_battery_parameter_readings.at(i));
  }
  return f_output_string;
}

std::string batteryParameterReadings(float f_min, float f_max)
{
  std::vector<float> battery_parameter_readings = generateRandomReading(f_min, f_max);

  return generateOutput(battery_parameter_readings);
}