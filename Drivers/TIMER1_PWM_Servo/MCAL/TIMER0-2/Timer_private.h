/*
 * Timer_private.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#include "../../Lib/STD_Types.h"



#define TIMER_TIMSK   *((volatile u8*) 0x59)

#define	TIMER_TCNT0   *((volatile u8*) 0x52)
#define TIMER_TCCR0   *((volatile u8*) 0x53)
#define TIMER_OCR0    *((volatile u8*) 0x5c)

#define	TIMER_TCNT2   *((volatile u8*) 0x44)
#define TIMER_TCCR2   *((volatile u8*) 0x45)
#define TIMER_OCR2    *((volatile u8*) 0x43)

#define TIMER_TIMER0 0
#define TIMER_TIMER2 2

#define TIMER_TIMER0_TCCR0_COM00 4
#define TIMER_TIMER0_TCCR0_COM01 5
#define TIMER_TIMER0_TCCR0_WGM00 6
#define TIMER_TIMER0_TCCR0_WGM01 3

#define TIMER_TIMER2_TCCR2_COM20 4
#define TIMER_TIMER2_TCCR2_COM21 5
#define TIMER_TIMER2_TCCR2_WGM20 6
#define TIMER_TIMER2_TCCR2_WGM21 3

// Pre-scaler options
#define TIMER_NO_CLOCK_SOURCE   (u8)0x00
#define TIMER_PRESCALER_8       (u8)0x02
#define TIMER_PRESCALER_64      (u8)0x03
#define TIMER_NO_PRESCALING	    (u8)0x01
#define TIMER_PRESCALER_256     (u8)0x04
#define TIMER_PRESCALER_1024    (u8)0x05
#define TIMER_EXTCLK_FALLING    (u8)0x06
#define TIMER_EXTCLK_RISING     (u8)0x07

// Modes of operation
#define TIMER_WaveGenerationMODE_NORMAL	        (u8)1
#define TIMER_WaveGenerationMODE_PWM		    (u8)2
#define TIMER_WaveGenerationMODE_CTC		    (u8)3
#define TIMER_WaveGenerationMODE_FASTPWM	    (u8)4


#define TIMER_OutputCompareMODE_NonPWM_NORMAL   (u8)1
#define TIMER_OutputCompareMODE_NonPWM_TOGGLE   (u8)2
#define TIMER_OutputCompareMODE_NonPWM_CLEAR    (u8)3
#define TIMER_OutputCompareMODE_NonPWM_SET      (u8)4

#define TIMER_OutputCompareMODE_FastPWM_NORMAL   (u8)1
#define TIMER_OutputCompareMODE_FastPWM_CLEAR    (u8)2
#define TIMER_OutputCompareMODE_FastPWM_SET      (u8)3


#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
