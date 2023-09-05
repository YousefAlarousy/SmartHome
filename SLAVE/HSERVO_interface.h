/*
 * HSERVO_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: youssef
 */

#ifndef HSERVO_INTERFACE_H_
#define HSERVO_INTERFACE_H_

/*from OC1A PIN*/
void HSERVO_voidSetAngle(u8 Copy_u8Angle);
u16 Mapping(u16 X_MAX,u16 X_MIN,u16 Y_MAX,u16 Y_MIN,u16 Y);


#endif /* HSERVO_INTERFACE_H_ */
