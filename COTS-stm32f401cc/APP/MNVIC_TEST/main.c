#include "MGPIO.h"
#include "STD_TYPES.h"
#include "MNVIC.h"

int main(void) {





    MGPIO_voidInit();
    MGPIO_enuSetPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT_PUSH_PULL);
    MGPIO_enuSetPinMode(MGPIO_PORTB, MGPIO_PIN2, MGPIO_OUTPUT_PUSH_PULL);
    MGPIO_enuSetPinMode(MGPIO_PORTB, MGPIO_PIN6, MGPIO_OUTPUT_PUSH_PULL);
    MGPIO_enuSetPinMode(MGPIO_PORTB, MGPIO_PIN5, MGPIO_OUTPUT_PUSH_PULL);


         MNVIC_EnableIRQ(EXTI0);
         MNVIC_EnableIRQ(EXTI1);

         SetPendingIRQ(EXTI0);


        MNVIC_enuSetPriority(EXTI0, 0);
        MNVIC_enuSetPriority(EXTI1, 1);
        
        
        if(GetPendingIRQ(EXTI1))
        {
           MGPIO_enuSetPinValue_Atomic(MGPIO_PORTB, MGPIO_PIN6, MGPIO_HIGH);
        }

        if(GetPendingIRQ(EXTI0))
         {
            MGPIO_enuSetPinValue_Atomic(MGPIO_PORTA, MGPIO_PIN0, MGPIO_HIGH);
         }


   
    while (1) 
    {

    }
    return 0;

}


void EXTI0_IRQHandler(void)
{
    SetPendingIRQ(EXTI1);
    MGPIO_enuSetPinValue_Atomic(MGPIO_PORTB, MGPIO_PIN2, MGPIO_HIGH);

}

void EXTI1_IRQHandler(void)
{
    MGPIO_enuSetPinValue_Atomic(MGPIO_PORTB, MGPIO_PIN5, MGPIO_HIGH);

}