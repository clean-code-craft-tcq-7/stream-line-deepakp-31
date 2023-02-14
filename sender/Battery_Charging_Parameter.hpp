#pragma once

#ifndef BATTRERY_CHARGING_PARAMETER
#define BATTRERY_CHARGING_PARAMETER

#include <iostream>
#include <vector>
#include <cstdlib>

bool isBatterParamterValid(float variable, float min, float max);

std::vector<float> generateRandomReading(float min, float max);

bool isReadinginRange(float min, float max, std::vector<float>  battery_parameters);

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