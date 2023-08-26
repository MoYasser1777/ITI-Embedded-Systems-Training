/*
 * Timer_private.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define	TIMER_TIMER0_TCNT0   *((volatile u8*) 0x52)
#define TIMER_TIMER0_TIMSK   *((volatile u8*) 0x59)
#define TIMER_TIMER0_TCCR0   *((volatile u8*) 0x53)

// Pre-scaler options for timer0
#define TIMER_TIMER0_NO_CLOCK_SOURCE   (u8)0x00
#define TIMER_TIMER0_PRESCALER_8       (u8)0x02
#define TIMER_TIMER0_PRESCALER_64      (u8)0x03
#define TIMER_TIMER0_NO_PRESCALING	   (u8)0x01
#define TIMER_TIMER0_PRESCALER_256     (u8)0x04
#define TIMER_TIMER0_PRESCALER_1024    (u8)0x05
#define TIMER_TIMER0_EXTCLK_FALLING    (u8)0x06
#define TIMER_TIMER0_EXTCLK_RISING     (u8)0x07

// Mode of operation of timer0
#define TIMER_TIMER0_MODE_NORMAL	    (u8)1
#define TIMER_TIMER0_MODE_PWM		    (u8)2
#define TIMER_TIMER0_MODE_CTC		    (u8)3
#define TIMER_TIMER0_MODE_FASTPWM	    (u8)4




#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
