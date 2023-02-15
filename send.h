//function to send the sensor value
void sendSensorValue(void (*fp_sender)(char*));

//function to ge the values in csv format
void getValueAsCsv(char* buffer,int* sensorVal, int count);

//function to get the minimum value in an array
int getMinInAnArray(int* arr, int cnt);
