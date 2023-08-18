/*
 * LCD_private.h
 *
 *  Created on: Aug 18, 2023
 *      Author: lenovo
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

//these are for 8 bit initialization
#define LCD_FunctionSet  0b00111100
#define LCD_DisplayOnOff 0b00001100
#define LCD_DisplayClear 0b00000001
#define LCD_EntryMode    0b00000110

#define LCD_ROW_1 127
#define LCD_ROW_2 191

#define LCD_LINE_1 1
#define LCD_LINE_2 2

#define CGRAM_Init 0b01000000
#define CGRAM_AvailableChars (u8)8

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
