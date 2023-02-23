#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"
#include "getSensorVal.h"
#include "getMinMaxVal.h"
#include "getMovingAvg.h"
#include "printMinMaxSMA.h"

void printMinMax_SMA(void (*receiver)(char*),void (*print)(int,st_Sensor,float*))
{
    static int rxCnt =0;
    char rxBuffer[MAX_SENSOR+(2*HEADER_STRCNT)][MAX_RECEIVE_BYTE];
    char sensor1Read[MAX_SENSOR][MAX_RECEIVE_BYTE];
    st_Sensor sensorReadingArr[MAX_SENSOR];
    float smaSensorOut[MAX_SENSOR][MAX_GET_SENSOR_VALUE];

    for(int i=0;i<(MAX_SENSOR+(2*HEADER_STRCNT));i++)
    {
        receiver(rxBuffer[i]);
    }
    getSensorRxValues(rxBuffer[1],&sensorReadingArr[ARRAY_INDEX0]);
    getSensorRxValues(rxBuffer[3],&sensorReadingArr[ARRAY_INDEX1]);
    getMinMaxVal(&sensorReadingArr[ARRAY_INDEX0]);
    getMinMaxVal(&sensorReadingArr[ARRAY_INDEX1]);
    simpleMovingAvg(&sensorReadingArr[ARRAY_INDEX0].value[0],sensorReadingArr[ARRAY_INDEX0].readingCnt-5,sensorReadingArr[ARRAY_INDEX0].readingCnt,&smaSensorOut[ARRAY_INDEX0][0]);
    simpleMovingAvg(&sensorReadingArr[ARRAY_INDEX1].value[0],sensorReadingArr[ARRAY_INDEX1].readingCnt-5,sensorReadingArr[ARRAY_INDEX1].readingCnt,&smaSensorOut[ARRAY_INDEX1][0]);
    for(int j=0;j<MAX_SENSOR;j++)
    {
        (*print)(j,sensorReadingArr[j],smaSensorOut[j]);
    }
}

void printConsole(int sensornum,st_Sensor Data,float* smaData)
{
    printf("Sensor%d Min : %f, Max : %f\n",sensornum,Data.minVal,Data.maxVal);
    printf("Sensor%d Last 5 SMA value: %f, %f, %f, %f, %f\n",sensornum,smaData[0],smaData[1],smaData[2],smaData[3],smaData[4]);
}
