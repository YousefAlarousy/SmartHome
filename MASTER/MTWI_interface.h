/*
 * MTWI_interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: hp
 */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

void MTWI_voidInit(void);

void MTWI_voidStart(void);

void MTWI_voidWrite(u8 Copy_u8Data);

u8 MTWI_u8ReadWithACK(void);

void MTWI_voidStop(void);

u8 MTWI_u8GetStatus(void);

#endif /* MTWI_INTERFACE_H_ */
