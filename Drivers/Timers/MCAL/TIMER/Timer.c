/*
 * Timer.c
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */
#include "Timer.h"
#include "Timer_private.h"
#include "Timer_config.h"
#include "../DIO/DIO.h"
#include "../../Lib/Bit_Maths.h"

u8  G_u8Preload;
u16 G_u16Counter=0;
u32 G_u16OverFlowCount;

static void (*PvoidFuncCallBack[3])(void);

void MTIMER_voidInit_start(void)
{
	//pre scalar
	TIMER_TIMER0_TCCR0= (TIMER_TIMER0_TCCR0 & 0xf8) | (TIMER0_PRESCALER & 0x07);
}

void MTIMER_voidEnable(u8 A_u8TimerNumber)
{
	switch (A_u8TimerNumber)
		{
		case 0:
			//enable
			SET_BIT(TIMER_TIMER0_TIMSK,0);
			break;

		case 1:
			break;

		case 2:
			break;
		}
}

void MTIMER_voidDisable(u8 A_u8TimerNumber)
{
	switch (A_u8TimerNumber)
			{
			case 0:
				//disable
				CLR_BIT(TIMER_TIMER0_TIMSK,0);
				break;

			case 1:
				break;

			case 2:
				break;
			}
}

void MTIMER_voidSetPreLoad(u8 A_u8PreLoad)
{
	//preload
	TIMER_TIMER0_TCNT0= A_u8PreLoad;
}

void MTIMER_voidSetCounts(u32 A_u8Counts)
{
	G_u16OverFlowCount=A_u8Counts;
}

void MTimer_voidSetCallBack(u8 A_u8TimerNumber, void (*A_FuncPtr)(void))
{
	switch(A_u8TimerNumber)
		{
		case 0:
			PvoidFuncCallBack[0] = A_FuncPtr;
			break;

		case 1:
			PvoidFuncCallBack[1] = A_FuncPtr;
			break;

		case 2:
			PvoidFuncCallBack[2] = A_FuncPtr;
			break;
		}

}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{

	G_u16Counter++;

	if (G_u16Counter == G_u16OverFlowCount)
	{
		//initial state
		G_u16Counter = 0;
		TIMER_TIMER0_TCNT0 = 0;

		PvoidFuncCallBack[0]();
	}
}
