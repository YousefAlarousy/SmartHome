#include "STD_TYPES.h"
#include "MACROS.h"
#include "MDIO_interface.h"
#include "HSSD_config.h"
#include "HSSD_interface.h"
#include "HSSD_private.h"

void HSSD_voidEnable(u8 Copy_EnablePort,u8 Copy_EnablePin)
{
#if SSD_COMMON_TYPE == SSD_COMMON_KATHODE
	MDIO_VoidSetPinValue(Copy_EnablePort,Copy_EnablePin,DIO_PIN_LOW);
#elif SSD_COMMON_TYPE==SSD_COMMON_ANODE
	MDIO_VoidSetPinValue(Copy_EnablePort,Copy_EnablePin,DIO_PIN_HIGH);
#else
#error "Wrong CommonType Configuration"
#endif
}
void HSSD_voidDisable(u8 Copy_EnablePort,u8 Copy_EnablePin)
{
#if SSD_COMMON_TYPE == SSD_COMMON_KATHODE
	MDIO_VoidSetPinValue(Copy_EnablePort,Copy_EnablePin,DIO_PIN_HIGH);
#elif SSD_COMMON_TYPE==SSD_COMMON_ANODE
	MDIO_VoidSetPinValue(Copy_EnablePort,Copy_EnablePin,DIO_PIN_LOW);
#else
#error "Wrong CommonType Configuration"
#endif
}
void HSSD_voidSendNumber(u8 Copy_u8Number)
{
	u8 Local_u8Number ;
#if SSD_COMMON_TYPE==SSD_COMMON_KATHODE
	switch(Copy_u8Number)
	{
	case 0 : Local_u8Number =0b0111111 ; break ;
	case 1 : Local_u8Number =0b0000110 ; break ;
	case 2 : Local_u8Number =0b1011011 ; break ;
	case 3 : Local_u8Number =0b1001111 ; break ;
	case 4 : Local_u8Number =0b1100110 ; break ;
	case 5 : Local_u8Number =0b1101101 ; break ;
	case 6 : Local_u8Number =0b1111101 ; break ;
	case 7 : Local_u8Number =0b0000111 ; break ;
	case 8 : Local_u8Number =0b1111111 ; break ;
	case 9 : Local_u8Number =0b1101111 ; break ;
	}
	MDIO_VoidSetPortValue(SSD_PORT,Local_u8Number);
#elif SSD_COMMON_TYPE==SSD_COMMON_ANODE
	switch(Copy_u8Number)
	{
	case 0 : Local_u8Number =(0b0111111) ; break ;
	case 1 : Local_u8Number =(0b0000110) ; break ;
	case 2 : Local_u8Number =(0b1011011) ; break ;
	case 3 : Local_u8Number =(0b1001111) ; break ;
	case 4 : Local_u8Number =(0b1100110) ; break ;
	case 5 : Local_u8Number =(0b1101101) ; break ;
	case 6 : Local_u8Number =(0b1111101) ; break ;
	case 7 : Local_u8Number =(0b0000111) ; break ;
	case 8 : Local_u8Number =(0b1111111) ; break ;
	case 9 : Local_u8Number =(0b1101111) ; break ;
	}
	MDIO_VoidSetPortValue(SSD_PORT,~(Local_u8Number));
#else
#error "Wrong CommonType Configuration"
#endif
}
