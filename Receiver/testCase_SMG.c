#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "getMovingAvg.h"
#include "testCases.h"

void testCaseMovingAvg()
{
//empty sensor reading
	float sensorRead[] ={};
	float outSensor[100];
	memset(outSensor,0.0,100);
	memset(sensorRead,0.0,100);
	simpleMovingAvg(sensorRead,0,0,outSensor);
	assert(outSensor[0] == 0.0);
	
//one sensor reading
	memset(outSensor,0.0,100);
	float sensorRead1[] ={12.5};
	simpleMovingAvg(sensorRead1,0,1,outSensor);
	assert(outSensor[0] == 2.5);

//7 sensor reading SMA
	memset(outSensor,0.0,100);
	memset(sensorRead,0.0,100);
	float sensorRead2[] ={12.5,14.8,11.3,10.9,8.2,15.7,23.4};
	simpleMovingAvg(sensorRead2,0,7,outSensor);
	float smgOut[] = {2.5,5.46,7.72,9.9,11.54,12.179999,13.9};
	for(int i=0; i< 7;i++)
	{
		assert(outSensor[i] == smgOut[i]);	
	}

//7 sensor reading and get last 5 SMA
	memset(outSensor,0.0,100);
	float sensorRead3[] ={12.5,14.8,11.3,10.9,8.2,15.7,23.4};
	simpleMovingAvg(sensorRead3,(7-5),7,outSensor);
	float smgOut1[] = {7.72,9.9,11.54,12.179999,13.9};
	for(int i=0; i< 7;i++)
	{
		assert(outSensor[i] == smgOut1[i]);	
	}
}