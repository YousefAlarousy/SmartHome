#include "STD_TYPES.h"
#include "MACROS.h"

#include "MDIO_interface.h"
#include "MTIMER_interface.h"

#include "HDCMOTOR_config.h"
#include "HDCMOTOR_interface.h"
#include "HDCMOTOR_private.h"


void HDCMOTOR_voidStop()
{
	MDIO_VoidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN,DIO_PIN_LOW);
}
void HDCMOTOR_voidPlay()
{
	MDIO_VoidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN,DIO_PIN_HIGH);
}

