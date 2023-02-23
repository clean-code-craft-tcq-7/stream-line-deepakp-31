#include <stdio.h>
#include <string.h>
#include "receiver.h"

void Receiver(char *rxBuffer,char sensor1Buff[][MAX_RECEIVE_BYTE])
{
	int separateCnt = 0;
	int rxCnt = 0;
	sensor1Buff[0][0] = '\0';
	sensor1Buff[1][0] = '\0';
	while(*rxBuffer != '\0')
	{
		sensor1Buff[separateCnt][rxCnt++] = *rxBuffer;
	    rxBuffer++;
		if(*rxBuffer == '\n')
		{
			if(strcmp(&sensor1Buff[separateCnt][ARRAY_INDEX0],"Battery_Charging_Parameter")!= 0)
			{
				separateCnt++;
			}
			else
			{
				memset(&sensor1Buff[separateCnt],0,rxCnt);
			}
			rxCnt = 0;
			rxBuffer++;
		}
	}
}

void readfromConsole(char* rxBuffer)
{    
    fgets(rxBuffer,MAX_RECEIVE_BYTE,stdin);
}