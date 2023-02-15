#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "config.h"
#include "send.h"
#include "file.h"
#include "test.h"

char test_buff[200];

void test_print(char* buff)
{
    strcpy(test_buff, buff);
}

void test_functions(void)
{
    test_sensorRead();
    test_sender();
}

void test_sensorRead(void)
{
    // The sensor values will be stored in files with "," separated.
    int sensor1[10];
    int count = 0;
    const char* file = "temperatureSensorTest.txt";

    count = readFile(file, sensor1);
    assert(count == 3);
    assert(sensor1[0] == 1);
    assert(sensor1[1] == 2);
    assert(sensor1[2] == 3);
}

void test_sender(void)
{
    memset(test_buff,0,200);
    strcpy((char*)sensorConfig[0], "temperatureSensorTest.txt");
    strcpy((char*)sensorConfig[1], "chargingSensorTest.txt");
    int val[] = {5,10,20};

    // Frame multiple sensor values in csv format
    getValueAsCsv(test_buff, val, 3);
    assert(strcmp(test_buff,"5, 10, 20\n") == 0);

    //test case to find the min value in an array function
    assert(getMinInAnArray(val,3) == 5);
    int val1[] = {30,30,30};
    assert(getMinInAnArray(val1,3) == 30);
    int val2[] = {17,7,27};
    assert(getMinInAnArray(val2,3) == 7);

    // Test case for the csv header
    sendSensorValue(&test_print);
    assert(strncmp(test_buff,HEADER,strlen(HEADER)) == 0);

    // Test the two sensor data output in csv format with 3 sample data
    memset(test_buff,0,200);
    sendSensorValue(&test_print);
    assert(strcmp(test_buff,"temperature, charging\n1, 20\n2, 21\n3, 23\n") == 0);
}
