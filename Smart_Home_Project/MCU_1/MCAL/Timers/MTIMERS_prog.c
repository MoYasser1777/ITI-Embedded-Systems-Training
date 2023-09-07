/*
 * MTIMERS_prog.c
 *
 *  Created on: 28 Aug 2023
 *      Author: ehab
 */

#include "../../LIB/Memory_Map.h"
#include "../../LIB/STD_Macros.h"
#include "../../LIB/STD_Types.h"

#include "MTIMERS_Init.h"
#include "MTIMERS_priv.h"
#include "MTIMERS_Config.h"

/************************** TIMER_1 ***********************************/

void MTIMER1_voidInitFastPwm()
{
	/* set OC1A as output pin */
	SET_BIT(DDRD,5);

	/* select fast PWM mode with TOP:ICR1*/
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

	/* load a value in ICR1 */
	ICR1=19999;

	/* select timer TIMER1_PRESCALLER = 8*/
	TCCR1B= (TCCR1B &0b11111000) | TIMER1_PRESCALLER ;

	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);

	// initialize counter
	TCNT1 = 0 ;
}

void MTIMER1_voidSetPinACompareMatch(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value ;
}
