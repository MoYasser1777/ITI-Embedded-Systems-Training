/*
 * LCD.h
 *
 *  Created on: Aug 15, 2023
 *      Author: lenovo
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../Lib/STD_Types.h"
#include "../../Lib/Bit_Maths.h"
#include "../../Lib/defines.h"

#define LCD_ROW_1 127
#define LCD_ROW_2 191

#define LCD_LINE_1 1
#define LCD_LINE_2 2

#define Control_Port PORTB
#define Data_Port PORTA

//these are for 8 bit initialization
#define LCD_FunctionSet  0b00111100
#define LCD_DisplayOnOff 0b00001100
#define LCD_DisplayClear 0b00000001
#define LCD_EntryMode    0b00000110

#endif /* HAL_LCD_LCD_H_ */

void HLCD_voidSendCommand(u8 A_u8cmd);
void HLCD_voidSendData(u8 A_u8data);
void HLCD_void8bitInit();
void HLCD_voidClear();
void HLCD_voidSetCursor(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidSendString(u8 *A_u8PtrString);
