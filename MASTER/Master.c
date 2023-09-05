#include "STD_TYPES.h"
#include "MACROS.h"

#include "MDIO_interface.h"
#include "MUSART_interface.h"
#include "MSPI_interface.h"
#include "MGIE_interface.h"
#include "ADC_interface.h"
#include "MTIMER_interface.h"
#include "MAPPING_interface.h"
#include"MTWI_interface.h"


#include "EEPROM_interface.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "util/delay.h"


void ADC_ISR();
void ISR_UART();
void ISR_TIMER1();

u8 flag=0;

u8* ptr = (u8*)0x01 ;
u8 flag_User=0;
u8 flag_CorrectPass=0 ;


u16 ReadInt_EEPROM(u8* address);
void WriteInt_EEPROM(u16 number,u8* address);
void Add_ID_EEPROM(u16 ID);
void Add_Pass_EEPROM(u16 Pass);
void Check_ID(u16 User_ID);
void Check_Pass(u16 User_Pass);



int main()
{
	u8 f=0,Key,Pass_Counter=0;
	u16 i=10000;
	u16 ID=0 ;
	u16 Pass=0 ;

	Port_voidInit();
	HLCD_voidInit();
	MTWI_voidInit();

	MUART_voidInit();
	MUART_SetCallBack(ISR_UART);
	MGIE_voidEnable();

	ADC_Init();
	ADC_voidSetCallBack(ADC_ISR);




	MTIMER1_voidSetCallBack_CMP(ISR_TIMER1);
	MTIMER1_voidSetTopValue(391,TOP_CTC_ICR1);


	while(1)
	{
		HLCD_voidSetCursorPosition(1,0);
		HLCD_voidSendString("1.Open Smart Sys");
		HLCD_voidSetCursorPosition(2,0);
		HLCD_voidSendString("# For More");
		Key=HKPD_u8GetPressedKey();

		if(Key != NOT_PRESSED )
		{
			if (Key=='#')
			{
				HLCD_voidClearDisplay();
				HLCD_voidSetCursorPosition(1,0);
				HLCD_voidSendString("2.Edit Pass");
				HLCD_voidSetCursorPosition(2,0);
				HLCD_voidSendString("3.Add User");
				do
				{
					Key=HKPD_u8GetPressedKey();
				}while(Key == NOT_PRESSED);
			}
			else if(Key==1)
			{
				HLCD_voidClearDisplay();
				HLCD_voidSetCursorPosition(1,0);
				HLCD_voidSendString("Enter ID :");
				i=10000;
				ID=0;
				for(f=0 ; f<4 ; f++)
				{
					do
					{
						Key=HKPD_u8GetPressedKey();
					}while(Key == NOT_PRESSED);
					HLCD_voidSendInt(Key);
					i/=10;
					ID += ( Key*i );

				}
				Check_ID(ID);
				_delay_ms(15);
				if(flag_User != 0)
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Pass :");
					i=10000;
					Pass=0 ;
					for(f=0 ; f<4 ; f++)
					{
						do
						{
							Key=HKPD_u8GetPressedKey();
						}while(Key == NOT_PRESSED);
						HLCD_voidSendInt(Key);
						i/=10;
						Pass += ( Key*i );
					}
					Check_Pass(Pass);
					_delay_ms(15);
					if(flag_CorrectPass==1)
					{
						flag_CorrectPass=0 ;
						HLCD_voidClearDisplay();
						HLCD_voidSendString("Welcome Home :) ");
						MSPI_voidInit();
						MTIMER1_voidInit(TIMER1_CTC_MODE,TOP_CTC_ICR1,TIMER1_1024_PRESCALER);
						while(1)
						{

						}
					}
					else
					{
						HLCD_voidClearDisplay();
						for(Pass_Counter=0 ; Pass_Counter<3 ; Pass_Counter++)
						{
							i=10000;
							Pass=0;
							HLCD_voidSendString("Wrong Pass");
							_delay_ms(500);
							HLCD_voidClearDisplay();
							HLCD_voidSendString("Pass : ");
							for(f=0 ; f<4 ; f++)
							{
								do
								{
									Key=HKPD_u8GetPressedKey();
								}while(Key == NOT_PRESSED);
								HLCD_voidSendInt(Key);
								i/=10;
								Pass += ( Key*i );
							}
							Check_Pass(Pass);
							if(flag_CorrectPass==1)
							{
								flag_CorrectPass=0 ;
								HLCD_voidClearDisplay();
								HLCD_voidSendString("Welcome Home :) ");
								MSPI_voidInit();
								MTIMER1_voidInit(TIMER1_CTC_MODE,TOP_CTC_ICR1,TIMER1_1024_PRESCALER);
								while(1)
								{

								}
								break;

							}
							_delay_ms(500);
							HLCD_voidClearDisplay();
						}
					}
				}
				else
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Wrong Id");
					_delay_ms(500);
				}
			}
			else if(Key==2)
			{
				HLCD_voidClearDisplay();
				HLCD_voidSetCursorPosition(1,0);
				HLCD_voidSendString("Enter ID :");
				i=10000;
				ID=0;
				for(f=0 ; f<4 ; f++)
				{
					do
					{
						Key=HKPD_u8GetPressedKey();
					}while(Key == NOT_PRESSED);
					HLCD_voidSendInt(Key);
					i/=10;
					ID += ( Key*i );

				}
				Check_ID(ID);
				if(flag_User != 0)
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Old Pass : ");
					i=10000;
					Pass=0;
					for(f=0 ; f<4 ; f++)
					{
						do
						{
							Key=HKPD_u8GetPressedKey();
						}while(Key == NOT_PRESSED);
						HLCD_voidSendInt(Key);
						i/=10;
						Pass += ( Key*i );
					}
					Check_Pass(Pass);
					_delay_ms(15);
					if(flag_CorrectPass == 1)
					{
						flag_CorrectPass=0 ;
						HLCD_voidClearDisplay();
						HLCD_voidSendString("New Pass : ");
						i=10000;
						Pass=0 ;
						for(f=0 ; f<4 ; f++)
						{
							do
							{
								Key=HKPD_u8GetPressedKey();
							}while(Key == NOT_PRESSED);
							HLCD_voidSendInt(Key);
							i/=10;
							Pass += ( Key*i );
						}
						Add_Pass_EEPROM(Pass);
					}
					else
					{
						HLCD_voidClearDisplay();
						for(Pass_Counter=0 ; Pass_Counter<2 ; Pass_Counter++)
						{
							i=10000;
							Pass=0;
							HLCD_voidSendString("Wrong Pass");
							_delay_ms(500);
							HLCD_voidClearDisplay();
							HLCD_voidSendString("Old Pass : ");
							for(f=0 ; f<4 ; f++)
							{
								do
								{
									Key=HKPD_u8GetPressedKey();
								}while(Key == NOT_PRESSED);
								HLCD_voidSendInt(Key);
								i/=10;
								Pass += ( Key*i );
							}
							Check_Pass(Pass);
							if(flag_CorrectPass==1)
							{
								flag_CorrectPass=0 ;
								HLCD_voidClearDisplay();
								HLCD_voidSendString("New Pass : ");
								i=10000;
								Pass=0 ;
								for(f=0 ; f<4 ; f++)
								{
									do
									{
										Key=HKPD_u8GetPressedKey();
									}while(Key == NOT_PRESSED);
									HLCD_voidSendInt(Key);
									i/=10;
									Pass += ( Key*i );
								}
								Add_Pass_EEPROM(Pass);
								break;
							}
							_delay_ms(500);
							HLCD_voidClearDisplay();
						}
					}
				}

			}
			else if(Key==3)
			{
				HLCD_voidClearDisplay();
				HLCD_voidSetCursorPosition(1,0);
				HLCD_voidSendString("Add ID :");
				i=10000;
				ID=0;
				for(f=0 ; f<4 ; f++)
				{
					do
					{
						Key=HKPD_u8GetPressedKey();
					}while(Key == NOT_PRESSED);
					HLCD_voidSendInt(Key);
					i/=10;
					ID += ( Key*i );
				}
				Add_ID_EEPROM(ID);

				_delay_ms(15);
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Add Pass :");
				i=10000;
				Pass=0 ;
				for(f=0 ; f<4 ; f++)
				{
					do
					{
						Key=HKPD_u8GetPressedKey();
					}while(Key == NOT_PRESSED);
					HLCD_voidSendInt(Key);
					i/=10;
					Pass += ( Key*i );
				}
				Add_Pass_EEPROM(Pass);

			}
		}
	}
}

u16 ReadInt_EEPROM(u8* address)
{
	u16 N,LocalVar=0,j=1000;
	u8 n;
	for(u8 i=0 ;i<4 ;i++)
	{
		EEPROM_voidRead(address+3,&n);
		N=(u16)n*j;
		LocalVar+=N;
		j/=10 ;
		N=0;
		_delay_ms(15);
		address-- ;
	}
	return LocalVar ;
}
void WriteInt_EEPROM(u16 number,u8* address)
{
	u8 LocalVar;
	//u8* pointer=address;
	for(u8 i=0 ; i<4 ; i++)
	{
		LocalVar=number%10 ;
		number/=10 ;
		EEPROM_voidWrite(LocalVar , address);
		_delay_ms(15);
		address++ ;
	}
}
void Add_ID_EEPROM(u16 ID)
{
	flag_User++ ;
	switch(flag_User)
	{
	case 1 : WriteInt_EEPROM(ID,ptr);break;
	case 2 : WriteInt_EEPROM(ID,ptr+8);break;
	case 3 : WriteInt_EEPROM(ID,ptr+16);break;
	case 4 : WriteInt_EEPROM(ID,ptr+24);break;
	case 5 : WriteInt_EEPROM(ID,ptr+32);break;
	default : break ;
	}
}
void Add_Pass_EEPROM(u16 Pass)
{
	switch(flag_User)
	{
	case 1 : WriteInt_EEPROM(Pass,ptr+4);break;
	case 2 : WriteInt_EEPROM(Pass,ptr+12);break;
	case 3 : WriteInt_EEPROM(Pass,ptr+20);break;
	case 4 : WriteInt_EEPROM(Pass,ptr+28);break;
	case 5 : WriteInt_EEPROM(Pass,ptr+36);break;
	default : break ;
	}
}
void Check_ID(u16 User_ID)
{
	u8 *address=ptr ;
	u16 ID=0;
	flag_User=0;
	for(u8 i=0 ; i<5 ; i++)
	{
		ID=ReadInt_EEPROM(address);
		if(ID==User_ID)
		{
			flag_User=i+1 ;
		}
		address+=8 ;
	}
}
void Check_Pass(u16 User_Pass)
{
	u16 Pass=0 ;
	switch(flag_User)
	{
	case 1 : Pass=ReadInt_EEPROM(ptr+4);break;
	case 2 : Pass=ReadInt_EEPROM(ptr+12);break;
	case 3 : Pass=ReadInt_EEPROM(ptr+20);break;
	case 4 : Pass=ReadInt_EEPROM(ptr+28);break;
	case 5 : Pass=ReadInt_EEPROM(ptr+36);break;
	default : break;
	}
	if(User_Pass == Pass)
	{
		flag_CorrectPass=1 ;
	}
}
void ADC_ISR()
{
	static u16 Temp=0,Reading=0,L=0,Light=0 ;

	if(flag==0)
	{
		Reading = ADC_DATA;
		Temp=Mapping(40,20,1023,0,Reading);
		MSPI_voidTranceive((u8)Temp);
		flag=1 ;
	}
	else
	{
		Light=ADC_DATA;
		L=Mapping(250,200,1023,0,Light);
		MSPI_voidTranceive((u8)L);
		flag=0 ;
	}
}
void ISR_UART()
{
	u8 x=0 ;
	x=UDR ;
	MSPI_voidTranceive(x);
}
void ISR_TIMER1()
{

	if(flag==0)
	{
		ADC_SelectChannel(0); // LM35
		ADC_StartConversionAndWait();
	}
	else
	{
		ADC_SelectChannel(1);//LDR
		ADC_StartConversionAndWait();
	}



}



