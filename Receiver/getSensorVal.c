#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getSensorVal.h"

char sensorNames[MAX_SENSOR][MAX_SENSOR_NAME_BYTE] = {"Temperature","SOC"};

void getSensorRxValues(char* rxSensorBuf,st_Sensor* sensorReadingArr)
{
    char name[MAX_SENSOR_NAME_BYTE];
    char readStrFloatVal[MAX_GET_SENSOR_VALUE]={};
    int nameCnt=0;
    int readStrFloatCnt = 0;
    int readFloatCnt = 0;
    float sensorOut=0.0;
    if(*rxSensorBuf != '\0')
    {
        while((*rxSensorBuf != '\0') && (*rxSensorBuf != ':'))
        {
            name[nameCnt++] = *rxSensorBuf++;
        }
        sensorReadingArr->number = checkSensorID(name);
        rxSensorBuf+=2;
        while((*rxSensorBuf != '\0') && (sensorReadingArr->number != -1))
        {
            if(*rxSensorBuf != ',')
            {
                readStrFloatVal[readStrFloatCnt++] = *rxSensorBuf;
            }
            else
            {
                sensorReadingArr->value[readFloatCnt] = atof(readStrFloatVal);
                readStrFloatCnt = 0;
                readFloatCnt++;
            }
            rxSensorBuf++;
        }
        sensorReadingArr->value[readFloatCnt++] = atof(readStrFloatVal);
        sensorReadingArr->readingCnt = readFloatCnt;
    }
}

int checkSensorID(char* readName)
{
    int retVal = -1;
    for(int loopcnt=0;loopcnt<2;loopcnt++)
    {
        if(strcmp(&sensorNames[loopcnt],readName) == 0)
        {
            retVal = loopcnt;
        }
    }
    return retVal;
}
