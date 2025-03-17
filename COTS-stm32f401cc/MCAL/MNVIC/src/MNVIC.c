#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MNVIC.h"
#include "MNVIC_private.h"
#include "MNVIC_cfg.h"


MNVIC_REG_t* MNVIC =(MNVIC_REG_t*)MNVIC_BASE_ADDRESS;
SCB_Type* SCB = (SCB_Type*)SCB_BASE_ADDRESS;


void MNVIC_vInit()
{
    SCB->MNVIC_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}
MNVIC_enuErrorStatus_t MNVIC_EnableIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber)
{
    MNVIC_enuErrorStatus_t RET_ERROR = MNVIC_enuOK;

    if ((Copy_enuInterruptNumber < 0) || (Copy_enuInterruptNumber >= MNVIC_IRQ_COUNT))
    {
        RET_ERROR = MNVIC_enuNOK;  
    }
    else
    {
        u8 regIndex = (u8)(Copy_enuInterruptNumber / MNVIC_BITS_PER_REG); 
        u8 bitPosition = (u8)(Copy_enuInterruptNumber % MNVIC_BITS_PER_REG);

        MNVIC->MNVIC_ISER[regIndex] |= (1UL << bitPosition);  
    }

    return RET_ERROR;  
}


MNVIC_enuErrorStatus_t MNVIC_DisableIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber)
{
    MNVIC_enuErrorStatus_t RET_ERROR = MNVIC_enuOK;

    if ((Copy_enuInterruptNumber < 0) || (Copy_enuInterruptNumber >= MNVIC_IRQ_COUNT))
    {
        RET_ERROR = MNVIC_enuNOK;  
    }
    else
    {
        u8 regIndex = (u8)(Copy_enuInterruptNumber / MNVIC_BITS_PER_REG); 
        u8 bitPosition = (u8)(Copy_enuInterruptNumber % MNVIC_BITS_PER_REG);

        MNVIC->MNVIC_ICER[regIndex] |= (1UL << bitPosition); 
    }

    return RET_ERROR;  
}

MNVIC_enuErrorStatus_t SetPendingIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber)
{
    MNVIC_enuErrorStatus_t RET_ERROR = MNVIC_enuOK;

    if ((Copy_enuInterruptNumber < 0) || (Copy_enuInterruptNumber >= MNVIC_IRQ_COUNT))
    {
        RET_ERROR = MNVIC_enuNOK;  
    }
    else
    {
        u8 regIndex = (u8)(Copy_enuInterruptNumber / MNVIC_BITS_PER_REG); 
        u8 bitPosition = (u8)(Copy_enuInterruptNumber % MNVIC_BITS_PER_REG);

        MNVIC->MNVIC_ISPR[regIndex] |= (1UL << bitPosition); 
    }

    return RET_ERROR;  
}

MNVIC_enuErrorStatus_t ClearPendingIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber)
{
    MNVIC_enuErrorStatus_t RET_ERROR = MNVIC_enuOK;

    if ((Copy_enuInterruptNumber < 0) || (Copy_enuInterruptNumber >= MNVIC_IRQ_COUNT))
    {
        RET_ERROR = MNVIC_enuNOK;  
    }
    else
    {
        u8 regIndex = (u8)(Copy_enuInterruptNumber / MNVIC_BITS_PER_REG); 
        u8 bitPosition = (u8)(Copy_enuInterruptNumber % MNVIC_BITS_PER_REG);

        MNVIC->MNVIC_ICPR[regIndex] |= (1UL << bitPosition); 
    }

    return RET_ERROR;  
}


u8 GetActiveIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber)
{
    u8 ActiveReadBit = 0;  
    
    if ((Copy_enuInterruptNumber >= 0) && (Copy_enuInterruptNumber < MNVIC_IRQ_COUNT))
    {
        u8 regIndex = (u8)(Copy_enuInterruptNumber / MNVIC_BITS_PER_REG);
        u8 bitPosition = (u8)(Copy_enuInterruptNumber % MNVIC_BITS_PER_REG);

        ActiveReadBit = (u8)((MNVIC->MNVIC_IABR[regIndex] >> bitPosition) & 1U);
    }

    return ActiveReadBit;  
}


u8 GetPendingIRQ(IRQ_VectorTable_t Copy_enuInterruptNumber)
{


    u8 PendingReadBit = 0;  
    
    if ((Copy_enuInterruptNumber >= 0) && (Copy_enuInterruptNumber < MNVIC_IRQ_COUNT))
    {
        u8 regIndex = (u8)(Copy_enuInterruptNumber / MNVIC_BITS_PER_REG);
        u8 bitPosition = (u8)(Copy_enuInterruptNumber % MNVIC_BITS_PER_REG);

       PendingReadBit = (u8)((MNVIC->MNVIC_ISPR[regIndex] >> bitPosition) & 1U);
    }

    return PendingReadBit;  

}

MNVIC_enuErrorStatus_t MNVIC_enuSetPriority(IRQ_VectorTable_t IRQn, u32 priority)
{
    MNVIC_enuErrorStatus_t RET_ERROR = MNVIC_enuOK;

    if ((IRQn < 0) || (IRQn >= MNVIC_IRQ_COUNT))
    {
        RET_ERROR = MNVIC_enuNOK;  
    }
    else
    {
        u8 regIndex = IRQn / 4;

        u8 bitPosition = (IRQn % 4) * 8;

        MNVIC->MNVIC_IPR[regIndex] &= ~(0xFFU << bitPosition); 
        MNVIC->MNVIC_IPR[regIndex] |= (priority & 0xFFU) << bitPosition;  
    }

    return RET_ERROR; 
}


MNVIC_enuErrorStatus_t MNVIC_enuGetPriority(IRQ_VectorTable_t IRQn, u32 *priority)
{
    MNVIC_enuErrorStatus_t RET_ERROR = MNVIC_enuOK;

    if ((IRQn < 0) || (IRQn >= MNVIC_IRQ_COUNT) || (priority == NULL))
    {
        RET_ERROR = MNVIC_enuNOK;  
    }
    else
    {
        u8 regIndex = (u8)(IRQn / 4);
        
        u8 bitPosition = (u8)((IRQn % 4) * 8);

        *priority = (MNVIC->MNVIC_IPR[regIndex] >> bitPosition) & 0xFFU;
    }

    return RET_ERROR;
}




