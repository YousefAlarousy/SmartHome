/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : MCAL           ****************/
/************* Module : USART          ****************/
/************* Version : 1.00          ****************/
/************* Date   : 17/8/2023      ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"

#include "MUSART_private.h"
#include "MUSART_interface.h"
#include "MUSART_register.h"
#include "MUSART_config.h"

void MUART_voidInit()
{
	u8 Temp=0 ;
	/*Enable Transmitter & Receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
	/*8-bit*/
	SET_BIT(Temp,UCSRC_UCSZ0);
	SET_BIT(Temp,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	/*Select UCSRC Register*/
	SET_BIT(Temp,UCSRC_URSEL);
	/*ASynch*/
	CLR_BIT(Temp,UCSRC_UMSEL);
	/*Stop bit is 1 i-bit */
	CLR_BIT(Temp,UCSRC_USBS);
	/*Select BaudRate*/
	UCSRC=Temp ;
	UBRRL = 51;
}
void MUART_voidTransmit(u8 Copy_u8Data)
{
	while( !GET_BIT(UCSRA,UCSRA_UDRE) );
	UDR=Copy_u8Data ;
}
u8 MUART_voidRecieve()
{
	while( !GET_BIT(UCSRA,UCSRA_RXC) );
	return UDR ;
}
