/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//******************************************************************************
//  MSP430FR59xx Demo - ADC12B, Sample A1, AVcc Ref, Set P1.0 if A1 > 0.5*AVcc
//
//   Description: A single sample is made on A1 with reference to AVcc.
//   Software sets ADC12BSC to start sample and conversion - ADC12BSC
//   automatically cleared at EOC. ADC12B internal oscillator times sample (16x)
//   and conversion. In Mainloop MSP430 waits in LPM0 to save power until ADC12B
//   conversion complete, ADC12_B_ISR will force exit from LPM0 in Mainloop on
//   reti. If A0 > 0.5*AVcc, P1.0 set, else reset. The full, correct handling of
//   and ADC12B interrupt is shown as well.
//
//
//                MSP430FR5969
//             -------------------------
//         /|\|                              XIN|-
//          | |                                 |
//          --|RST                          XOUT|-
//            |                                 |   
//        >---|P1.1/A1(LM35)                P1.0|-->LED
//        >---|P1.1/Single wire (DTH11)
//
//******************************************************************************
#include "adc_driver.h"
#include "temp_main.h"
#include <stdio.h>

unsigned int read_voltage;  //  initial pin status to be checked

void main()
{
  //  when sensors connected, mcu has to detect which one being connected to the machine
  P1DIR &= ~BIT1;
  P1SEL0 |= BIT1;
  P1SEL1 |= BIT1; //alternate function : analog read

  //  initially do the safe voltage checks
  //  check if meets following constraints
  //  1. not connected
  //  2. connected to DTH11 sensor or LM35 sensor
  ADC_Init();
  
  read_voltage = ADC_Read();
  if(read_voltage > 3.3)
  {
    //  safely deactivate lines on LM35 sensor 
    ADC12CTL0 &= ~(ADC12ON | ADC12ENC);
    //  activate DTH11 sensor
    printf("activating DTH11 sensor");

  }
  else {
    //  safely deactivate lines on DTH1 sensor 
    //  activate LM35 sensor
    printf("activating LM35 sensor");
  }

  while(1){
    __bis_SR_register(LPM3_bits | GIE);
  }
}
void ADC_Init(void)
{
    ADC12CTL0 = ADC12SHT0_2 | ADC12ON;     // 16 x ADC clock cycles, ADC on
    ADC12CTL1 = ADC12SHP;                  // Use sampling timer
    ADC12MCTL0 = ADC12INCH_1;              // Input channel A1
    ADC12CTL0 |= ADC12ENC;                 // Enable conversion
}

int ADC_Read(void)
{
  // measure continuous samples of max. 20 and average
    int increment = 0, average = -1;
    //  sample rate 
    int data[100] = {0};
    ADC12CTL0 |= ADC12SC;                  // Start conversion
    while(increment < 100)
    {
      while (ADC12CTL1 & ADC12BUSY);         // Wait for conversion complete
      data[increment++] = ADC12MEM0 ;
      average += data[increment];
    }
    if(average != -1)
    {
      return (average/increment);
    }
    else {
      return -1;
    }
}