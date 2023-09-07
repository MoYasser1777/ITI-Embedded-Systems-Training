/*
 * Timer_Prv.h
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMER_PRV_H_
#define MCAL_TIMERS_TIMER_PRV_H_

#define TIMER0 			0
#define TIMER1			1
#define TIMER2			2

/************		TIMER0		*******************/

#define TCCR0		*((volatile u8*)(0x53))
#define FOCO			7
#define WGM00			6
#define WGM01			3 // NORMAL 00 ,PHASE PWM 01 , CTC 10 , FAST PWM 11
#define COM01			5
#define COM00			4

#define TCNT0		*((volatile u8*)(0x52))
#define OCR0		*((volatile u8*)(0x5C))

#define TIMSK		*((volatile u8*)(0x59))
#define OCIE0			1
#define TOIE0			0

#define TIFR		*((volatile u8*)(0x58))
#define OCF0			1
#define TOV0			0
		/******************************************************/

/************		TIMER1		*******************/

#define TCCR1A		*((volatile u8*)(0X4F))
#define COM1A1			7
#define COM1A0			6
#define COM1B1			5
#define COM1B0			4
#define FOC1A			3
#define FOC1B			2
#define WGM11			1
#define WGM10			0

#define TCCR1B		*((volatile u8*)(0X4E))
#define ICNC1			7
#define ICES1			6
#define WGM13			4
#define WGM12			3

#define TCNT1H		*((volatile u8*)(0X4D))
#define TCNT1L		*((volatile u8*)(0X4C))
#define OCR1AH		*((volatile u8*)(0X4B))
#define OCR1AL		*((volatile u8*)(0X4A))
#define OCR1BH		*((volatile u8*)(0X49))
#define OCR1BL		*((volatile u8*)(0X48))
#define ICR1H		*((volatile u8*)(0X47))
#define ICR1L		*((volatile u16*)(0X46))

#define TIMSK		*((volatile u8*)(0x59))
#define TICIE1			5
#define OCIE1A			4
#define OCIE1B			3
#define TOIE1			2

#define TIFR		*((volatile u8*)(0x58))
#define ICF1			5
#define OCF1A			4
#define OCF1B			3
#define TOV1			2
		/******************************************************/

/************		TIMER2		*******************/

#define TCCR2		*((volatile u8*)(0X45))
#define FOC2				7
#define WGM20				6
#define WGM21				3
#define COM21				5
#define COM20				4

#define TCNT2		*((volatile u8*)(0x44))
#define OCR2		*((volatile u8*)(0x43))

#define TIMSK		*((volatile u8*)(0x59))
#define OCIE2				7
#define TOIE2				6

#define TIFR		*((volatile u8*)(0x58))
#define OCF2				7
#define TOV2				6

// TIMERS MODES0

#define TIMER_OVF			1
#define TIMER_CTC			2
#define TIMER_FASTPWM		3
#define TIMER_PHASECORRECT	4

// TIMERS Clocks

#define Clock_NOPRS 		0b001
#define Clock_PRS8 			0b010
#define Clock_PRS64 		0b011
#define Clock_PRS256		0b100
#define Clock_PRS1024 		0b101
#define Clock_onfalling 	0b110
#define Clock_onrising	 	0b111

#endif /* MCAL_TIMERS_TIMER_PRV_H_ */
