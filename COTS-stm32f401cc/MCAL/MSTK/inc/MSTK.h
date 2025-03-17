#ifndef _MSTK_H
#define _MSTK_H



#define MAX_TICKS 0x00FFFFFF /*24-bit resolution*/

typedef enum {
    MSTK_enuOK,          
    MSTK_enuNOK,            
    MSTK_enuAlreadyEnabled, 
    MSTK_enuAlreadyDisabled,
    MSTK_enuConfigError,   
    MSTK_enuHWError         
} MSTK_enuErrorStatus_t;


typedef enum {
    MSTK_AHB_DIVIDED_BY_8,
    MSTK_AHB_NOT_DIVIDED
}MSTK_enuClockSource_t;





void MSTK_voidInit(void);
MSTK_enuErrorStatus_t MSTK_enuSetCallBack(void (*Copy_ptr)(void));
MSTK_enuErrorStatus_t MSTK_enuSetBusyWait(u32 Copy_u32Ticks);
MSTK_enuErrorStatus_t MSTK_enuSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
MSTK_enuErrorStatus_t MSTK_enuSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
MSTK_enuErrorStatus_t MSTK_enuStopInterval(void);
MSTK_enuErrorStatus_t MSTK_enuSetClockSource(MSTK_enuClockSource_t Copy_enuClockSource);
MSTK_enuErrorStatus_t MSTK_GetElapsedTime(u32 *Copy_u32ElapsedTime);
MSTK_enuErrorStatus_t MSTK_GetRemainingTime(u32 *Copy_u32RemainingTime);

void SysTick_Handler(void);



#endif