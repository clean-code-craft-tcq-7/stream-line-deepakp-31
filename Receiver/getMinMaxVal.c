#include <stdio.h>
#include "getSensorVal.h"
#include "getMinMaxVal.h"

void getMinMaxVal(st_Sensor* sensorArr)
{
    sensorArr->minVal = sensorArr->value[VALARRAY_INDEX0];
    sensorArr->maxVal = sensorArr->value[VALARRAY_INDEX0];
    for(int loopCnt = 1; loopCnt<sensorArr->readingCnt; loopCnt++)
    {
        if(sensorArr->minVal > sensorArr->value[loopCnt])
        {
            sensorArr->minVal = sensorArr->value[loopCnt];
        }
        if(sensorArr->maxVal < sensorArr->value[loopCnt])
        {
            sensorArr->maxVal = sensorArr->value[loopCnt];
        }
    }
}
