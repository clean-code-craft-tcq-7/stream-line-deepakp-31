#include <stdio.h>
#include <string.h>
#include "receiver.h"

void Receiver(char *rxBuffer,char* sensor1Buff,char* sensor2Buff)
{
 	char SeparateBuff[MAX_SENSOR_OUT_READ][MAX_RECEIVE_BYTE] = {};
	int separateCnt = 0;
	int rxCnt = 0;
	while(*rxBuffer != '\0')
	{
		SeparateBuff[separateCnt][rxCnt++] = *rxBuffer;
	    rxBuffer++;
		if(*rxBuffer == '\n')
		{
			if(strcmp(&SeparateBuff[separateCnt][ARRAY_INDEX0],"Battery_Charging_Parameter")!= 0)
			{
				separateCnt++;
			}
			rxBuffer++;
		}
	}
	if(*SeparateBuff != '\0')
	{
		strcpy(sensor1Buff,&SeparateBuff[ARRAY_INDEX0]);
		strcpy(sensor2Buff,&SeparateBuff[ARRAY_INDEX1]);
	}
}

void getReceivedSensorVal(char* sensor1Buff,char* sensor2Buff)
{
    char rxBuffer[MAX_RECEIVE_BYTE];
    fgets(rxBuffer,MAX_RECEIVE_BYTE,stdout);
    Receiver(rxBuffer,sensor1Buff,sensor2Buff);
}
