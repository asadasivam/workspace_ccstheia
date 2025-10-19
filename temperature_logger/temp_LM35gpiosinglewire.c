#include <stdint.h>
#include "temp_LM35gpiosinglewire.h"
#include <msp430fr5969.h>

/* analog read */
#define VREF 3.3
#define ADC_RES 4096.0

// Example: ADC channel where LM35 is connected
#define LM35_ADC_CHANNEL  1

void LM35_Init(void)
{
    // Configure ADC pin, reference voltage, sampling time
    
}

float LM35_ReadTemperature(void)
{
    uint16_t adc_value = ADC_Read(LM35_ADC_CHANNEL);
    float voltage = (adc_value * VREF) / ADC_RES;  // Convert ADC to voltage
    float temp_c = voltage / 0.01;                 // 10 mV per °C
    return temp_c;
}