#ifndef TEMP_LM35GPIOSINGLEWIRE_H_
#define TEMP_LM35GPIOSINGLEWIRE_H_
void LM35_Init(void);
float LM35_ReadTemperature(void);

//use cases
/*
1. 3.3V
2. 5V do not diirectly sample 5V, it will damage, use protection circuits
//we need voltage scaling circuits for higher voltages
3. 12V
4. 25V
5. 110V (DC signal)
6. 220V (AC signal)
7. unknown voltage or current or resistance, we cannot determine actual value
*/

/*
concept : *C to output voltage - convert analog voltage into temperature
LM35 : 10mV per degree Celsius

negative temperature values : 

*/
int ADC_Read_val(int);
#endif


