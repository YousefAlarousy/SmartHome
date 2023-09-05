/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : HAL            ****************/
/************* Module : LED            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 6/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/


#include "STD_TYPES.h"
#include "MACROS.h"
#include "MDIO_interface.h"
#include "HLED_interface.h"
#include "HLED_config.h"
#include "HLED_private.h"



void HLED_voidLedPinState(led_pin_t Copy_u8LedPinStruct,u8 Copy_u8LedPinState)
{

	switch(Copy_u8LedPinStruct.LedConnection)
	{
	case LED_PIN_SOURCE : MDIO_VoidSetPinValue(Copy_u8LedPinStruct.LedPort,Copy_u8LedPinStruct.LedPin,Copy_u8LedPinState);break ;
	case LED_PIN_SINK   : MDIO_VoidSetPinValue(Copy_u8LedPinStruct.LedPort,Copy_u8LedPinStruct.LedPin,Copy_u8LedPinState);break ;
	default:break;
	}

}
void HLED_voidLedPortState(led_port_t Copy_u8LedPortStruct,u8 Copy_u8LedPortState)
{

	switch(Copy_u8LedPortStruct.LedConnection)
	{
	case LED_PORT_SOURCE : MDIO_VoidSetPortValue(Copy_u8LedPortStruct.LedPort,Copy_u8LedPortState);break ;
	case LED_PORT_SINK   : MDIO_VoidSetPortValue(Copy_u8LedPortStruct.LedPort,Copy_u8LedPortState);break ;
	default:break;
	}


}


