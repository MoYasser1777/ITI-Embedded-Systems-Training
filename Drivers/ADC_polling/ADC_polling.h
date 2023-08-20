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

void MADC_voidInit();
u16 MADC_u16ConvertToDigital(u8 A_u16ChannelNum);

#endif /* HAL_ADC_ADC_H_ */
