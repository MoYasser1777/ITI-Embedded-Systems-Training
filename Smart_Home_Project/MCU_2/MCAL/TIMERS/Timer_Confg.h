/*
 * Timer_Confg.h
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMER_CONFG_H_
#define MCAL_TIMERS_TIMER_CONFG_H_

/*CLOCK_OPTIONS :
 	 * Clock_NOPRS
 	 * Clock_PRS8
 	 * Clock_PRS64
 	 * Clock_PRS256
 	 * Clock_PRS1024
 	 * Clock_onfalling
 	 * Clock_onrising
 */
#define TIMER0_PRS_Clock Clock_PRS64

#define TIMER1_PRS_Clock Clock_PRS64

#define TIMER2_PRS_Clock Clock_PRS256

/*TIMERS MODE
 * TIMER_OVF
 * TIMER_CTC
 * TIMER_FASTPWM
 * TIMER_PHASECORRECT
 */
#define TIMER0_MODE TIMER_CTC

#define TIMER1_MODE TIMER_FASTPWM

#define TIMER2_MODE TIMER_FASTPWM


#define ICR_Value 2499

#endif /* MCAL_TIMERS_TIMER_CONFG_H_ */
