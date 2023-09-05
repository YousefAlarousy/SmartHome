#include "STD_TYPES.h"
#include "MACROS.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_register.h"

void (*ADC_PF)(void)=NULL ;


void ADC_Init()
{
	// Set reference voltage to AVCC and left-adjust the result
	ADMUX |= (1 << ADMUX_REFS0);

	// Enable ADC and enable ADC conversion complete interrupt
	ADCSRA |= (1 << ADCSRA_ADEN) | (1 << ADCSRA_ADIE);

	// Set ADC prescaler to 64 (Fadc = Fcpu / 64)
	ADCSRA |= (1 << ADCSRA_ADPS2) | (1 << ADCSRA_ADPS1);
}
void ADC_SelectChannel(u8 channel)
{
	// Clear the channel bits and set the desired channel
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07);
}
void ADC_StartConversionAndWait()
{
	// Start the conversion
	ADCSRA |= (1 << ADCSRA_ADSC);

	// Wait for the conversion to complete
	//while (ADCSRA & (1 << ADCSRA_ADSC));
}
u16 ADC_Read()
{
	// Return the ADC result (16-bit)
	return ADC_DATA;
}

void ADC_voidSetCallBack(void (*Copy_pf)(void) )
{
	ADC_PF=Copy_pf ;
}


void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if(ADC_PF != NULL)
	{

		ADC_PF();
	}
}

