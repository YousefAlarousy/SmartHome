/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : MCAL           ****************/
/************* Module : SPI            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 18/8/2023      ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"

#include "MSPI_register.h"
#include "MSPI_config.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

void MSPI_voidInit()
{

	/*Data Order*/
	SET_BIT(SPCR,SPCR_DORD);
	/*Master & Slave Selection */
#if SPI_MODE==SPI_MASTER
	SET_BIT(SPCR,SPCR_MSTR);
	/*Select Prescaler as 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_MODE==SPI_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#else
#error"Wrong SPI Mode Configuration"
#endif
	/* Select Clock Polarity as Leading edge rising*/
	CLR_BIT(SPCR,SPCR_CPOL);
	/* Select Clock Phase as Leading edge is sample*/
	CLR_BIT(SPCR,SPCR_CPHA);

	/*Enable SPI peripheral*/
	SET_BIT(SPCR,SPCR_SPE);

}
u8 MSPI_voidTranceive(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data ;

	while( (GET_BIT(SPSR,SPSR_SPIF)) ==0);

	return SPDR ;
}
