/*
 * attiny13_millis.h
 *
 * Created: 01.06.2017 15:20:26
 *  Author: igr
 *
 *
 *
 *
 *	unsigned long millis(int state) - return time iin ms from millis(start).
 *
 *							 state:
 *									on		- turn on TC0
 *									off		- turn off TC0
 *									start	- start write time
 *									stop	- stop write time, after stop millis(get) return last time value
 *									get		- return time from start
 *
 *
 */ 


#ifndef ATTINY13_MILLIS_H_
#define ATTINY13_MILLIS_H_

	#define get		100
	
	#define start	11
	#define stop	10
	
	#define on		1
	#define off		0
	
	unsigned long millis(int state);


#endif /* ATTINY13_MILLIS_H_ */