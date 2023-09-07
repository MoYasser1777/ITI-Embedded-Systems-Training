/*
 * STD_Types.h
 *
 *  Created on: 11 Aug 2023
 *      Author: ehab
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// unsigned
typedef unsigned char        u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;
typedef unsigned long long  u64;

// signed
typedef signed char          s8;
typedef signed short int    s16;
typedef signed long int     s32;
typedef signed long long    s64;

// float
typedef float               f32;
typedef double              f64;


// Essential macros
#define TRUE    (u8)0x01
#define FALSE   (u8)0x00

#define HIGH    (u8)0x01
#define LOW     (u8)0x00

#define OUTPUT  (u8)0x01
#define INPUT   (u8)0x00

#define NULL    ('\0')

#define NULLPTR   ((void*)0)



#endif /* STD_TYPES_H_ */
