/*
 * MTIMERS_Config.h
 *
 *  Created on: 28 Aug 2023
 *      Author: ehab
 */

#ifndef MCAL_TIMERS_MTIMERS_CONFIG_H_
#define MCAL_TIMERS_MTIMERS_CONFIG_H_

/************************** TIMER_0_Configurations *****************************/

#define DISABLE   0
#define ENABLE    1

#define TIMER0_ENABLE    ENABLE
#define TIMER1_ENABLE    ENABLE
#define TIMER2_ENABLE    DISABLE


#define TIMER_OVF  				1
#define TIMER_CTC      			2
#define TIMER_FASTPWM  			3
#define TIMER_PHASECORRECETPWM  4

#define TIMER1_MODE TIMER_FASTPWM


#define TIMER_PRE_1  		0x01
#define TIMER_PRE_8  		0x02
#define TIMER_PRE_64  		0x03
#define TIMER_PRE_256  		0x04
#define TIMER_PRE_1024  	0x05

#define TIMER1_PRESCALLER	TIMER_PRE_8


#endif /* MCAL_TIMERS_MTIMERS_CONFIG_H_ */
