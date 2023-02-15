#pragma once

#ifndef BATTRERY_CHARGING_PARAMETER
#define BATTRERY_CHARGING_PARAMETER

#include <iostream>
#include <vector>
#include <random>

// Check if battery Parameter in limits
bool isBatteryParameterWithinLimits(float f_variable, float f_min, float f_max);

// Check if vector of battery Parameter in limits
bool isReadinginRange(float f_min, float f_max, std::vector<float> f_battery_parameters);

// Generate random readings given min and max
std::vector<float> generateRandomReading(float f_min, float f_max);

// Create string given string and reading or value
std::string createString(std::string f_output_string, float f_value);

// Create Final outut string given vector of readings
std::string generateOutput(std::vector<float> f_battery_parameter_readings);

// Random Battery parameter reading given min and max
std::string batteryParameterReadings(float f_min, float f_max);

#endif