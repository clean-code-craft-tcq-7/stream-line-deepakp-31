#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "receiver.h"

void testCaseRx()
{
//Name received but sesnor value not received
	char rxBuff2[] = {"Battery_Charging_Parameter\nSOC: "};
	char sensorRead2[20][MAX_RECEIVE_BYTE] ={'\0'};
    Receiver(rxBuff2,sensorRead2);
    assert(strcmp(sensorRead2[0],"SOC: ")==0);

//Sensor name with One reading value received	
	char rxBuff3[] = {"Battery_Charging_Parameter\nSOC: 70.411263"};
	char sensorRead3[20][MAX_RECEIVE_BYTE] ={'\0'};
    Receiver(rxBuff3,sensorRead3);
    assert(strcmp(sensorRead3[0],"SOC: 70.411263")==0);

//Sensor name with 5 reading value received	
	char rxBuff4[] = {"Battery_Charging_Parameter\nSOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837"};
	char sensorRead4[20][MAX_RECEIVE_BYTE] ={'\0'};
    Receiver(rxBuff4,sensorRead4);
    assert(strcmp(sensorRead4[0],"SOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837")==0);
 
 //2Sensor name with 5 reading value received	
	char rxBuff5[] = {"Battery_Charging_Parameter\nSOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837\nTemperature: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837"};
	char sensorRead5[20][MAX_RECEIVE_BYTE] ={'\0'};
    Receiver(rxBuff5,sensorRead5);
    assert(strcmp(sensorRead5[0],"SOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837")==0);
    assert(strcmp(sensorRead5[1],"Temperature: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837")==0);
 }