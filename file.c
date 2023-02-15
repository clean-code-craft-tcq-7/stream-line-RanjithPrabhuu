#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "file.h"

int read(const char* filePath, int* data)
{
    FILE* file;
    long file_size;
    char * buf;
    char * strtok_str;
    int count = 0;

    file = fopen ( filePath , "r+" );
    fseek (file , 0 , SEEK_END);
    file_size = ftell (file);
    rewind (file);

    buf = (char*) malloc (sizeof(char)*file_size);

    fread(buf,1,file_size,file);

    strtok_str = strtok(buf, ",");
    while (strtok_str != NULL)
    {
        *data = atoi(strtok_str);
        data++;
        count++;
        strtok_str = strtok (NULL, ",");
    }

    fclose (file);

    return count;
}

void printToConsole(char* buff)
{
    write(STDOUT_FILENO, buff, strlen(buff));
}
