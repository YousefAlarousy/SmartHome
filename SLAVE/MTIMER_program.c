/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : MCAL           ****************/
/************* Module : Timer          ****************/
/************* Version : 1.00          ****************/
/************* Date   : 13/8/2023      ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"

#include "MTIMER_interface.h"
#include "MTIMER_private.h"
#include "MTIMER_register.h"
#include "MTIMER_config.h"

/*Timer0*/
void (*Timer0_PF_OVF)(void)=NULL ;
void (*Timer0_PF_CMP)(void)=NULL ;
/*Timer1*/
void (*Timer1_PF_CMP)(void)=NULL ;
void (*ICU_PF)(void)=NULL ;
/*Timer2*/
void (*Timer2_PF_OVF)(void)=NULL ;
void (*Timer2_PF_CMP)(void)=NULL ;

/**************************************TIMER0 ******************************************/

void MTIMER0_voidInit()
{
	/****Mode Selection****/
#if TIMER0_MODE==TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TIMSK,TIMSK_TOIE0); // Overflow Interrupt enable

#elif TIMER0_MODE==TIMER0_CTC_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TIMSK,TIMSK_OCIE0); // Compare Match Interrupt enable
#elif TIMER0_MODE==TIMER0_FPWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/*Non-inverting mode*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#elif TIMER0_MODE==TIMER0_PPWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

#else
#error "Wrong TIMRT0 Mode Configuration"
#endif

	/*Prescaler Selection */
#if TIMER0_PRESCALER==TIMER0_NO_PRESCALER
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif  TIMER0_PRESCALER==TIMER0_8_PRESCALER
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif  TIMER0_PRESCALER==TIMER0_64_PRESCALER
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif  TIMER0_PRESCALER==TIMER0_256_PRESCALER
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif  TIMER0_PRESCALER==TIMER0_1024_PRESCALER
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
#error"Wrong Timer0 Prescaler Selection"
#endif
}
void MTIMER0_voidDisable()
{
	/*No Clock Source*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}
void MTIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle)
{
	OCR0 = Copy_u8DutyCycle ;
}
void MTIMER0_voidPreload(u8 Copy_u8Preload)
{
	TCNT0=Copy_u8Preload ;
}

void MTIMER0_voidCompMatchValue(u8 Copy_u8ComMatchValue)
{
	OCR0=Copy_u8ComMatchValue ;
}

void MTIMER0_voidSetCallBack_OVF(void (*Copy_pf)(void) )
{
	Timer0_PF_OVF=Copy_pf ;
}
void MTIMER0_voidSetCallBack_CMP(void (*Copy_pf)(void) )
{
	Timer0_PF_CMP=Copy_pf ;
}
/*OVF*/
void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	if (Timer0_PF_OVF != NULL)
	{
		Timer0_PF_OVF() ;
	}
}
/*CMP*/
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	if (Timer0_PF_CMP != NULL)
	{
		Timer0_PF_CMP() ;
	}
}
/**************************************TIMER1 ******************************************/
void MTIMER1_voidInit(TIMER1MODES_t Copy_enuTimer1Mode , TIMER1_TOPMODES_t Copy_enuTimer1TopMode,TIMER1_PRESCALER_t Copy_enuTimer1Prescaler)
{
	switch(Copy_enuTimer1Mode)
	{
	case TIMER1_CTC_MODE :
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
		/*SEI*/
		SET_BIT(TIMSK,TIMSK_OCIE1A);
		break;
	case TIMER1_FPWM_NON_INVERTING :
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);break;
	case TIMER1_PPWM_NON_INVERTING :
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);break;
	default:break ;
	}
	switch(Copy_enuTimer1TopMode)
	{
	case TOP_CTC_ICR1 :
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case TOP_CTC_OCR1A :
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case TOP_FPWM_ICR1 :
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case TOP_FPWM_OCR1A :
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	default:break ;
	}
	switch(Copy_enuTimer1Prescaler)
	{
	case TIMER1_NO_PRESCALER:
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_8_PRESCALER:
		CLR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_64_PRESCALER:
		SET_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_256_PRESCALER:
		CLR_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_1024_PRESCALER:
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);break;
	default:break;

	}

}
void MTIMER1_voidDisable()
{
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}
void MTIMER1_voidSetTopValue(u16 Copy_TopValue ,TIMER1_TOPMODES_t Copy_enuTimer1TopMode)
{
	switch(Copy_enuTimer1TopMode)
	{
	case TOP_CTC_ICR1 : ICR1 = Copy_TopValue ;break ;
	case TOP_CTC_OCR1A : OCR1A = Copy_TopValue ;break ;
	case TOP_FPWM_ICR1 : ICR1 = Copy_TopValue ;break ;
	case TOP_FPWM_OCR1A : OCR1A = Copy_TopValue ;break ;
	default:break;

	}
}
void MTIMER1_voidSetDutyCycle(u16 Copy_DutyCycleValue)
{
	OCR1A = Copy_DutyCycleValue ;
}

void MTIMER1_voidSetCallBack_CMP(void (*Copy_pf)(void) )
{
	Timer1_PF_CMP=Copy_pf ;
}

void MTIMER1_voidICUInit(TIMER1_PRESCALER_t Copy_enuTimer1Prescaler)
{
	switch(Copy_enuTimer1Prescaler)
	{
	case TIMER1_NO_PRESCALER:
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_8_PRESCALER:
		CLR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_64_PRESCALER:
		SET_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_256_PRESCALER:
		CLR_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);break;
	case TIMER1_1024_PRESCALER:
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);break;
	default:break;
	}

}
void MTIMER1_voidSetICUSense(u8 Copy_u8ICUSense)
{
	switch(Copy_u8ICUSense)
	{
	case ICU_RISING : SET_BIT(TCCR1B,TCCR1B_ICES1);break ;
	case ICU_FALLING : CLR_BIT(TCCR1B,TCCR1B_ICES1);break ;
	default:break;
	}
}

void MTIMER1_voidEnableICUInterrupt()
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void MTIMER1_voidDisableICUInterrupt()
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
u16 MTIMER1_voidGetICUValue()
{
	return ICR1 ;
}
void MTIMER1_voidSetICUCallBack(void (*Copy_pf)(void))
{

	ICU_PF=Copy_pf ;
}

/*ICU*/
void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	if(ICU_PF!=NULL)
	{
		ICU_PF() ;
	}

}
/*COMPA*/
void __vector_7(void)  __attribute__((signal));
void __vector_7(void)
{
	if(Timer1_PF_CMP!=NULL)
	{
		Timer1_PF_CMP();
	}
}
/**************************************TIMER2 ******************************************/
void MTIMER2_voidInit()
{
	/*Mode Selection*/
#if TIMER2_MODE==TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);
	/*SEI*/
	SET_BIT(TIMSK,TIMSK_TOIE2);
#elif TIMER2_MODE==TIMER2_CTC_MODE
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
	/*Normal Operation*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);
	/*SEI*/
	SET_BIT(TIMSK,TIMSK_OCIE2);
#elif TIMER2_MODE==TIMER2_FPWM_MODE
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
	/*non-Inverting*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);
#elif TIMER2_MODE==TIMER2_PPWM_MODE
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);
	/*non-Inverting*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);
#else
#error "Wrong Timer2 Mode Selection"
#endif

#if TIMER2_PRESCALER==TIMER2_NO_PRESCALER
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_PRESCALER==TIMER2_8_PRESCALER
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_PRESCALER==TIMER2_32_PRESCALER
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_PRESCALER==TIMER2_64_PRESCALER
	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_PRESCALER==TIMER2_128_PRESCALER
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_PRESCALER==TIMER2_256_PRESCALER
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#elif TIMER2_PRESCALER==TIMER2_1024_PRESCALER
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#else
#error " Wrong Timer2 Prescaler Configuration"
#endif
}
void MTIMER2_voidDisable()
{
	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
}
void MTIMER2_voidPreload(u8 Copy_u8Preload)
{
	TCNT2=Copy_u8Preload ;
}
void MTIMER2_voidSetDutyCycle(u8 Copy_u8DutyCycle)
{
	OCR2=Copy_u8DutyCycle ;
}
void MTIMER2_voidCompMatchValue(u8 Copy_u8ComMatchValue)
{
	OCR2=Copy_u8ComMatchValue ;
}
void MTIMER2_voidSetCallBack_OVF(void (*Copy_pf)(void) )
{
	Timer2_PF_OVF=Copy_pf ;
}
void MTIMER2_voidSetCallBack_CMP(void (*Copy_pf)(void) )
{
	Timer2_PF_CMP=Copy_pf ;
}
/*OVF*/
void __vector_5(void)  __attribute__((signal));
void __vector_5(void)
{
	if(Timer2_PF_OVF!=NULL)
	{
		Timer2_PF_OVF();
	}
}
/*CMP*/
void __vector_4(void)  __attribute__((signal));
void __vector_4(void)
{
	if(Timer2_PF_CMP!=NULL)
	{

		Timer2_PF_CMP();
	}
}






