/*
 * Timer.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../../Lib/STD_Types.h"

void MTIMER_voidInit(u8 A_u8TimerNum);

void MTIMER_voidStart(u8 A_u8TimerNum);

void MTIMER_voidEnable(u8 A_u8TimerNumber);

void MTIMER_voidDisable(u8 A_u8TimerNumber);

void MTIMR_voidSetCompareMatch(u8 A_u8TimerNum,u8 A_u8Value);

void MTIMER_voidSetPreLoad(u8 A_u8PreLoad);

void MTIMER_voidSetCounts(u32 A_u8Counts);

void MTimer_voidSetCallBack(u8 A_u8TimerNumber, void (*A_FuncPtr)(void));

#endif /* MCAL_TIMER_TIMER_H_ */
