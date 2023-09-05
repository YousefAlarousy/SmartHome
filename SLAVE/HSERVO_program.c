#include "STD_TYPES.h"
#include "MACROS.h"

#include "MTIMER_interface.h"
#include "HSERVO_private.h"
#include "HSERVO_interface.h"
#include "HSERVO_config.h"




void HSERVO_voidSetAngle(u8 Copy_u8Angle)
{
	u16 Local_DutyCycle ;
	MTIMER1_voidInit(TIMER1_FPWM_NON_INVERTING,TOP_FPWM_ICR1,TIMER1_8_PRESCALER);
	MTIMER1_voidSetTopValue(20000,TOP_FPWM_ICR1);
	Local_DutyCycle=Mapping(2500,700,180,0,Copy_u8Angle);
	MTIMER1_voidSetDutyCycle(Local_DutyCycle);
}

u16 Mapping(u16 X_MAX,u16 X_MIN,u16 Y_MAX,u16 Y_MIN,u16 Y)
{
	u16 X;
	X = ( (  ((u32) (X_MAX - X_MIN) * (Y-Y_MIN) )/ (Y_MAX-Y_MIN) ) + X_MIN);

	return X ;
}
