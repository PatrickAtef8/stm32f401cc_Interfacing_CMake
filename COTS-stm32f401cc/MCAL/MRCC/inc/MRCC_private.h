#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "STD_TYPES.h"


/* ON clock mask*/
#define RCC_BASE_ADDRESS            0x40023800
#define RCC_HSI_ON_MASK             0x00000000
#define RCC_HSE_ON_MASK             0x00010000
#define RCC_PLL_ON_MASK             0x01000000

/*Ready clock mask*/
#define RCC_HSI_RDY_MASK 			0x00000002
#define RCC_HSE_RDY_MASK			0X00020000
#define RCC_PLL_RDY_MASK			0x02000000


#define RCC_SELECT_HSI            	~((1 << 0) | (1 << 1));
#define RCC_SELECT_HSE 				(RCC->RCC_CFGR | (1 << 0)) & ~(1 << 1);
#define RCC_SELECT_PLL 				(RCC->RCC_CFGR | (1 << 1)) & ~(1 << 0)


#define RCC_SW_MASK 				0xFFFFFFFC

#define RCC_PLL_SYSCLK_MASK         0x00400000


#define RCC_PLL_P_MASK				0xFFFCFFFF
#define RCC_PLL_P_2_MASK			0x00000000
#define RCC_PLL_P_4_MASK			0x00010000
#define RCC_PLL_P_6_MASK			0x00020000
#define RCC_PLL_P_8_MASK			0x00030000


#define RCC_PLL_N_MASK              0xFFFF803F
#define RCC_PLL_M_MASK              0xFFFFFFE0
#define RCC_PLL_Q_MASK				0xF0FFFFFF

#define RCC_AHB1_GPIOA 				0x00000001
#define RCC_AHB1_GPIOB 				0x00000002
#define RCC_AHB1_GPIOC 				0x00000004
#define RCC_AHB1_GPIOD 				0x00000008
#define RCC_AHB1_GPIOE 				0x00000010
#define RCC_AHB1_GPIOH 				0x00000080
#define RCC_AHB_CRC                 0x00000100

/*dma1 dma1*/
#define RCC_VRFY_AHB1				0xFF9FEF60

#define RCC_AHB2_OTGFS   			0xFFFFFF7F


#define RCC_APB1RSTR_VRFY 			0xEF1D37F0               
#define RCC_APB2RSTR_VRFY			0xFFF806CE

#define RCC_HSI_FREQ				16000000
#define RCC_HSE_FREQ                8000000


#define RCC_ENABLE  1
#define RCC_DISABLE 0
/*Registers*/
typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 Reserved1[2];
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 Reserved2[2];
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 Reserved3[2];
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 Reserved4[2];
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 Reserved5[2];
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 Reserved6[2];
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 Reserved7[2];
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 Reserved8;
	volatile u32 RCC_DCKCFGR;
}RCC_Registers_t;


#endif