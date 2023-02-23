#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"
#include "getSensorVal.h"
#include "getMinMaxVal.h"
#include "getMovingAvg.h"
#include "printMinMaxSMA.h"
#include "testCases.h"

void runTestcases()
{
    testCaseGetRxFloatVal();
    testCasesGetMinMaxVal();
    testCaseMovingAvg();
}

void testreadFromText(char* rxBuffer)
{
    char buff[MAX_SENSOR+(2*HEADER_STRCNT)][MAX_RECEIVE_BYTE] = 
    {
    	{"Battery_Charging_Parameter\n"},
    	{"SOC: 70.411263, 43.662975, 66.985954, 67.906403, 74.698837, 31.853083, 40.113365, 66.093781, 36.666481, 53.238197, 48.643822, 57.732254, 41.887070, 50.804054, 77.133789, 74.971710, 58.142704, 63.037819, 28.496155, 56.418133, 20.978035, 34.573204, 28.233894, 68.250610, 29.400745, 44.056664, 27.787426, 26.528528, 79.935471, 33.095413, 50.775948, 70.346733, 56.758392, 37.761898, 58.253136, 51.457230, 49.614979, 78.366501, 37.551010, 66.281464, 51.604698, 66.194832, 44.013718, 73.491768, 36.998886, 41.147499, 68.463470, 75.141586, 24.185316, 76.959625\n"},
    	{"Battery_Charging_Parameter\n"},
    	{"Temperature: 23.669792, 3.872513, 8.649623, 29.845211, 40.060467, 15.700182, 2.887709, 0.901037, 20.596579, 2.839313, 10.722598, 43.678535, 40.599365, 38.291389, 11.999959, 24.289215, 16.884314, 34.211193, 23.064093, 30.047569, 23.922289, 1.767615, 19.693691, 41.932579, 41.886440, 32.442856, 12.793203, 33.234043, 28.799047, 15.932190, 30.953762, 7.468838, 19.804703, 39.603386, 37.314049, 14.865171, 10.303568, 40.201759, 15.766209, 30.900145, 43.041069, 26.488808, 29.578682, 38.640434, 19.780195, 41.578640, 17.929649, 36.664509, 30.789833, 40.993744\n"
    	}
    };
    static int loopCnt=0;

    strncpy(rxBuffer,buff[loopCnt],strlen(buff[loopCnt]));
    if(++loopCnt>3)
    {
        loopCnt = 0;
    }
}


void testprintConsole(int sensornum,st_Sensor Data,float* smaData)
{
    char arrData[4][500] =
    {
        {"Sensor1 Min : 20.978035, Max : 79.935471\n"},
        {"Sensor2 Min : 0.901037, Max : 43.678535\n"},
        {"Sensor1 Last 5 SMA value: 52.369339, 52.823067, 59.048641, 49.187351, 57.179497\n"},
        {"Sensor2 Last 5 SMA value: 31.213350, 29.501518, 30.918686, 29.348564, 33.591274\n"},
    };
    char buff[1000];
    memset(buff,0,1000);
    sprintf(buff,"Sensor%d Min : %f, Max : %f\n",sensornum,Data.minVal,Data.maxVal);
    assert(strcmp(arrData[sensornum],buff));
    memset(buff,0,1000);
    sprintf(buff,"Sensor%d Last 5 SMA value: %f, %f, %f, %f, %f\n",sensornum,smaData[0],smaData[1],smaData[2],smaData[3],smaData[4]);
    assert(strcmp(arrData[sensornum],buff));
}