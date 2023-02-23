#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"
#include "getSensorVal.h"
#include "getMinMaxVal.h"
#include "getMovingAvg.h"
#include "testCases.h"

void runTestcases()
{
    testCaseRx();
    testCaseGetRxFloatVal();
    testCasesGetMinMaxVal();
    testCaseMovingAvg();
    testprintMinMax_SMA();
}

void testprintMinMax_SMA()
{
    char rxBuff[] = {"Battery_Charging_Parameter\nSOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837, 31.853083, 40.113365, 66.093781, 36.666481, 53.238197, 48.643822, 57.732254, 41.887070, 50.804054, 77.133789, 74.971710, 58.142704, 63.037819, 28.496155, 56.418133, 20.978035, 34.573204, 28.233894, 68.250610, 29.400745, 44.056664, 27.787426, 26.528528, 79.935471, 33.095413, 50.775948, 70.346733, 56.758392, 37.761898, 58.253136, 51.457230, 49.614979, 78.366501, 37.551010, 66.281464, 51.604698, 66.194832, 44.013718, 73.491768, 36.998886, 41.147499, 68.463470, 75.141586, 24.185316, 76.959625\nBattery_Charging_Parameter\nTemperature: 23.669792, 3.872513, 8.649623, 29.845211, 40.060467, 15.700182, 2.887709, 0.901037, 20.596579, 2.839313, 10.722598, 43.678535, 40.599365, 38.291389, 11.999959, 24.289215, 16.884314, 34.211193, 23.064093, 30.047569, 23.922289, 1.767615, 19.693691, 41.932579, 41.886440, 32.442856, 12.793203, 33.234043, 28.799047, 15.932190, 30.953762, 7.468838, 19.804703, 39.603386, 37.314049, 14.865171, 10.303568, 40.201759, 15.766209, 30.900145, 43.041069, 26.488808, 29.578682, 38.640434, 19.780195, 41.578640, 17.929649, 36.664509, 30.789833, 40.993744\n"};
    
    char sensor1Read[MAX_SENSOR][MAX_RECEIVE_BYTE];
    st_Sensor sensorReadingArr[MAX_SENSOR];
    float smaSensorOut[MAX_SENSOR][MAX_GET_SENSOR_VALUE];

    Receiver(rxBuff,sensor1Read);
    getSensorRxValues(sensor1Read[0],&sensorReadingArr[ARRAY_INDEX0]);
    getSensorRxValues(sensor1Read[1],&sensorReadingArr[ARRAY_INDEX1]);
    getMinMaxVal(&sensorReadingArr[ARRAY_INDEX0]);
    getMinMaxVal(&sensorReadingArr[ARRAY_INDEX1]);
    simpleMovingAvg(&sensorReadingArr[ARRAY_INDEX0].value[0],sensorReadingArr[ARRAY_INDEX0].readingCnt-5,sensorReadingArr[ARRAY_INDEX0].readingCnt,&smaSensorOut[ARRAY_INDEX0][0]);
    simpleMovingAvg(&sensorReadingArr[ARRAY_INDEX1].value[0],sensorReadingArr[ARRAY_INDEX1].readingCnt-5,sensorReadingArr[ARRAY_INDEX1].readingCnt,&smaSensorOut[ARRAY_INDEX1][0]);
    printf("Sensor1 Min : %f, Max : %f\n",sensorReadingArr[ARRAY_INDEX0].minVal,sensorReadingArr[ARRAY_INDEX0].maxVal);
    printf("Sensor2 Min : %f, Max : %f\n",sensorReadingArr[ARRAY_INDEX1].minVal,sensorReadingArr[ARRAY_INDEX1].maxVal);
    printf("Sensor1 Last 5 SMA value: %f, %f, %f, %f, %f\n",smaSensorOut[ARRAY_INDEX0][0],smaSensorOut[ARRAY_INDEX0][1],smaSensorOut[ARRAY_INDEX0][2],smaSensorOut[ARRAY_INDEX0][3],smaSensorOut[ARRAY_INDEX0][4]);
    printf("Sensor2 Last 5 SMA value: %f, %f, %f, %f, %f\n",smaSensorOut[ARRAY_INDEX1][0],smaSensorOut[ARRAY_INDEX1][1],smaSensorOut[ARRAY_INDEX1][2],smaSensorOut[ARRAY_INDEX1][3],smaSensorOut[ARRAY_INDEX1][4]);
}