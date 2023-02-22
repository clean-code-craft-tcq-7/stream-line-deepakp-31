#include <stdio.h>
#include <string.h>
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
    assert(sensorReadingArr[0].value[0] == 0.0);
	
//get Sensor name only
	char sensorRead1[1000]={"SOC: "};
	getSensorRxValues(sensorRead1,&sensorReadingArr[0]);
	assert(sensorReadingArr[0].number == 1);
    assert(sensorReadingArr[0].readingCnt == 0);
    assert(sensorReadingArr[0].value[0] == 0.0);


//get Sensor name and one sensor value get
	char sensorRead2[1000]={"SOC: 70.411263"};
	getSensorRxValues(sensorRead2,&sensorReadingArr[0]);
	assert(sensorReadingArr[0].number == 1);
    assert(sensorReadingArr[0].readingCnt == 1);
    assert(sensorReadingArr[0].value[0] == 70.411263);	

//get Sensor name and 4 sensor value get
	char sensorRead3[1000]={"SOC: 70.411263, 43.662975, 66.985954, 67.906403"};
	getSensorRxValues(sensorRead2,&sensorReadingArr[0]);
	assert(sensorReadingArr[0].number == 1);
    assert(sensorReadingArr[0].readingCnt == 4);
    assert(sensorReadingArr[0].value[0] == 70.411263);
    assert(sensorReadingArr[0].value[1] == 43.662975);
    assert(sensorReadingArr[0].value[2] == 66.985954);
    assert(sensorReadingArr[0].value[3] == 67.906403);	
}
