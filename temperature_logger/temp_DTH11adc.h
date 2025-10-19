#ifndef TEMP_DTH11ADC_H_
#define TEMP_DTH11ADC_H_

// typedef struct dataframe{
//   unsigned short int humidity_int;
//   unsigned short int humidity_decimal;
//   unsigned short int temp_int;
//   unsigned short int temp_decimal;
//   unsigned short int checksum;
// }DTHSensor_frameformat;

unsigned short int dataframe[5];

void DHT11_Init(void);
float DHT11_ReadTemperature(void);

#endif