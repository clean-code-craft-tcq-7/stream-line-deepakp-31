#pragma once

#ifndef BATTRERY_CHARGING_PARAMETER
#define BATTRERY_CHARGING_PARAMETER

#include <iostream>
#include <vector>
#include <random>

bool isBatteryParameterWithinLimits(float f_variable, float f_min, float f_max);

std::vector<float> generateRandomReading(float f_min, float f_max);

bool isReadinginRange(float f_min, float f_max, std::vector<float> f_battery_parameters);

std::string createString(std::string f_output_string, float f_value);

std::string generateOutput(std::vector<float> f_battery_parameter_readings);

std::string batteryParameterReadings(float f_min, float f_max);


// class CBatteyCharging
// {
// public:
//   // Assuming the parameter is just transformation achieved by simple multiplication and shifting

// private:
//   bool tempOk;
//   bool socOk;
//   bool inRange;
// };

#endif