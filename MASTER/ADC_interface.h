/*
 * ADC_interface.h
 *
 *  Created on: Sep 1, 2023
 *      Author: youssef
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_DATA		  *((volatile u16 *)0x24)

void ADC_Init();
void ADC_SelectChannel(u8 channel);
void ADC_StartConversionAndWait();
u16 ADC_Read();
void ADC_voidSetCallBack(void (*Copy_pf)(void) );


#endif /* ADC_INTERFACE_H_ */
