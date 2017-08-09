/*
 * atmega_adc.c
 *
 * Created: 19.04.2017 11:27:01
 *  Author: igr
 */ 

#include "prj.h"

//--------------------------------------------------------------------------------------------------------------------------
void atmega_adc_init()
{
	//clock divider = 64 --> fadc = 125 kHz
	
	ADCSRA = 0xC6;		//	|ADEN|ADSC|ADFR|ADIF|ADIE|ADPS2|ADPS1|ADPS0|
						//	| 1  | 1  | 0  | 0  | 0  |  1  |  1  |  0  |
}//atmega_adc_init

//--------------------------------------------------------------------------------------------------------------------------
unsigned int adc_get_value(unsigned char channel)
{
	ADMUX = ( channel | (ADMUX & 0xF0) );	// REFS1:REFS0	0:0	/AREF
											// ADLAR(bit 5) 0	/ADCH <- 2 high bit
	_delay_us(15);
	ADCSRA |= 0x40;							// ADSC = 1
	while ( 0 == (ADCSRA & 0x10) );			// while (ADIF == 0)
	return ( (unsigned int) (ADCL + (ADCH<<8)) );
	
}//adc_get_value()
//--------------------------------------------------------------------------------------------------------------------------
