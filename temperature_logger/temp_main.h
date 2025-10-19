#ifndef TEMP_MAIN_H_
#define TEMP_MAIN_H_

#include "temp_DTH11adc.h"
#include "temp_LM35gpiosinglewire.h"

typedef struct {
    void    (*adc_init)(void);
    float   (*adc_read)(void);
}adc_interface;

adc_interface adcDTH11 = {
    .adc_init = DHT11_Init,
    .adc_read = DHT11_ReadTemperature
};

adc_interface adcLM35 = {
    .adc_init = LM35_Init,
    .adc_read = LM35_ReadTemperature
};

void ADC_Init(void);
int ADC_Read(void);

#endif