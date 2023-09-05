/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES.h"
#include "util/delay.h"
#include "MACROS.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"


void HLCD_voidInit(){
	_delay_ms(40);

	/* manual 4 bit initialization of LCD */
	MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,DIO_PIN_HIGH);
	MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,DIO_PIN_HIGH);
	MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,DIO_PIN_LOW);
	MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,DIO_PIN_LOW);

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_PIN_LOW); 	/* RS=0, command  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_PIN_LOW); 	/* RW=0, command Write */

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);

	_delay_ms(5); /* min 4.1ms */

MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,DIO_PIN_HIGH);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,DIO_PIN_HIGH);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,DIO_PIN_LOW);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,DIO_PIN_LOW);

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_PIN_LOW); 	/* RS=0, command  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_PIN_LOW); 	/* RW=0, command Write */

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);

	_delay_ms(1);

MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,DIO_PIN_HIGH);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,DIO_PIN_HIGH);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,DIO_PIN_LOW);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,DIO_PIN_LOW);

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_PIN_LOW); 	/* RS=0, command  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_PIN_LOW); 	/* RW=0, command Write */

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);


MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,DIO_PIN_LOW);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,DIO_PIN_HIGH);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,DIO_PIN_LOW);
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,DIO_PIN_LOW);

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_PIN_LOW); 	/* RS=0, command  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_PIN_LOW); 	/* RW=0, command Write */

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);

	HLCD_voidSendCommand(0x02); 	/*CMD for 4bit		*/
	HLCD_voidSendCommand(0x28);		/* Enabling 2lies 5*7   */
	HLCD_voidSendCommand(0x0c); 	/* setting cursor on and off */
	HLCD_voidSendCommand(0x06);		/* Increment cursor (shift cursor to right)	*/
	HLCD_voidSendCommand(0x01);		/* Clear display screen */
	_delay_ms(2);

}

void HLCD_voidSendData(u8 Copy_u8Data){

	/*Sending Data upper nibble*/
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,((Copy_u8Data>>4)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,((Copy_u8Data>>5)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,((Copy_u8Data>>6)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,((Copy_u8Data>>7)&1));

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_PIN_HIGH);	/*	SET RS to send data */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_PIN_LOW);	/*	CLR RW to Enable write */

	/* set EN for 2ms to make LCD CPU reads the data  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);
	_delay_us(200);

	/*Sending Data LOWER nibble */
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,((Copy_u8Data>>0)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,((Copy_u8Data>>1)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,((Copy_u8Data>>2)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,((Copy_u8Data>>3)&1));

MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);
	_delay_ms(2);
}


void HLCD_voidSendCommand(u8 Copy_u8Command){
	/*Sending UPPER Nibble of the command */
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,((Copy_u8Command>>4)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,((Copy_u8Command>>5)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,((Copy_u8Command>>6)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,((Copy_u8Command>>7)&1));

	/*	CLR RS to send command */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_PIN_LOW);
	/*	CLR RS to Enable write */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_PIN_LOW);


	/* set EN for 2ms to make LCD CPU reads the command  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);
	_delay_us(200);

	/*Sending LAST Nibble of the command */
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D0,((Copy_u8Command>>0)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D1,((Copy_u8Command>>1)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D2,((Copy_u8Command>>2)&1));
MDIO_VoidSetPinValue(LCD_PORT_DATA,LCD_D3,((Copy_u8Command>>3)&1));

	/* set EN for 2ms to make LCD CPU reads the command  */
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_HIGH);
	_delay_us(1);
MDIO_VoidSetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_PIN_LOW);
	_delay_ms(2);
}


void HLCD_voidSendString(char Copy_u8Data[]){
	int i = 0 ;
	while (Copy_u8Data[i]!='\0'){
		HLCD_voidSendData(Copy_u8Data[i]);
		i++;
	}
}

void HLCD_voidSendInt(s32 Copy_u32Data){
	s8 s[20];
	itoa(Copy_u32Data, s, 10);
	HLCD_voidSendString(s);
}

void HLCD_voidClearDisplay(){
	HLCD_voidSendCommand(0b00000001);

}

void HLCD_voidReturnHome(){
	HLCD_voidSendCommand(0b00000010);
}

void HLCD_voidSetCursorPosition(u8 x , u8 y){
	u8 command = 0b10000000;
	if (x == 2) command  |=0x40 ;
	command  +=y ;
	HLCD_voidSendCommand(command);
}
