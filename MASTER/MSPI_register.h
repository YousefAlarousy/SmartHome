/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : MCAL           ****************/
/************* Module : SPI            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 18/8/2023      ****************/
/******************************************************/
/******************************************************/
/******************************************************/
#ifndef MSPI_REGISTER_H_
#define MSPI_REGISTER_H_


#define  SPCR           *((volatile u8*)0x2D)
#define  SPCR_SPIE                7
#define  SPCR_SPE                 6
#define  SPCR_DORD                5
#define  SPCR_MSTR                4
#define  SPCR_CPOL                3
#define  SPCR_CPHA                2
#define  SPCR_SPR1                1
#define  SPCR_SPR0                0


#define  SPSR           *((volatile u8*)0x2E)
#define  SPSR_SPIF                7
#define  SPSR_WCOL                6
#define  SPSR_SPI2X               0


#define  SPDR           *((volatile u8*)0x2F)
#define  SPCR_MSB                 7
#define  SPCR_LSB                 0



#endif /* MSPI_REGISTER_H_ */
