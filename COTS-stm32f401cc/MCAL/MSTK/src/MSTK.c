#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MSTK.h"
#include "MSTK_private.h"

MSTK_REG_t* MSTK = (MSTK_REG_t*)MSTK_BASE_ADDRESS;

static void (*MSTK_CallBack)(void) = NULL;


void MSTK_voidInit(void)
{
    MSTK_enuSetClockSource(MSTK_AHB_DIVIDED_BY_8);
}

MSTK_enuErrorStatus_t MSTK_enuSetCallBack(void (*Copy_ptr)(void))
{

    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;
    if (Copy_ptr == NULL)
    {
        RetError = MSTK_enuConfigError;
    }
    MSTK_CallBack = Copy_ptr;
    return RetError;
}

MSTK_enuErrorStatus_t MSTK_enuSetBusyWait(u32 Copy_u32Ticks)
{

    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;
    if (Copy_u32Ticks > MAX_TICKS)
    {
        RetError = MSTK_enuConfigError;
    }
    MSTK->MSTK_LOAD = Copy_u32Ticks;
    MSTK->MSTK_VAL = 0;
    
    while (GET_BIT(MSTK->MSTK_CTRL, COUNTFLAG_MSTK) == 0);
    
    return RetError;
}

MSTK_enuErrorStatus_t MSTK_enuSetClockSource(MSTK_enuClockSource_t Copy_enuClockSource)
{
    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;

    if (Copy_enuClockSource == MSTK_AHB_DIVIDED_BY_8)
    {
        CLR_BIT(MSTK->MSTK_CTRL, CLKSOURCE_MSTK);
    }
    else if (Copy_enuClockSource == MSTK_AHB_NOT_DIVIDED)
    {
        SET_BIT(MSTK->MSTK_CTRL, CLKSOURCE_MSTK);
    }
    else
    {
        RetError = MSTK_enuConfigError;
    }
    return RetError;
}

MSTK_enuErrorStatus_t MSTK_enuSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;
    if (Copy_u32Ticks > MAX_TICKS || Copy_ptr == NULL)
    {
        RetError = MSTK_enuConfigError;
    }
    MSTK->MSTK_LOAD = Copy_u32Ticks;
    MSTK->MSTK_VAL = 0;
    MSTK_CallBack = Copy_ptr;
    SET_BIT(MSTK->MSTK_CTRL, TICKINT_MSTK);

    return RetError;
}

MSTK_enuErrorStatus_t MSTK_enuSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{

    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;
    if (Copy_u32Ticks > MAX_TICKS || Copy_ptr == NULL)
    {
        RetError = MSTK_enuConfigError;
    }
    MSTK->MSTK_LOAD = Copy_u32Ticks;
    MSTK->MSTK_VAL = 0;
    MSTK_CallBack = Copy_ptr;
    SET_BIT(MSTK->MSTK_CTRL, TICKINT_MSTK);
    SET_BIT(MSTK->MSTK_CTRL, ENABLE_MSTK);
   
    return RetError;
}

MSTK_enuErrorStatus_t MSTK_enuStopInterval(void)
{
    CLR_BIT(MSTK->MSTK_CTRL, ENABLE_MSTK);
    CLR_BIT(MSTK->MSTK_CTRL, TICKINT_MSTK);
    MSTK->MSTK_LOAD = 0;
    MSTK->MSTK_VAL = 0;
    MSTK_CallBack = NULL;
   
    return MSTK_enuOK;
}

MSTK_enuErrorStatus_t MSTK_GetElapsedTime(u32 *Copy_u32ElapsedTime)
{
    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;
    if (Copy_u32ElapsedTime == NULL)
    {
        RetError = MSTK_enuNOK;

    }    

    *Copy_u32ElapsedTime = MSTK->MSTK_LOAD - MSTK->MSTK_VAL;

    return RetError;
}

MSTK_enuErrorStatus_t MSTK_GetRemainingTime(u32 *Copy_u32RemainingTime)
{
    MSTK_enuErrorStatus_t RetError = MSTK_enuOK;

    if (Copy_u32RemainingTime == NULL)
    {
        RetError = MSTK_enuNOK;
    }
    *Copy_u32RemainingTime = MSTK->MSTK_VAL;
   
    return RetError;
}

void SysTick_Handler(void)
{
    if (MSTK_CallBack != NULL)
    {
        MSTK_CallBack();
    }
    volatile u32 temp = GET_BIT(MSTK->MSTK_CTRL, COUNTFLAG_MSTK); 
}


