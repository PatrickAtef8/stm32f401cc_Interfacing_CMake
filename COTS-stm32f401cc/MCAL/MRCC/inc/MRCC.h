#ifndef RCC_H
#define RCC_H

#include "STD_TYPES.h"
#include "MRCC_private.h"
typedef enum
{
	RCC_enuOK,
	RCC_enuNOK,


}RCC_enuErrorStatus_t;


typedef enum
{
	RCC_enu_HSI,
	RCC_enu_HSE,
	RCC_enu_PLL

}RCC_enuCLK_Types_t;

typedef struct
{
	u32 M;
	u32 N;
	u32 P;
	u32 Q;
	RCC_enuCLK_Types_t SysClk;
}RCC_PLL_CFG_t;

typedef enum 
{
	RCC_BUS_AHB1,
	RCC_BUS_AHB2,
	RCC_BUS_APB1,
	RCC_BUS_APB2,



}RCC_BUS_t;
typedef enum {
    HSE_FREQ_4MHZ = 4000000,
    HSE_FREQ_8MHZ = 8000000,
    HSE_FREQ_16MHZ = 16000000,
    HSE_FREQ_25MHZ = 25000000
} HSE_Freq_t;


extern RCC_Registers_t* RCC; 
RCC_enuErrorStatus_t RCC_enuEnableClk(RCC_enuCLK_Types_t Copy_enuCLK_type);
RCC_enuErrorStatus_t RCC_enuDisableClk(RCC_enuCLK_Types_t Copy_enuCLK_type);
RCC_enuErrorStatus_t RCC_enuGetClkStatus(RCC_enuCLK_Types_t Copy_enuCLK_type, u32 *Add_ret);
RCC_enuErrorStatus_t RCC_enuSysClkSelection(RCC_enuCLK_Types_t Copy_enuCLK_type);
RCC_enuErrorStatus_t RCC_enuControlPeripheralClk(RCC_BUS_t RCC_BUS,u32 RCC_Peripheral,u8 status); /*Must check if the clock is enabled or disabled*/



#endif