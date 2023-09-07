/*
 * ADC_Prog.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Youssef
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_Init.h"
#include "ADC_Prv.h"
#include "ADC_Config.h"

void(*ADC_CallBack)(void); /* Pointer to Function */

void MADC_VoidADCInit()
{
	// Reference Voltage
#if ADC_Ref_VOLT == AVCC
	Set_Bit(ADMUX , REFS0);
	Clr_Bit(ADMUX , REFS1);
#elif ADC_Ref_VOLT == Internal_REF
	Set_Bit(ADMUX , REFS0);
	Set_Bit(ADMUX , REFS1);
#elif ADC_Ref_VOLT == AREF
	Clr_Bit(ADMUX , REFS0);
	Clr_Bit(ADMUX , REFS1);
#else
#error "Please Enter The correct Reference"
#endif
	// Adjustment Right
	Clr_Bit(ADMUX , ADLAR);
	// Select Prescaler
	ADCSRA = ( ADCSRA & 0XF8 ) | ADC_PRS_64 ;
	// INTERRUPT Enable & Disable
#if ADC_MODE == POLLING
	Clr_Bit( ADCSRA , ADIE);
#elif ADC_MODE == ISR_INTERRUPT
	Set_Bit( ADCSRA , ADIE);
#else
#error "Please Enter The correct Mode"
#endif
	// Auto Triggering Disable " Start Conversion Manually "
	Clr_Bit( ADCSRA , ADATE);
	// ADC Enable
	Set_Bit( ADCSRA , ADEN);
}

// polling
u16 MADC_U16AnalogRead(u8 A_U8ChannelNO)
{
	u16 ADC;
	// select channel
	ADMUX = (ADMUX & 0XE0) | ( A_U8ChannelNO & 0X07) ; /* 0x07 due to single Ended */
	// Start Conversion
	Set_Bit( ADCSRA , ADSC);
	// pool on flag
	while ( (Get_Bit( ADCSRA , ADIF)) !=1){}
	// clear flag
	Set_Bit( ADCSRA , ADIF);
	// Read the whole register
	ADC = ADCL ;
	ADC |= ADCH<<8 ;
	return ADC ;
}

// INT_ADC

void MADC_VoidINTStartConversion(u8 A_U8ChannelNO)
{
	// select channel
		ADMUX = (ADMUX & 0XE0) | ( A_U8ChannelNO & 0X07) ; // 0x07 due to single Ended
	// Start Conversion
	Set_Bit( ADCSRA , ADSC);

}

void MADC_VoidINTsetCallBack( void(*A_ADC_Ptr)(void))
{
	ADC_CallBack = A_ADC_Ptr ;

}

u16 MADC_U16INTGetADC()
{
	u16 ADC ;
	ADC = ADCL ;
	ADC |= ADCH<<8 ;
	return ADC ;
}
// ADC_ISR
void __vector_16(void)		__attribute__((signal));
void __vector_16(void)
{
	ADC_CallBack();
}
