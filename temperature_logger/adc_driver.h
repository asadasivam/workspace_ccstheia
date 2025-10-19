#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H

#include <msp430fr5969.h>

typedef volatile unsigned int ut16;
typedef struct adc_entity{
    ut16 ADC12CTL0;
    ut16 ADC12CTL1;
    ut16 ADC12CTL2;
    ut16 ADC12CTL3;
    ut16 ADC12LO;
    ut16 ADC12HI;
    ut16 ADC12IFGR0;
    ut16 ADC12IFGR1;
    ut16 ADC12IFGR2;
    ut16 ADC12IER0;
    ut16 ADC12IER1;
    ut16 ADC12IER2;
    ut16 ADC12IV;
    ut16 ADC12MCTL0;
    ut16 ADC12MCTL1;
    ut16 ADC12MCTL2;
    ut16 ADC12MCTL3;
    ut16 ADC12MCTL4;
    ut16 ADC12MCTL5;
    ut16 ADC12MCTL6;
    ut16 ADC12MCTL7;
    ut16 ADC12MCTL8;
    ut16 ADC12MCTL9;
    ut16 ADC12MCTL10;
    ut16 ADC12MCTL11;
    ut16 ADC12MCTL12;
    ut16 ADC12MCTL13;
    ut16 ADC12MCTL14;
    ut16 ADC12MCTL15;
    ut16 ADC12MCTL16;
    ut16 ADC12MCTL17;
    ut16 ADC12MCTL18;
    ut16 ADC12MCTL19;
    ut16 ADC12MCTL20;
    ut16 ADC12MCTL21;
    ut16 ADC12MCTL22;
    ut16 ADC12MCTL23;
    ut16 ADC12MCTL24;
    ut16 ADC12MCTL25;
    ut16 ADC12MCTL26;
    ut16 ADC12MCTL27;
    ut16 ADC12MCTL28;
    ut16 ADC12MCTL29;
    ut16 ADC12MCTL30;
    ut16 ADC12MCTL31;
    ut16 ADC12MEM0;
    ut16 ADC12MEM1;
    ut16 ADC12MEM2;
    ut16 ADC12MEM3;
    ut16 ADC12MEM4;
    ut16 ADC12MEM5;
    ut16 ADC12MEM6;
    ut16 ADC12MEM7;
    ut16 ADC12MEM8;
    ut16 ADC12MEM9;
    ut16 ADC12MEM10;
    ut16 ADC12MEM11;
    ut16 ADC12MEM12;
    ut16 ADC12MEM13;
    ut16 ADC12MEM14;
    ut16 ADC12MEM15;
    ut16 ADC12MEM16;
    ut16 ADC12MEM17;
    ut16 ADC12MEM18;
    ut16 ADC12MEM19;
    ut16 ADC12MEM20;
    ut16 ADC12MEM21;
    ut16 ADC12MEM22;
    ut16 ADC12MEM23;
    ut16 ADC12MEM24;
    ut16 ADC12MEM25;
    ut16 ADC12MEM26;
    ut16 ADC12MEM27;
    ut16 ADC12MEM28;
    ut16 ADC12MEM29;
    ut16 ADC12MEM30;
    ut16 ADC12MEM31;
}adc_offset_registers;

//assign a base address to this struct so that offset registers can be accessed
#define adc_base_address ((adc_offset_registers*)ADC12_B_BASE)

#endif



