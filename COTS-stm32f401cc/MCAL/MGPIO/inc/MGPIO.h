#ifndef _MGPIO_PRIVATE_H
#define _MGPIO_PRIVATE_H

#include "STD_TYPES.h"

typedef enum
{
    MGPIO_INPUT,
    MGPIO_OUTPUT
}MGPIO_enuDirection_t;


typedef enum
{
    MGPIO_INPUT_ANALOG,
    MGPIO_INPUT_FLOATING,
    MGPIO_INPUT_PULL_UP,
    MGPIO_INPUT_PULL_DOWN,
    MGPIO_OUTPUT_PUSH_PULL,
    MGPIO_OUTPUT_OPEN_DRAIN,
    MGPIO_AF_PUSH_PULL,
    MGPIO_AF_OPEN_DRAIN
}MGPIO_enuMode_t;

typedef enum
{
    MGPIO_SPEED_2MHZ,
    MGPIO_SPEED_25MHZ,
    MGPIO_SPEED_50MHZ,
    MGPIO_SPEED_100MHZ
}MGPIO_enuSpeed_t;

typedef enum
{
    MGPIO_PIN0,
    MGPIO_PIN1,
    MGPIO_PIN2,
    MGPIO_PIN3,
    MGPIO_PIN4,
    MGPIO_PIN5,
    MGPIO_PIN6,
    MGPIO_PIN7,
    MGPIO_PIN8,
    MGPIO_PIN9,
    MGPIO_PIN10,
    MGPIO_PIN11,
    MGPIO_PIN12,
    MGPIO_PIN13,
    MGPIO_PIN14,
    MGPIO_PIN15
}MGPIO_enuPin_t;

typedef enum
{
    MGPIO_PORTA,
    MGPIO_PORTB,
    MGPIO_PORTC,
    MGPIO_PORTD,
    MGPIO_PORTE,
    MGPIO_PORTH
}MGPIO_enuPort_t;


typedef enum
{
    MGPIO_LOW,
    MGPIO_HIGH
}MGPIO_enuValue_t;

typedef enum

{
    MGPIO_enuOK,
    MGPIO_enuNOK

}MGPIO_enuErrorStatus_t;

typedef enum 
{
    MGPIO_MODER_INPUT ,
    MGPIO_MODER_OUTPUT,
    MGPIO_MODER_AF,
    MGPIO_MODER_ANALOG 

}MGPIO_MODER_OPTIONS_t;



void MGPIO_voidInit(void);
MGPIO_enuErrorStatus_t MGPIO_enuSetPinMode(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, MGPIO_enuMode_t Copy_enuMode);
MGPIO_enuErrorStatus_t MGPIO_enuSetPinSpeed(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, MGPIO_enuSpeed_t Copy_enuSpeed);   
MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue_Atomic(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, MGPIO_enuValue_t Copy_enuValue);
MGPIO_enuErrorStatus_t MGPIO_enuGetPinValue(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, u32* Copy_enuValue);
void MGPIO_enuTogglePin(void);
#endif