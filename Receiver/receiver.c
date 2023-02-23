#include <stdio.h>
#include <string.h>
#include "receiver.h"

void readfromConsole(char* rxBuffer)
{    
    fgets(rxBuffer,MAX_RECEIVE_BYTE,stdin);
}