/*
 * ADC.h
 *
 *  Created on: Aug 20, 2023
 *      Author: lenovo
 */

#ifndef HAL_ADC_ADC_H_
#define HAL_ADC_ADC_H_
#include "../../Lib/STD_Types.h"

#define ADC_PreScalar 0x06 //divisor : 64

#define ADMUX *((volatile u8 *) 0x27)
#define REFS0 6
#define REFS1 7
#define ADLAR 5

#define ADCSRA *((volatile u8 *) 0x26)
#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3

#define AVCC          0
#define AREF          1
#define Internal_Ref  2

#define ADCH *((volatile u8 *) 0x25)
#define ADCL *((volatile u8 *) 0x24)
#define ADC  *((volatile u8 *) 0x24)

#define ENABLE  1
#define DISABLE 0

#define ADC_INT_ENABLE ENABLE

#define ADC_Ref_Voltage AVCC
void MADC_voidInit();
u16 MADC_u16ConvertToDigital_Polling(u8 A_u8ChannelNum);
void MADC_voidConvertToDigital_Interrupt (u8 A_u8ChannelNum);
void MADC_voidSetCallBack(void(*A_FuncPtr)(void));



#endif /* HAL_ADC_ADC_H_ */
