#include "return_pressure_controller.h"
#include "msp430fr5969.h"


void stepper_motor_init()
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT

  // Configure GPIO
  P1DIR |= BIT0 | BIT3;
  P1OUT |= BIT0 | BIT3;

  // Disable the GPIO power-on default high-impedance mode to activate
  // previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;

  TA0CCTL0 = CCIE;                          // TACCR0 interrupt enabled
  TA0CCR0 = 50000;
  TA0CTL = TASSEL__ACLK | MC__CONTINOUS;   // SMCLK(1MHz), continuous mode

  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt
  __no_operation();                         // For debugger
}

// Timer0_A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer0_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  P1OUT ^= BIT0;
  TA0CCR0 += 50000;                         // Add Offset to TA0CCR0
}


void write_pwm_signal()
{
}


