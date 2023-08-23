#ifndef Bit_Math
#define Bit_Math

#define Set_Bit(Reg, bit_num) Reg |= (1 << (bit_num))

#define Clr_Bit(Reg, bit_num) Reg &= ~(1 << (bit_num))

#define Toggle_Bit(Reg, bit_num) Reg ^= (1 << (bit_num))

#define Get_Bit(Reg, bit_num) (Reg >> bit_num) & 0x01

#define Set_Byte(Reg,Value)    Reg=Value

#endif