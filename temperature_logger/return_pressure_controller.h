#ifndef RETURN_PRESSURE_CONTROLLER_H_
#define RETURN_PRESSURE_CONTROLLER_H_

/*
stepper motor interface
1. find the rpm of rotation and 
2. make it to rotate cw, cc, centre
3. give a pressure to the tube attached.

connections - gnd, pwr, gpio(P1.3) 

Standard servos require a 50 Hz (20 ms period) PWM signal, 
with pulse widths typically varying between 1 ms (0 degrees)
and 2 ms (180 degrees).
*/
void write_pwm_signal();
#endif

