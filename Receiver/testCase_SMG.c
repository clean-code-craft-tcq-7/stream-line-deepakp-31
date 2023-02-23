#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "getMovingAvg.h"
#include "getSensorVal.h"

void testCaseMovingAvg()
{
//empty sensor reading
	float sensorRead[] ={};
	float outSensor[100]={};
	simpleMovingAvg(sensorRead,0,0,outSensor);
	assert(outSensor[0] == 0.0);

//one sensor reading
	float sensorRead1[] ={12.5};
	float outSensor1[100]={};
	simpleMovingAvg(sensorRead1,0,1,outSensor1);
	assert(outSensor1[0] == 2.5);

//7 sensor reading SMA
	float sensorRead2[] ={12.5,14.8,11.3,10.9,8.2,15.7,23.4};
	float outSensor2[100] = {};
	simpleMovingAvg(sensorRead2,0,7,outSensor2);
	float smgOut[] = {2.5,5.46,7.72,9.9,11.54,12.179999,13.9};
	for(int i=0; i< 7;i++)
	{	
		assert(fabs(outSensor2[i] -smgOut[i]) < 0.0001);
	}

//7 sensor reading and get last 5 SMA
	float sensorRead3[] ={12.5,14.8,11.3,10.9,8.2,15.7,23.4};
	float outSensor3[100]={};
	simpleMovingAvg(sensorRead3,2,7,outSensor3);
	float smgOut1[] = {7.72,9.9,11.54,12.179999,13.9};
	for(int i=0; i< 5;i++)
	{
		assert(fabs(outSensor3[i] -smgOut1[i]) < 0.0001);
	}
}