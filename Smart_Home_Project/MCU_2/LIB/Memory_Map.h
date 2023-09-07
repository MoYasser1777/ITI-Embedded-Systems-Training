/*
 * Memory_Map.h
 *
 *  Created on: 11 Aug 2023
 *      Author: ehab
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

/* MDIO_Registers */
#define DDRA  (*(volatile u8 *)0x3A)
#define DDRB  (*(volatile u8 *)0x37)
#define DDRC  (*(volatile u8 *)0x34)
#define DDRD  (*(volatile u8 *)0x31)

#define PINA  (*(volatile u8 *)0x39)
#define PINB  (*(volatile u8 *)0x36)
#define PINC  (*(volatile u8 *)0x33)
#define PIND  (*(volatile u8 *)0x30)

#define PORTA (*(volatile u8 *)0x3B)
#define PORTB (*(volatile u8 *)0x38)
#define PORTC (*(volatile u8 *)0x35)
#define PORTD (*(volatile u8 *)0x32)

/****************************************************************************************************/
/* External Interrupt */
#define MCUCSR   (*(volatile u8*)0x54)
#define ISC2 6

#define MCUCR    (*(volatile u8*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define GICR     (*(volatile u8*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR     (*(volatile u8*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5

#define SREG	 (*(volatile u8 *) 0x5F)
#define I_BIT 7

/****************************************************************************************************/
/* Timer 0 */
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)
#define TWCR    (*(volatile unsigned char*)0x56)
#define SPMCR   (*(volatile unsigned char*)0x57)
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)

#define OCR0    (*(volatile unsigned char*)0x5C)
/****************************************************************************************************/
/*TIMER 1*/

#define ICR1         (*(volatile unsigned short*)0x46)
#define ICR1L     (*(volatile unsigned char*)0x46)
#define ICR1H     (*(volatile unsigned char*)0x47)
#define OCR1B     (*(volatile unsigned short*)0x48)
#define OCR1BL    (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)
#define OCR1A     (*(volatile unsigned short*)0x4A)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH      (*(volatile unsigned char*)0x4B)
#define TCNT1       (*(volatile unsigned short*)0x4C)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)
#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define TCCR1A        (*(volatile unsigned char*)0x4F)

#define SFIOR       (*(volatile unsigned char*)0x50)

#define OSCCAL       (*(volatile unsigned char*)0x51)
/******************************************************************************/
/* Timer 2 */

#define OCR2     (*(volatile unsigned char*)0x43)
#define TCNT2    (*(volatile unsigned char*)0x44)
#define TCCR2    (*(volatile unsigned char*)0x45)


/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

/* ASSR */
/* bits 7-4 reserved */
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* WDTCR */
#define WDTCR    (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0


/*******************************USART***********************************************/
/* USART Baud Rate Register Low */
#define UBRRL    (*(volatile unsigned char*)0x29)

/* USART Control and Status Register B */
#define UCSRB    (*(volatile unsigned char*)0x2A)

/* USART Control and Status Register A */
#define UCSRA    (*(volatile unsigned char*)0x2B)

/* USART I/O Data Register */
#define UDR      (*(volatile unsigned char*)0x2C)

/* USART Baud Rate Register High */
#define UBRRH    (*(volatile unsigned char*)0x40)

/* USART Control and Status Register C */
#define UCSRC    (*(volatile unsigned char*)0x40)

/* USART Register C */
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0

/* USART Status Register A  */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0
/* USART Control Register B  */
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0

#endif /* MEMORY_MAP_H_ */
