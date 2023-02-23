#define MAX_SENSOR_NAME_BYTE        100
#define MAX_SENSOR                  2
#define MAX_GET_SENSOR_VALUE        100

typedef struct 
{
    int number;
    int readingCnt;
    float minVal;
    float maxVal;
    float value[100];
}st_Sensor;

void getSensorRxValues(char* rxSensorBuf,st_Sensor* sensorReadingArr);
int checkSensorID(char* readName);
void getSensorName(char* rxBuff,char* name);