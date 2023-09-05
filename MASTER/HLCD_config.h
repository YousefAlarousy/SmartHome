/***************************************************/
/********************	Auther	: Amr 		********/

/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/


#ifndef _HLCD_CONFIG_H
#define _HLCD_CONFIG_H
#include "STD_TYPES.h"

#define LCD_MODE			HLCD_MODE_4

#define LCD_PORT_DATA 		DIO_PORTC
#define LCD_D0		 		DIO_PIN4
#define LCD_D1		 		DIO_PIN5
#define LCD_D2		 		DIO_PIN6
#define LCD_D3		 		DIO_PIN7

#define LCD_PORT_CTRL 		DIO_PORTB
#define LCD_RS 				0
#define LCD_RW 				1
#define LCD_EN	 			2


#endif
