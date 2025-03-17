#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSTK.h"
#include "MRCC.h"
#include "MGPIO.h"

#define LED_PIN  MGPIO_PIN0
#define LED_PORT MGPIO_PORTA

#define TIME_MS  1000000 


void toggle_led(void);

void main(void)
{
   MGPIO_voidInit();

        MGPIO_enuSetPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT_PUSH_PULL);
        MGPIO_enuSetPinMode(MGPIO_PORTB, MGPIO_PIN2, MGPIO_OUTPUT_PUSH_PULL);
   
    MSTK_voidInit();
  
    MSTK_enuSetIntervalPeriodic(TIME_MS, toggle_led);

    while (1) 
    {
  
    }
}

void toggle_led(void)
{
    static u8 flag = 0;
    if (flag == 0)
    {
        MGPIO_enuSetPinValue_Atomic(LED_PORT, LED_PIN, MGPIO_HIGH);
        flag = 1;
    }
    else
    {
        MGPIO_enuSetPinValue_Atomic(LED_PORT, LED_PIN, MGPIO_LOW);
        flag = 0;
    }


    
}
