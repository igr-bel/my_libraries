/*
 * attiny13_millis.c
 *
 * Created: 01.06.2017 15:20:40
 *  Author: igr
 */ 

#ifndef ATTINY13_MILLIS_C_
#define ATTINY13_MILLIS_C_


	#include "prj.h"

	unsigned long counter_ms = 0;
	unsigned long counter_tics = 0;
	unsigned long storage_ms = 0;		//if counter stop

//	char stop_flag = 0;

	ISR( TIMER0_OVF_vect )
	{
		counter_tics++;
	}//ISR

	unsigned long millis(int state)
	{
		switch (state)
		{
			case get:
				return (counter_tics / 4);
			break;
/*
			case start:
				TCNT0 = 0x00;
				counter_tics = 0;
				stop_flag = 0;
				return 0;
			break;
*/
/*
			case stop:
				storage_ms = counter_tics / 4;
				stop_flag = 1;
				return 0;
			break;
*/
			case on:
				SREG |= (1<<7);			//global interrupt enable
				TIMSK |= (1<<TOIE0);	//interrupt overflow TC0 enable
				TCCR0B |= (1<<CS01);	//prescaler 8
				TCNT0 = 0x00;
//				stop_flag = 0;
				counter_tics = 0;
				return 0;
			break;
/*
			case off:
				TIMSK &= ~(1<<TOIE0);
				stop_flag = 1;
				counter_tics = 0;
				return 0;
			break;
*/
			default :
				return 1;
			break;

		}//switch()
	}//milis()

#endif /* ATTINY13_MILLIS_C_ */
