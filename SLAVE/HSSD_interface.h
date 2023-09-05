/*
 * HSSD_interface.h
 *
 *  Created on: Aug 7, 2023
 *      Author: youssef
 */

#ifndef HSSD_INTERFACE_H_
#define HSSD_INTERFACE_H_


#define SSD_PORTA    DIO_PORTA
#define SSD_PORTB    DIO_PORTB
#define SSD_PORTC    DIO_PORTC
#define SSD_PORTD    DIO_PORTD

#define SSD_PIN0   DIO_PIN0
#define SSD_PIN1   DIO_PIN1
#define SSD_PIN2   DIO_PIN2
#define SSD_PIN3   DIO_PIN3
#define SSD_PIN4   DIO_PIN4
#define SSD_PIN5   DIO_PIN5
#define SSD_PIN6   DIO_PIN6
#define SSD_PIN7   DIO_PIN7




void HSSD_voidEnable(u8 Copy_EnablePort,u8 Copy_EnablePin);
void HSSD_voidDisable(u8 Copy_EnablePort,u8 Copy_EnablePin);
void HSSD_voidSendNumber(u8 Copy_u8Number);

#endif /* HSSD_INTERFACE_H_ */
