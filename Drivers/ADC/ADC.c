/*
 * ADC.c
 *
 *  Created on: Aug 20, 2023
 *      Author: lenovo
 */
#include "../ADC/ADC.h"
#include "../../Lib/Bit_Maths.h"

void (*ADC_callback)(void);

void MADC_voidInit()
{
	// Reference Voltage
	#if ADC_REF_VOLT == AVCC
	 CLR_BIT (ADMUX, REFS1);
	 SET_BIT(ADMUX, REFS0);

	#elif ADC_REF_VOLT == Internal_Ref
	 SET_BIT (ADMUX, REFS1);
	 SET_BIT (ADMUX, REFS0);

	#elif ADC_REF_VOLT == AREF
	CLR_BIT (ADMUX, REFS1);
	CLR_BIT (ADMUX, REFS0);

	#else
	#error "Please select the correct refrence"

#endif

	//Data Adjustment
	CLR_BIT(ADMUX,ADLAR);

	//Prescaler Selection //divisor : 64
	ADCSRA=(ADCSRA & 0xf8)|ADC_PreScalar;

	//Auto Trigger Enable
	SET_BIT(ADCSRA,ADATE);

	//interrupt enable/disable
#if ADC_INT_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADIE);

#elif ADC_INT_ENABLE == DISABLE
	CLR_BIT(ADCSRA,ADIE);

#endif

	//Enable ADC
	SET_BIT(ADCSRA,ADEN);
}

u16 MADC_u16ConvertToDigital_Polling(u8 A_u8ChannelNum)
{

	A_u8ChannelNum &= 0x07;

	//select channel
	ADMUX=(ADMUX & 0xe0) | A_u8ChannelNum;

	//start conversion
	SET_BIT(ADCSRA,ADSC);

	//poll on flag
	while (GET_BIT(ADCSRA , ADSC) != 0){}

	//clear flag
	CLR_BIT(ADCSRA,ADIF);

	return ADC;
}

void MADC_voidConvertToDigital_Interrupt (u8 A_u8ChannelNum)
{
	A_u8ChannelNum &= 0x07;

		//select channel
		ADMUX=(ADMUX & 0xe0) | A_u8ChannelNum;

		//start conversion
		SET_BIT(ADCSRA,ADSC);
}

void MADC_voidSetCallBack(void(*A_FuncPtr)(void))
{
	ADC_callback=A_FuncPtr;
}

void __vector_16(void)  __attribute__((signal));

void __vector_16(void) {
	ADC_callback();
}
