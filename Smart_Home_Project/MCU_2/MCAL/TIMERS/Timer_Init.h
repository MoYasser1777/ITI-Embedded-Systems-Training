/*
 * Timer_Init.h
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMER_INIT_H_
#define MCAL_TIMERS_TIMER_INIT_H_

void MTIMERS_voidTimer_Init(u8 A_U8TimerID);

void MTIMERS_VoidSetCompare(u8 A_U8TimerID , u16 A_U16CompareValue);

void MTIMERS_VoidCTC_CallBack(u8 A_U8TimerID ,u32 A_u16Interval_counts,u16 A_u16compare_value,  void(*A_TIMERS_Ptr)(void));

void MTIMERS_VoidSetIntervals_OVF(u8 A_U8TimerID ,u32 A_U32IntervalCounters , void(*A_TIMERS_Ptr)(void));

void MTIMERS_VoidPreLoadval(u8 A_U8TimerID , u16 A_U16PreLoadVal);


void MTIMERS_VoidStart(u8 A_U8TimerID);

void MTIMERS_VoidStop(u8 A_U8TimerID);

#endif /* MCAL_TIMERS_TIMER_INIT_H_ */

