/*
 * TIMER1_PWM.c
 *
 *  Created on: Aug 28, 2023
 *      Author: lenovo
 */

#include "TIMER1_PWM.h"
#include "TIMER1_PWM_private.h"

void MTIMR1_voidTimer1Init()
{
	/* Select Mode : fast pwm */
	CLR_BIT(TCCR1A , TCCR1A_WGM10);
	SET_BIT(TCCR1A , TCCR1A_WGM11);
	SET_BIT(TCCR1B , TCCR1B_WGM12);
	SET_BIT(TCCR1B , TCCR1B_WGM13);

	/* Choose non inverting mode */
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	CLR_BIT(TCCR1A , TCCR1A_COM1A0);

	/* Choose Prescaler to 8
	 * Every tick will take 1 us */
	CLR_BIT(TCCR1B , TCCR1B_CS10);
	SET_BIT(TCCR1B , TCCR1B_CS11);
	CLR_BIT(TCCR1B , TCCR1B_CS12);
}

void MTIMR1_voidSetICR(u16 A_u16value)
{
	ICR1 =A_u16value;
}

void MTIMR1_voidTimer1SetCompMatchA(u16 A_u16value)
{
	OCR1A = A_u16value;
}

void MTIMR1_voidTimer1SetCompMatchB(u16 A_u16value)
{
	OCR1B = A_u16value;
}
