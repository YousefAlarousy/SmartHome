/*
 * MTWI_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "MACROS.h"


#include "MTWI_interface.h"
#include "MTWI_registers.h"
#include "MTWI_private.h"
#include "MTWI_config.h"



void MTWI_voidInit(void)
{
	/* Set Master | Slave Address */
	TWAR = MY_ADDRESS << 1;
	/*Set PRESCALER Value */
#if TWI_PRESCALER == TWI_DIV_1
	TWSR = 0b00000000;
#elif TWI_PRESCALER == TWI_DIV_4
	TWSR = 0b00000001;
#elif TWI_PRESCALER == TWI_DIV_16
	TWSR = 0b00000010;
#elif TWI_PRESCALER == TWI_DIV_64
	TWSR = 0b00000011;

#endif
	/*Set PRESCALER TWBR Value */
	TWBR = TWBR_VALUE;


	/*Set TWEN to enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}

void MTWI_voidStart(void)
{
//	/* set TWSTA to start condition */
//	SET_BIT(TWCR , TWCR_TWSTA);
//	/* CLR TWI flag */
//	SET_BIT(TWCR , TWCR_TWINT);
//	/* SET TWEN to enable TWI */
//	SET_BIT(TWCR , TWCR_TWEN);

	TWCR=(1<<TWCR_TWINT) | (1<<TWCR_TWSTA) | (1<<TWCR_TWEN);



	/* busy wait for TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT)) == 0);


}

void MTWI_voidWrite(u8 Copy_u8Data)
{
	/* Set Data | Address to TWDR */
	TWDR = Copy_u8Data;

	/* CLR start condition */
	CLR_BIT(TWCR , TWCR_TWSTA);
	/* CLR TWI flag */
	SET_BIT(TWCR , TWCR_TWINT);
	/* SET TWEN to enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);

	/* busy wait for TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT)) == 0);

}

u8 MTWI_u8ReadWithACK(void)
{
	/* CLR start condition */
	CLR_BIT(TWCR , TWCR_TWSTA);
	/* CLR TWI flag */
	SET_BIT(TWCR , TWCR_TWINT);
	/* SET TWEN to enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);



	/* busy wait for TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT)) == 0);

	return TWDR;
}

void MTWI_voidStop(void)
{
//	/* Set TWSTO to make stop condition */
//	SET_BIT(TWCR , TWCR_TWSTO);
//	/* CLR TWI flag */
//	SET_BIT(TWCR , TWCR_TWINT);
//	/* SET TWEN to enable TWI */
//	SET_BIT(TWCR , TWCR_TWEN);

	TWCR=(1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (1<<TWCR_TWSTO);

}

u8 MTWI_u8GetStatus(void)
{
	return (TWSR & 0xF8);
}
