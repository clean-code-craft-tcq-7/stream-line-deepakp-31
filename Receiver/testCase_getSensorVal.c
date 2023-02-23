#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "getSensorVal.h"

void testCaseGetRxFloatVal()
{
//Empty array
	char sensorRead[1000]={};
    st_Sensor sensorReadingArr[2]={};
	getSensorRxValues(sensorRead,&sensorReadingArr[0]);
	assert(sensorReadingArr[0].number == 0);
    assert(sensorReadingArr[0].readingCnt == 0);
    assert(fabs(sensorReadingArr[0].value[0] - 0.0) < 0.0001);

//get Sensor name only
	char sensorRead1[1000]={"SOC: "};
	st_Sensor sensorReadingArr1[2]={};
	getSensorRxValues(sensorRead1,&sensorReadingArr1[0]);
	assert(sensorReadingArr1[0].number == 1);
    assert(sensorReadingArr1[0].readingCnt == 1);
    assert(fabs(sensorReadingArr1[0].value[0] - 0.0) < 0.0001);

//get Sensor name and one sensor value get
	char sensorRead2[1000]={"SOC: 70.411263"};
	st_Sensor sensorReadingArr2[2]={};
	getSensorRxValues(sensorRead2,&sensorReadingArr2[0]);
	assert(sensorReadingArr2[0].number == 1);
    assert(sensorReadingArr2[0].readingCnt == 1);
    assert(fabs(sensorReadingArr2[0].value[0] - 70.411263) < 0.0001);	

//get Sensor name and 4 sensor value get
	char sensorRead3[1000]={"SOC: 70.411263,43.662975,66.985954,67.906403"};
    st_Sensor sensorReadingArr3[2]={};
	getSensorRxValues(sensorRead3,&sensorReadingArr3[0]);
	assert(sensorReadingArr3[0].number == 1);
    assert(sensorReadingArr3[0].readingCnt == 4);
    assert(fabs(sensorReadingArr3[0].value[0] - 70.411263) < 0.0001);
    assert(fabs(sensorReadingArr3[0].value[1] - 43.662975) < 0.0001);
    assert(fabs(sensorReadingArr3[0].value[2] - 66.985954) < 0.0001);
    assert(fabs(sensorReadingArr3[0].value[3] - 67.906403) < 0.0001);
}