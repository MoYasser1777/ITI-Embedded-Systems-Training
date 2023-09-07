/*
 * ADC_Init.h
 *
 *  Created on: 22 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

// Pooling Functions
void MADC_VoidADCInit();
u16 MADC_U16AnalogRead(u8 A_U8ChannelNO);

// INTERRUPT ISR
void MADC_VoidINTStartConversion(u8 A_U8ChannelNO);
void MADC_VoidINTsetCallBack( void(*A_ADC_Ptr)(void));
u16 MADC_U16INTGetADC();


#endif /* MCAL_ADC_ADC_INIT_H_ */
