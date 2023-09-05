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
#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_
/***********************************TIMER0*************************************/
#define TIMER0_NORMAL_MODE  	     1
#define TIMER0_CTC_MODE      		 2
#define TIMER0_FPWM_MODE      		 3
#define TIMER0_PPWM_MODE      		 4

#define TIMER0_NO_PRESCALER   		 1
#define TIMER0_8_PRESCALER    		 2
#define TIMER0_64_PRESCALER    	     3
#define TIMER0_256_PRESCALER   		 4
#define TIMER0_1024_PRESCALER   	 5
/***********************************TIMER2**************************************/
#define TIMER2_NORMAL_MODE  	     1
#define TIMER2_CTC_MODE      		 2
#define TIMER2_FPWM_MODE      		 3
#define TIMER2_PPWM_MODE      		 4

#define TIMER2_NO_PRESCALER   		 1
#define TIMER2_8_PRESCALER    		 2
#define TIMER2_32_PRESCALER    		 3
#define TIMER2_64_PRESCALER    	     4
#define TIMER2_128_PRESCALER    	 5
#define TIMER2_256_PRESCALER   		 6
#define TIMER2_1024_PRESCALER   	 7





#define NULL      (void*)0

#endif /* MTIMER_PRIVATE_H_ */
