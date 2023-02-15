#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "send.h"
#include "file.h"
#include "test_cases.h"

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("Usage: %s [-t]/[-r]\n[-t]: To run the unit test cases\n[-r]: To send the sensors data via console output\n", argv[0]);
        exit(0);
    }

    if(strcmp(argv[1],"-t") == 0)
    {
        test_functions();
    }
    else if(strcmp(argv[1],"-r") == 0)
    {
        sendSensorValue(&printToConsole);
    }

    return 0;
}
