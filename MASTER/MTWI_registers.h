/*
 * MTWI_registers.h
 *
 *  Created on: Aug 19, 2023
 *      Author: hp
 */

#ifndef MTWI_REGISTERS_H_
#define MTWI_REGISTERS_H_

#define TWCR			*((volatile u8*)0x56)		/* TWI Control Register*/
#define TWCR_TWINT		7							/* Interrupt Flag*/
#define TWCR_TWEA		6							/* Enable ACK */
#define TWCR_TWSTA		5							/* Start Condition */
#define TWCR_TWSTO		4							/* Stop Condition */
#define TWCR_TWWC		3							/* Write Collision */
#define TWCR_TWEN		2							/* TWI Enable */
#define TWCR_TWIE		0							/* Interrupt Enable */

#define TWDR			*((volatile u8*)0x23)		/* TWI Data register */


#define TWAR			*((volatile u8*)0x22)		/* TWI Address register */
#define TWAR_TWGCE		0							/* General call recognition enable */

#define TWSR			*((volatile u8*)0x21)		/* TWI Status register */
#define TWSR_TWPS0		0							/* Prescaler Bit0 */
#define TWSR_TWPS1		1							/* Prescaler Bit1 */

#define TWBR			*((volatile u8*)0x20)		/* TWI Bit rate register */




#endif /* MTWI_REGISTERS_H_ */
