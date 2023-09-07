/*
 * TIMER1_PWM.h
 *
 *  Created on: Aug 28, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER1_PWM_TIMER1_PWM_H_
#define MCAL_TIMER1_PWM_TIMER1_PWM_H_

#include "../../Lib/STD_Types.h"
#include "../../Lib/Bit_Maths.h"

void MTIMR1_voidTimer1Init();
void MTIMR1_voidSetICR(u16 A_u16value);
void MTIMR1_voidTimer1SetCompMatchA(u16 A_u16value);
void MTIMR1_voidTimer1SetCompMatchB(u16 A_u16value);

#endif /* MCAL_TIMER1_PWM_TIMER1_PWM_H_ */
