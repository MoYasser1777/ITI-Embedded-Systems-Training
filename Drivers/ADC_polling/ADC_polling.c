/*
 * ADC.c
 *
 *  Created on: Aug 20, 2023
 *      Author: lenovo
 */
#include "../ADC_polling/ADC_polling.h"

#include <avr/io.h>
#include "../../Lib/Bit_Maths.h"

void MADC_voidInit()
{
	//AVCC with external capacitor at AREF pin
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	//Data Adjustment
	CLR_BIT(ADMUX,ADLAR);

	//Prescaler Selection //divisor : 64
	ADCSRA=(ADCSRA & 0xf8)|ADC_PreScalar;

	//Auto Trigger Enable (polling)
	SET_BIT(ADCSRA,ADATE);

	//disable interrupt
	CLR_BIT(ADCSRA,ADIE);

	//Enable ADC
	SET_BIT(ADCSRA,ADEN);
}

u16 MADC_u16ConvertToDigital(u8 A_u8ChannelNum)
{

	A_u8ChannelNum &= 0x07;

	//select channel
	ADMUX=(ADMUX & 0xf8) | A_u8ChannelNum;

	//start conversion
	SET_BIT(ADCSRA,ADSC);

	//poll on flag
	while ( GET_BIT(ADCSRA , ADSC) != 0)  {

	}

	//clear flag
	CLR_BIT(ADCSRA,ADIF);

	return ADC;
}
