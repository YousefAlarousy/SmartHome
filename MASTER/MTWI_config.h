/*
 * MTWI_config.h
 *
 *  Created on: Aug 19, 2023
 *      Author: hp
 */

#ifndef MTWI_CONFIG_H_
#define MTWI_CONFIG_H_

/* TWI_PRESCALER >>>>           TWI_DIV_1
 * 								TWI_DIV_4
 * 								TWI_DIV_16
 * 								TWI_DIV_64	*/

#define TWI_PRESCALER		TWI_DIV_1
#define TWBR_VALUE			2
#define MY_ADDRESS			0x01

#endif /* MTWI_CONFIG_H_ */
