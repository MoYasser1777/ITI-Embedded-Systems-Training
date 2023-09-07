/*
 * Timer_config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

/* Pre scaler choice                    */
/* Options : TIMER_NO_CLOCK_SOURCE            */
/*   	     TIMER_NO_PRESCALING		      */
/*     		 TIMER_PRESCALER_8                */
/*   		 TIMER_PRESCALER_64               */
/*  		 TIMER_PRESCALER_256              */
/*     		 TIMER_PRESCALER_1024             */
/*     		 TIMER_EXTCLK_FALLING             */
/*           TIMER_EXTCLK_RISING              */
#define TIMER_PRESCALER		TIMER_PRESCALER_64

/* Modes of operation                    */
/* Options : TIMER_TIMER0_MODE_NORMAL          */
/*           TIMER_TIMER0_MODE_PWM             */
/*           TIMER_TIMER0_MODE_CTC             */
/*           TIMER_TIMER0_MODE_FASTPWM         */
#define TIMER_WaveGenerationMODE			TIMER_WaveGenerationMODE_FASTPWM
#define TIMER_OutputCompareMODE_FastPWM 	TIMER_OutputCompareMODE_FastPWM_CLEAR //non-inverting

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
