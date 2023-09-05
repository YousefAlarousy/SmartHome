#include "STD_TYPES.h"
#include "MACROS.h"

#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "MTIMER_interface.h"
#include "MGIE_interface.h"

#include "HDCMOTOR_interface.h"
#include "HLED_interface.h"
#include "HSERVO_interface.h"
#include "HSTEPPER_interface.h"
#include "HSSD_interface.h"


void EnableSSD();
u8 Temp=0 ;

int main()
{
	u8 f=0,flag=0,t ;
	u16 Light;
	char x;
	led_port_t Leds ={LED_PORT_SOURCE,LED_PORTA};
	Port_voidInit();
	MSPI_voidInit();
	MGIE_voidEnable();
	MTIMER2_voidInit();
	MTIMER2_voidCompMatchValue(200);
	MTIMER2_voidSetCallBack_CMP(EnableSSD);

	while(1)
	{
		x=MSPI_voidTranceive(0);
		if(x>=20 && x<= 40)
		{
			if(x!=Temp)
			{
				f=0;
			}
			Temp=x ;
			if (x>35 && f==0)
			{
				HDCMOTOR_voidPlay();
			}
			if( x<=35 && f==0 )
			{
				HDCMOTOR_voidStop();
			}
		}
		else if(x>=200 && x<= 250)
		{
			if(x!=t)
			{
				flag=0 ;
			}
			t=x;
			if(flag==0 )
			{
				Light=Mapping(255,0,250,200,x) ;
				HLED_voidLedPortState(Leds,~Light);
			}
		}
		else
		{
			switch(x)
			{
			case '1':HSERVO_voidSetAngle(180);break;
			case '2':HSERVO_voidSetAngle(0);break;
			case '3':HDCMOTOR_voidPlay();f=1;break;
			case '4':HDCMOTOR_voidStop();f=1;break;
			case '5':HStepperPlay_CW(270);break;
			case '6':HStepperPlay_CCW(270);break;
			case 'L':HLED_voidLedPortState(Leds,LED_PORT_ON);flag=1;break;
			case 'l':HLED_voidLedPortState(Leds,LED_PORT_OFF);flag=1;break;
			default : break ;
			}
		}
	}
}
void EnableSSD()
{
	static u8 f=0,counter=0;
	u8 D1,D2 ;
	counter++;
	D1=Temp%10 ;
	D2=Temp/10 ;
	if(counter==100)//5ms
	{
		counter=0;
		if(f==0)
		{
			HSSD_voidEnable(SSD_PORTC,SSD_PIN7);
			HSSD_voidDisable(SSD_PORTB,SSD_PIN1);
			HSSD_voidSendNumber(D1);
			f=1 ;
		}
		else
		{
			HSSD_voidDisable(SSD_PORTC,SSD_PIN7);
			HSSD_voidEnable(SSD_PORTB,SSD_PIN1);
			HSSD_voidSendNumber(D2);
			f=0 ;
		}
	}

}

