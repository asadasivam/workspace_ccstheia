#include <stdio.h>
#include "msp430fr5969.h"
int ADC_Read_Thermistor(void)
{
    ADC12CTL0 |= ADC12SC;                     // Start conversion
    while (ADC12CTL1 & ADC12BUSY);            // Wait until conversion is complete
    return ADC12MEM0;                         // Return conversion result
}