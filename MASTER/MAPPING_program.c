#include "STD_TYPES.h"
#include "MACROS.h"

#include "MAPPING_interface.h"




u16 Mapping(u16 X_MAX,u16 X_MIN,u16 Y_MAX,u16 Y_MIN,u16 Y)
{
	u16 X;
	X = ( (  ((u32) (X_MAX - X_MIN) * (Y-Y_MIN) )/ (Y_MAX-Y_MIN) ) + X_MIN);

	return X ;
}
