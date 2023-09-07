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

volatile u8  G_u8Preload;
static u16 G_u16Counter=0;
volatile u32 G_u16OverFlowCount;

static void (*PvoidFuncCallBack[3])(void);

void MTIMER_voidInit(u8 A_u8TimerNum)
{
	if (A_u8TimerNum==0){
		if (TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_NORMAL){
			CLR_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM00);
			CLR_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM01);
		}
		else if(	TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_PWM){
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM00);
			CLR_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM01);
		}

		else if(	TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_CTC){
			CLR_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM00);
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM01);
		}
		else if(	TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_FASTPWM){
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM00);
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_WGM01);

			if (TIMER_OutputCompareMODE_FastPWM ==TIMER_OutputCompareMODE_FastPWM_CLEAR){
			CLR_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_COM00);
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_COM01);
			}
			else if( TIMER_OutputCompareMODE_FastPWM ==TIMER_OutputCompareMODE_FastPWM_SET){
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_COM00);
			SET_BIT(TIMER_TCCR0,TIMER_TIMER0_TCCR0_COM01);
			}
		}
}
	else if (A_u8TimerNum==2)
	{
		        if (TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_NORMAL){
					CLR_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM20);
					CLR_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM21);
				}
				else if(	TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_PWM){
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM20);
					CLR_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM21);
				}

				else if(	TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_CTC){
					CLR_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM20);
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM21);
				}
				else if(	TIMER_WaveGenerationMODE == TIMER_WaveGenerationMODE_FASTPWM){
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM20);
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_WGM21);

					if (TIMER_OutputCompareMODE_FastPWM ==TIMER_OutputCompareMODE_FastPWM_CLEAR){
					CLR_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_COM20);
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_COM21);
					}
					else if( TIMER_OutputCompareMODE_FastPWM ==TIMER_OutputCompareMODE_FastPWM_SET){
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_COM20);
					SET_BIT(TIMER_TCCR2,TIMER_TIMER2_TCCR2_COM21);
					}
				}
	}
}




void MTIMER_voidStart(u8 A_u8TimerNum)
{
	//pre scalar
	switch(A_u8TimerNum)
	{
	case 0:
	         TIMER_TCCR0= (TIMER_TCCR0 & 0xf8) | (TIMER_PRESCALER & 0x07);
	         break;
	case 2:
			 TIMER_TCCR2= (TIMER_TCCR2 & 0xf8) | (TIMER_PRESCALER & 0x07);
			 break;
	}
}

void MTIMR_voidSetCompareMatch(u8 A_u8TimerNum,u8 A_u8Value)
{
	switch(A_u8TimerNum){
	case TIMER_TIMER0:
		TIMER_OCR0=A_u8Value;
		break;

	case TIMER_TIMER2:
		TIMER_OCR2=A_u8Value;
		break;
	}
}
void MTIMER_voidEnable(u8 A_u8TimerNumber)
{
	switch (A_u8TimerNumber)
		{
		case 0:
			//enable
			SET_BIT(TIMER_TIMSK,0);
			SET_BIT(TIMER_TIMSK,1);
			break;

		case 1:
			break;

		case 2:
			SET_BIT(TIMER_TIMSK,6);
			SET_BIT(TIMER_TIMSK,7);
			break;
		}
}

void MTIMER_voidDisable(u8 A_u8TimerNumber)
{
	switch (A_u8TimerNumber)
			{
			case 0:
				//disable
				CLR_BIT(TIMER_TIMSK,0);
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
	TIMER_TCNT0= A_u8PreLoad;
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

//void __vector_11 (void) __attribute__((signal));
//void __vector_11 (void)
//{
//
//	G_u16Counter++;
//
//	if (G_u16Counter == G_u16OverFlowCount)
//	{
//		//initial state
//		G_u16Counter = 0;
//		TIMER_TCNT0 = 0;
//
//		PvoidFuncCallBack[0]();
//	}
//}
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{

	PvoidFuncCallBack[0]();
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{

	PvoidFuncCallBack[2]();
}
