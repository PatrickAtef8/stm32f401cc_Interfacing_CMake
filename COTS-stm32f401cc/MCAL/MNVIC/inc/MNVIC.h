#ifndef MNVIC_INTERFACE_H
#define MNVIC_INTERFACE_H
 

#include "MNVIC.h"
#include "MNVIC_private.h"
#include "STD_TYPES.h"

typedef enum
{
	MNVIC_enuOK,
	MNVIC_enuNOK,
}MNVIC_enuErrorStatus_t;


typedef enum {
    WWDG = 0,                                                           
    EXTI16_PVD,                                                        
    EXTI21_TAMP_STAMP,                                                 
    EXTI22_RTC_WKUP,                                                
    FLASH,                                     
    RCC_INT,                                     
    EXTI0,                                   
    EXTI1,                                   
    EXTI2,                                   
    EXTI3,                                   
    EXTI4,                                   
    DMA1_Stream0,                                 
    DMA1_Stream1,         
    DMA1_Stream2,         
    DMA1_Stream3,         
    DMA1_Stream4,         
    DMA1_Stream5,         
    DMA1_Stream6,                               
    ADC,                                
    EXTI9_5 = 23,                              
    TIM1_BRK_TIM9,                                     
    TIM1_UP_TIM10,                                       
    TIM1_TRG_COM_TIM11,                                                
    TIM1_CC,                                     
    TIM2,                               
    TIM3,                               
    TIM4,                                                           
    I2C1_EV,                                                       
    I2C1_ER,                                                       
    I2C2_EV,                                                       
    I2C2_ER,                                                       
    SPI1,                                                           
    SPI2,                                                           
    USART1,                                                           
    USART2,                                                           
    EXTI15_10 = 40,                                                                  
    EXTI17_RTC_Alarm,                                              
    EXTI18_OTG_FS_WKUP,                                           
    DMA1_Stream7 = 47,                       
    SDIO = 49,                       
    TIM5,                            
    SPI3,                            
    DMA2_Stream0 = 56,                       
    DMA2_Stream1,                            
    DMA2_Stream2,                            
    DMA2_Stream3,                            
    DMA2_Stream4,                            
    OTG_FS = 67,                                 
    DMA2_Stream5,                            
    DMA2_Stream6,                            
    DMA2_Stream7,                            
    USART6,                                                           
    I2C3_EV,                                                       
    I2C3_ER,                                                       
    FPU = 81,                                                      
    SPI4 = 84
} IRQ_VectorTable_t;

void MNVIC_vInit(void);
MNVIC_enuErrorStatus_t MNVIC_EnableIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber);
MNVIC_enuErrorStatus_t MNVIC_DisableIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber);
MNVIC_enuErrorStatus_t SetPendingIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber);
MNVIC_enuErrorStatus_t ClearPendingIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber);
u8 GetActiveIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber);
u8 GetPendingIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber);
MNVIC_enuErrorStatus_t MNVIC_enuSetPriority(IRQ_VectorTable_t IRQn, u32 priority);
MNVIC_enuErrorStatus_t MNVIC_enuGetPriority(IRQ_VectorTable_t IRQn, u32 *priority);
MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityGrouping(u32 Copy_u32Grouping);















#endif