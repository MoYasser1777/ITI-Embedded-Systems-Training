/*
 * TIMER_PROG.c
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Init.h"
#include "Timer_Prv.h"
#include "Timer_Confg.h"

volatile u32 G_IntervalCounter = 0;


static void(*TIMER0_OVF)(void);
static void(*TIMER0_CTC)(void);

static void(*TIMER1_OVF)(void);
static void(*TIMER1_CTC)(void);
//static void(*TIMER1_ICR)(void);

static void(*TIMER2_OVF)(void);
static void(*TIMER2_CTC)(void);

void MTIMERS_voidTimer_Init(u8 A_U8TimerID)
{
	switch(A_U8TimerID)
	{
		case TIMER0 :
			/* 	Interrupt Enable */
			/* Select Mode */
			#if TIMER0_MODE == TIMER_OVF
				Clr_Bit(TCCR0 , WGM00);
				Clr_Bit(TCCR0 , WGM01);
				// For Normal Operation
				Clr_Bit(TCCR0 , COM00);
				Clr_Bit(TCCR0 , COM01);

				Set_Bit( TIMSK , TOIE0);

			#elif TIMER0_MODE == TIMER_CTC
				Clr_Bit(TCCR0 , WGM00);
				Set_Bit(TCCR0 , WGM01);
				// For toggle OC0
				Set_Bit(TCCR0 , COM00);
				Clr_Bit(TCCR0 , COM01);
				/* 	Interrupt Enable */
				Set_Bit( TIMSK , OCIE0);

			#elif TIMER0_MODE == TIMER_FASTPWM
				Set_Bit(TCCR0 , WGM00);
				Set_Bit(TCCR0 , WGM01);
				// For Non Inverting Mode
				Clr_Bit(TCCR0 , COM00);
				Set_Bit(TCCR0 , COM01);

			#elif TIMER0_MODE == TIMER_PHASECORRECT
				Set_Bit(TCCR0 , WGM00);
				Clr_Bit(TCCR0 , WGM01);
				// For Non Inverting Mode
				Clr_Bit(TCCR0 , COM00);
				Set_Bit(TCCR0 , COM01);

			#else
			#error "Please Select the Right Mode"
			#endif
		break;
		case TIMER1 :
			/* 	Interrupt Enable */
			/* Select Mode */
			#if TIMER1_MODE == TIMER_OVF
				Clr_Bit(TCCR1A , WGM10);
				Clr_Bit(TCCR1A , WGM11);
				Clr_Bit(TCCR1B , WGM12);
				Clr_Bit(TCCR1B , WGM13);
				// For Normal Operation
				Clr_Bit(TCCR1A , COM1A0);
				Clr_Bit(TCCR1A , COM1A1);

				Set_Bit( TIMSK , TOIE1);


			#elif TIMER1_MODE == TIMER_CTC
				Clr_Bit(TCCR1A , WGM10);
				Clr_Bit(TCCR1A , WGM11);
				Set_Bit(TCCR1B , WGM12);
				Set_Bit(TCCR1B , WGM13);
				// For Toggle OC2
				Set_Bit(TCCR1A , COM1A0);
				Clr_Bit(TCCR1A , COM1A1);

				Set_Bit( TIMSK , OCIE1A);


			#elif TIMER1_MODE == TIMER_FASTPWM
				Clr_Bit(TCCR1A , WGM10);
				Set_Bit(TCCR1A , WGM11);
				Set_Bit(TCCR1B , WGM12);
				Set_Bit(TCCR1B , WGM13);
				// For Non Inverting Mode
				Clr_Bit(TCCR1A , COM1A0);
				Set_Bit(TCCR1A , COM1A1);

			#elif TIMER1_MODE == TIMER_PHASECORRECT
				Clr_Bit(TCCR1A , WGM10);
				Set_Bit(TCCR1A , WGM11);
				Clr_Bit(TCCR1B , WGM12);
				Set_Bit(TCCR1B , WGM13);
				// For Non Inverting Mode
				Clr_Bit(TCCR2 , COM20);
				Set_Bit(TCCR2 , COM21);
			#else
			#error "Please Select the Right Mode"
			#endif
		break;

		case TIMER2 :
			/* 	Interrupt Enable */
			/* Select Mode */
			#if TIMER2_MODE == TIMER_OVF
				Clr_Bit(TCCR2 , WGM20);
				Clr_Bit(TCCR2 , WGM21);
				// For Normal Operation
				Clr_Bit(TCCR2 , COM20);
				Clr_Bit(TCCR2 , COM21);

				Set_Bit( TIMSK , TOIE2);


			#elif TIMER2_MODE == TIMER_CTC
				Clr_Bit(TCCR2 , WGM20);
				Set_Bit(TCCR2 , WGM21);
				// For Toggle OC2
				Set_Bit(TCCR2 , COM20);
				Clr_Bit(TCCR2 , COM21);

				Set_Bit( TIMSK , OCIE2);


			#elif TIMER2_MODE == TIMER_FASTPWM
				Set_Bit(TCCR2 , WGM20);
				Set_Bit(TCCR2 , WGM21);
				// For Non Inverting Mode
				Set_Bit(TCCR2 , COM20);
				Set_Bit(TCCR2 , COM21);

			#elif TIMER2_MODE == TIMER_PHASECORRECT
				Set_Bit(TCCR2 , WGM20);
				Clr_Bit(TCCR2 , WGM21);
				// For Non Inverting Mode
				Clr_Bit(TCCR2 , COM20);
				Set_Bit(TCCR2 , COM21);

			#else
			#error "Please Select the Right Mode"
			#endif
		break;
	}
}

void MTIMERS_VoidCTC_CallBack(u8 A_U8TimerID ,u32 A_u16Interval_counts,u16 A_u16compare_value,  void(*A_TIMERS_Ptr)(void))
{
	G_IntervalCounter = A_u16Interval_counts;
	switch(A_U8TimerID)
	{
	case TIMER0 :
		TIMER0_CTC = A_TIMERS_Ptr ;
		MTIMERS_VoidStart(TIMER0);
		break;
	case TIMER1 :
		TIMER1_CTC = A_TIMERS_Ptr ;
		MTIMERS_VoidStart(TIMER1);
		break;
	case TIMER2 :
		TIMER2_CTC = A_TIMERS_Ptr ;
		MTIMERS_VoidStart(TIMER2);
		break;
	}
	MTIMERS_VoidSetCompare(A_U8TimerID , A_u16compare_value);
}

void MTIMERS_VoidSetCompare(u8 A_U8TimerID , u16 A_U16CompareValue)
{
	switch(A_U8TimerID)
	{
	case TIMER0 : OCR0 = A_U16CompareValue ; break;
	case TIMER1 :
		OCR1AL = A_U16CompareValue ;
		OCR1BL = A_U16CompareValue ;
		break;
	case TIMER2 : OCR2 = A_U16CompareValue ; break;
	}
}

void MTIMERS_VoidSetIntervals_OVF(u8 A_U8TimerID ,u32 A_U32IntervalCounters , void(*A_TIMERS_Ptr)(void))
{
	switch(A_U8TimerID)
		{
		case TIMER0 :
			G_IntervalCounter = A_U32IntervalCounters ;
			TIMER0_OVF = A_TIMERS_Ptr ;
			MTIMERS_VoidStart(TIMER0);
			break;
		case TIMER1 :
			G_IntervalCounter = A_U32IntervalCounters ;
			TIMER1_OVF = A_TIMERS_Ptr ;
			MTIMERS_VoidStart(TIMER1);
			break;
		case TIMER2 :
			G_IntervalCounter = A_U32IntervalCounters ;
			TIMER2_OVF = A_TIMERS_Ptr ;
			MTIMERS_VoidStart(TIMER2);
			break;
		}
}

void MTIMERS_VoidPreLoadval(u8 A_U8TimerID , u16 A_U16PreLoadVal)
{
	switch(A_U8TimerID)
	{
	case TIMER0 : TCNT0 = A_U16PreLoadVal; break;
	case TIMER1 : TCNT1L = A_U16PreLoadVal; break;
	case TIMER2 : TCNT2 = A_U16PreLoadVal; break;
	}
}

void MTIMERS_VoidStart(u8 A_U8TimerID)
{
	switch( A_U8TimerID)
	{
	case TIMER0 : TCCR0 = ( TCCR0 & 0XF8) | (TIMER0_PRS_Clock) ;break;
	case TIMER1 :
		TCCR1B =  ( TCCR1B & 0XF8) | (TIMER1_PRS_Clock);
		ICR1L = ICR_Value ;
		break;
	case TIMER2 : TCCR2 = ( TCCR2 & 0XF8) | (TIMER2_PRS_Clock) ;break;
	}
}

void MTIMERS_VoidStop(u8 A_U8TimerID)
{
	switch( A_U8TimerID)
	{
	case TIMER0 : TCCR0 = ( TCCR0 & 0XF8) | (TIMER0_PRS_Clock) ;break;
	case TIMER1 : TCCR1B =  ( TCCR1B & 0XF8) | (TIMER0_PRS_Clock);break;
	case TIMER2 : TCCR2 = ( TCCR2 & 0XF8) | (TIMER2_PRS_Clock) ;break;
	}
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static u32 L_U32Counter = 0 ;
		L_U32Counter ++ ;
		if( L_U32Counter == G_IntervalCounter)
		{
			TIMER0_CTC();
			L_U32Counter = 0 ;
		}
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u32 L_U32Counter = 0 ;
	L_U32Counter ++ ;
	if( L_U32Counter == G_IntervalCounter)
	{
		TIMER0_OVF();
		L_U32Counter = 0 ;
	}
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	static u32 L_U32Counter = 0 ;
		L_U32Counter ++ ;
		if( L_U32Counter == G_IntervalCounter)
		{
			TIMER2_CTC();
			L_U32Counter = 0 ;
		}

}


void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	static u32 L_U32Counter = 0 ;
	L_U32Counter ++ ;
	if( L_U32Counter == G_IntervalCounter)
	{
		TIMER2_OVF();
		L_U32Counter = 0 ;
	}
}

void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	static u32 L_U32Counter = 0 ;
		L_U32Counter ++ ;
		if( L_U32Counter == G_IntervalCounter)
		{
			TIMER1_CTC();
			L_U32Counter = 0 ;
		}

}

/*void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	TIMER1_ICR();

}*/

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	static u32 L_U32Counter = 0 ;
	L_U32Counter ++ ;
	if( L_U32Counter == G_IntervalCounter)
	{
		TIMER1_OVF();
		L_U32Counter = 0 ;
	}
}
