#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"
#include "getSensorVal.h"
#include "getMinMaxVal.h"
#include "getMovingAvg.h"

void printMinMax_SMA()
{
    char sensor1Read[MAX_SENSOR][MAX_RECEIVE_BYTE];
    st_Sensor sensorReadingArr[MAX_SENSOR];
    float smaSensorOut[MAX_SENSOR][MAX_GET_SENSOR_VALUE];

    getReceivedSensorVal(sensor1Read);
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