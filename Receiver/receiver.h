#define MAX_RECEIVE_BYTE        5000
#define MAX_SENSOR_OUT_READ     20
#define ARRAY_INDEX0            0
#define ARRAY_INDEX1            1
void readfromConsole(char* rxBuffer);
void Receiver(char *rxBuffer,char sensor1Buff[][MAX_RECEIVE_BYTE]);