#include <stdio.h>
#include <string.h>
#include "getMovingAvg.h"

void simpleMovingAvg(float* sensorVal,int startIndex,int sensorReadingCnt,float* smgSensorOut)
{
    int smgLoopCnt = 0;
	for(int loopCnt = startIndex; (sensorReadingCnt > 0)&&(loopCnt < sensorReadingCnt); loopCnt++)
	{
		smgSensorOut[smgLoopCnt] = 0.0;
		for(int smgCnt =0;(smgCnt <5)&&(smgCnt <= loopCnt);smgCnt++)
		{
			smgSensorOut[smgLoopCnt] += sensorVal[loopCnt-smgCnt]/5;
		}
		smgLoopCnt++;
	}
}
