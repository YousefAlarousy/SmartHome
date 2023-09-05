/*
 * EEPROM_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: hp
 */


#include "STD_TYPES.h"
#include "MACROS.h"

#include "MTWI_interface.h"
#include "EEPROM_interface.h"


void EEPROM_voidWrite(u8 Copy_u8Data , u8 Copy_u8Address)
{
	MTWI_voidStart();

	/* send SLAVE ADDRESS with write*/
	MTWI_voidWrite(0xA0);

	/* Send memory location */
	MTWI_voidWrite(Copy_u8Address);

	/* Send Data */
	MTWI_voidWrite(Copy_u8Data);

	MTWI_voidStop();

}

void EEPROM_voidRead(u8 Copy_u8Address , u8 *Copy_pu8Data)
{
	MTWI_voidStart();

	/* send SLAVE ADDRESS with write*/
	MTWI_voidWrite(0xA0);

	/* Send memory location */
	MTWI_voidWrite(Copy_u8Address);

	/* Send repeated start */
	MTWI_voidStart();
	/* send SLAVE ADDRESS with READ*/
	MTWI_voidWrite(0xA1);

	/* master read data byte */
	*Copy_pu8Data = MTWI_u8ReadWithACK();

	MTWI_voidStop();

}
