#include <stdio.h>
#include <assert.h>
#include "getSensorVal.h"
#include "getMinMaxVal.h"

void testCasesGetMinMaxVal()
{
//Get empty sensor value
	st_Sensor sensorReadingArr={};
	getMinMaxVal(&sensorReadingArr);
	assert(sensorReadingArr.minVal == 0.0);
	assert(sensorReadingArr.maxVal == 0.0);

//Get one sensor value
	sensorReadingArr.readingCnt = 1;
	sensorReadingArr.value[0] = 70.411263;
	getMinMaxVal(&sensorReadingArr);
	assert(sensorReadingArr.minVal == 70.411263);
	assert(sensorReadingArr.maxVal == 70.411263);

//Get 4 sensor value
	sensorReadingArr.readingCnt = 4;
	sensorReadingArr.value[0] = 70.411263;
	sensorReadingArr.value[1] = 43.662975;
	sensorReadingArr.value[2] = 66.985954;
	sensorReadingArr.value[3] = 67.906403;
	getMinMaxVal(&sensorReadingArr);
	assert(sensorReadingArr.minVal == 43.662975);
	assert(sensorReadingArr.maxVal == 70.411263);	
}