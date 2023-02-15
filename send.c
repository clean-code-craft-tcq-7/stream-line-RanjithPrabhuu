#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include "send.h"
#include "file.h"

void sendSensorValue(void (*fp_sender)(char*))
{
    char buffer[500];
    char sensorTxt[50];
    int idx = 0;
    int arrayIdx;
    int minSampleCnt = 0;
    int samplesCnt[MAX_SENSOR];
    int sampleValArr[MAX_SENSOR];
    int sensorValue[MAX_SENSOR][50];

    sprintf(buffer, "%s\n",HEADER);

    while(idx < MAX_SENSOR)
    {
        samplesCnt[index] = read(sensorConfig[idx], &sensorValue[idx][0]);
        idx++;
    }
    minSampleCnt = getMinInAnArray(samplesCnt, MAX_SENSOR);

    for(idx = 0; idx < minSampleCnt; idx++)
    {
        arrayIdx = 0;
        while(arrayIdx < MAX_SENSOR)
        {
            sampleValArr[arrayIdx] = sensorValue[arrayIdx][idx];
            arrayIdx++;
        }
        memset(sensTxt, 0, 50);
        getValueAsCsv(sensTxt, sampleValArr, MAX_SENSOR);
        strcat(buffer,sensTxt);
    }

    fp_sender(buffer);
}


void getValueAsCsv(char* buffer,int* sensorVal, int count)
{
    int index = 0;
    char buff[10];

    while(index < count)
    {
        sprintf(buff,"%d, ",sensorVal[index]);
        strcat(buffer, buff);
        index++;
    }
    buffer[strlen(buffer) - 2] = '\n';
    buffer[strlen(buffer) - 1] = '\0';
}

int getMinInAnArray(int* arr, int cnt)
{
    int idx;
    int min = arr[0];

    for(idx = 1; idx < cnt; idx++)
    {
        if(arr[idx] < min)
        {
            min = arr[idx];
        }
    }

    return min;
}
