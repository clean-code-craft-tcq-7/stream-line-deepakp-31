#define MAX_RECEIVE_BYTE        2000
#define MAX_SENSOR_OUT_READ     20
#define ARRAY_INDEX0            0
#define ARRAY_INDEX1            1
void Receiver(char *rxBuffer,char* sensor1Buff,char* sensor2Buff);
void getReceivedSensorVal(char* sensor1Buff,char* sensor2Buff);