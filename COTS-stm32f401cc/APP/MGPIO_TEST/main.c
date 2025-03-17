#include "MGPIO.h"
#include "STD_TYPES.h"

int main(void) {


    u32 button;
    MGPIO_voidInit();
    MGPIO_enuSetPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT_PUSH_PULL);
    MGPIO_enuSetPinMode(MGPIO_PORTB, MGPIO_PIN2, MGPIO_OUTPUT_PUSH_PULL);
    
         MGPIO_enuSetPinValue_Atomic(MGPIO_PORTA, MGPIO_PIN0, MGPIO_HIGH);
         MGPIO_enuSetPinValue_Atomic(MGPIO_PORTB, MGPIO_PIN2, MGPIO_HIGH);
   
    while (1) 
    {


         


    }
    return 0;
}
