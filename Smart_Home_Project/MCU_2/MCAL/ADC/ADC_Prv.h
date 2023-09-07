/*
 * ADC_Prv.h
 *
 *  Created on: 22 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#define ADC_PRS_2		0b001
#define ADC_PRS_4		0b010
#define ADC_PRS_8		0b011
#define ADC_PRS_16		0b100
#define ADC_PRS_32		0b101
#define ADC_PRS_64		0b110
#define ADC_PRS_112		0b111

#define ADMUX	*(volatile u8*)(0X27)
#define REFS1				7
#define REFS0				6
#define ADLAR				5


#define ADCSRA	*(volatile u8*)(0X26)
#define ADEN				7
#define ADSC				6
#define ADATE				5
#define ADIF				4
#define ADIE				3

#define ADCH	*(volatile u8*)(0X25)
#define ADCL	*(volatile u8*)(0X24)
//#define ADC		*(volatile u8*)(0X24)

#define POLLING				0
#define ISR_INTERRUPT		1

#define AVCC				0
#define Internal_REF		1
#define AREF				2

#endif /* MCAL_ADC_ADC_PRV_H_ */
