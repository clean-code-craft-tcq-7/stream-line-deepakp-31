#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getSensorVal.h"

char sensorNames[MAX_SENSOR][MAX_SENSOR_NAME_BYTE] = {"Temperature","SOC"};

void getSensorRxValues(char* rxSensorBuf,st_Sensor* sensorReadingArr)
{
    char name[MAX_SENSOR_NAME_BYTE];
    char readStrFloatVal[MAX_GET_SENSOR_VALUE]={};
    int readStrFloatCnt = 0;
    int readFloatCnt = 0;
    int nameCnt=0;
    if(*rxSensorBuf != '\0')
    {
        getSensorName(rxSensorBuf,name,&nameCnt);
        rxSensorBuf+=(2+nameCnt);
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
        sensorReadingArr->number = checkSensorID(name);
    }
}

void getSensorName(char* rxBuff,char* name,int* nameCnt)
{
    while(*rxBuff != ':')
    {
        name[*nameCnt] = *rxBuff++;
        *nameCnt += 1;
    }
}

int checkSensorID(char* readName)
{
    int retVal = -1;
    for(int loopcnt=0;loopcnt<2;loopcnt++)
    {
        if(strcmp(&sensorNames[loopcnt][0],readName) == 0)
        {
            retVal = loopcnt;
        }
    }
    return retVal;
}
