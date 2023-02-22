#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "receiver.h"

void testCaseRx()
{
//Empty Buffer check
	char rxBuff[]={};
	char sensor1Read[1000];
    char sensor2Read[1000];
    Receiver(rxBuff,sensor1Read,sensor2Read);
    assert(strcmp(sensor1Read,"\0")==0);

//Header only received
	char rxBuff1[] = {"Battery_Charging_Parameter\n"};
	strcpy(sensor1Read,"\0");
	strcpy(sensor2Read,"\0");
    Receiver(rxBuff1,sensor1Read,sensor2Read);
    assert(strcmp(sensor1Read,"\0")==0);

//Name received	but sesnor value not received
	char rxBuff2[] = {"Battery_Charging_Parameter\nSOC: "};
	strcpy(sensor1Read,"\0");
	strcpy(sensor2Read,"\0");
    Receiver(rxBuff2,sensor1Read,sensor2Read);
    assert(strcmp(sensor1Read,"SOC: ")==0);

//Sensor name with One reading value received	
	char rxBuff3[] = {"Battery_Charging_Parameter\nSOC: 70.411263"};
	strcpy(sensor1Read,"\0");
	strcpy(sensor2Read,"\0");
    Receiver(rxBuff3,sensor1Read,sensor2Read);
    assert(strcmp(sensor1Read,"SOC: 70.411263")==0);
	
//Sensor name with 5 reading value received	
	char rxBuff4[] = {"Battery_Charging_Parameter\nSOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837"};
	strcpy(sensor1Read,"\0");
	strcpy(sensor2Read,"\0");
    Receiver(rxBuff4,sensor1Read,sensor2Read);
    assert(strcmp(sensor1Read,"SOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837")==0);
}