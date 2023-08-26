/*
 * Timer_config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

/* Pre scaler choice                    */
/* Options : TIMER0_NO_CLOCK_SOURCE            */
/*   	     TIMER0_NO_PRESCALING		      */
/*     		 TIMER0_PRESCALER_8                */
/*   		 TIMER0_PRESCALER_64               */
/*  		 TIMER0_PRESCALER_256              */
/*     		 TIMER0_PRESCALER_1024             */
/*     		 TIMER0_EXTCLK_FALLING             */
/*           TIMER0_EXTCLK_RISING              */
#define TIMER0_PRESCALER		TIMER_TIMER0_PRESCALER_64

/* Mode of operation                    */
/* Options : TIMER_TIMER0_MODE_NORMAL          */
/*           TIMER_TIMER0_MODE_PWM             */
/*           TIMER_TIMER0_MODE_CTC             */
/*           TIMER_TIMER0_MODE_FASTPWM         */
#define TIMER_TIMER0_MODE		TIMER_TIMER0_MODE_NORMAL

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
