/*
 * atmega_adc.h
 *
 * Created: 19.04.2017 11:27:49
 *  Author: igr
 */ 


#ifndef ATMEGA_ADC_H_
#define ATMEGA_ADC_H_

	void			atmega_adc_init();
	
	unsigned int	adc_get_value(unsigned char channel);	//channel - numbers of analog pins

#endif /* ATMEGA_ADC_H_ */