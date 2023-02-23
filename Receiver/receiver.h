#define MAX_RECEIVE_BYTE        2000
#define MAX_SENSOR_OUT_READ     20
#define ARRAY_INDEX0            0
#define ARRAY_INDEX1            1
void getReceivedSensorVal(char sensor1Buff[][MAX_RECEIVE_BYTE]);
void Receiver(char *rxBuffer,char sensor1Buff[][MAX_RECEIVE_BYTE]);