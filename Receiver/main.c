#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printMinMaxSMA.h"
#include "testCases.h"

int main(int argc, char *argv[])
{
    void (*funPtr[])() = {printMinMax_SMA,runTestcases};
    if(argc == 1)
    {
        printf("Usage: %s [-t]/[-r]\n[-t]: To run the unit test cases\n[-r]: To send the receiver data via console output\n", argv[0]);
        exit(0);
    }
    if(strcmp(argv[1],"-t") == 0)
    {
        (*funPtr[1])();
    }
    else if(strcmp(argv[1],"-r") == 0)
    {
        (*funPtr[0])();
    }
    return 0;
}