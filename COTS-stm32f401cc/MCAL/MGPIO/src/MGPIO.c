#include "MGPIO.h"
#include "MGPIO_private.h"
#include "MRCC.h"
#include "MRCC_private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

MGPIO_registers_t* MGPIOA = (MGPIO_registers_t*) MGPIOA_BASE_ADDRESS;
MGPIO_registers_t* MGPIOB = (MGPIO_registers_t*) MGPIOB_BASE_ADDRESS;
MGPIO_registers_t* MGPIOC = (MGPIO_registers_t*) MGPIOC_BASE_ADDRESS;
MGPIO_registers_t* MGPIOD = (MGPIO_registers_t*) MGPIOD_BASE_ADDRESS;
MGPIO_registers_t* MGPIOE = (MGPIO_registers_t*) MGPIOE_BASE_ADDRESS;
MGPIO_registers_t* MGPIOH = (MGPIO_registers_t*) MGPIOH_BASE_ADDRESS;


void MGPIO_voidInit(void) {
    
    MGPIO_enuErrorStatus_t status;

    status = RCC_enuEnableClk(RCC_enu_HSI);
    if (status != MGPIO_enuOK) {
        while (1);
    }

    status = RCC_enuControlPeripheralClk(RCC_BUS_AHB1, RCC_AHB1_GPIOA, RCC_ENABLE);
    if (status != MGPIO_enuOK) {
        while (1);
    }

    status = RCC_enuControlPeripheralClk(RCC_BUS_AHB1, RCC_AHB1_GPIOB, RCC_ENABLE);
    if (status != MGPIO_enuOK) {
        while (1);
    }
    // status=MGPIO_enuSetPinSpeed(MGPIO_PORTA, MGPIO_PIN5, MGPIO_SPEED_2MHZ);
    // if (status != MGPIO_enuOK) {
    //     while (1);
    // }
}



MGPIO_enuErrorStatus_t MGPIO_enuSetPinMode(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, MGPIO_enuMode_t Copy_enuMode)
{
    MGPIO_enuErrorStatus_t RET_enuStatus = MGPIO_enuOK;
    MGPIO_registers_t* GPIO_Port = NULL;

    switch (Copy_enuPort) {
        case MGPIO_PORTA: GPIO_Port = MGPIOA; break;
        case MGPIO_PORTB: GPIO_Port = MGPIOB; break;
        case MGPIO_PORTC: GPIO_Port = MGPIOC; break;
        case MGPIO_PORTD: GPIO_Port = MGPIOD; break;
        case MGPIO_PORTE: GPIO_Port = MGPIOE; break;
        case MGPIO_PORTH: GPIO_Port = MGPIOH; break;
        default: return MGPIO_enuNOK; 
    }
    if (Copy_enuPin>15 || Copy_enuPin<0)
        {
        RET_enuStatus = MGPIO_enuNOK;
        }

    if (Copy_enuMode == MGPIO_INPUT_ANALOG) 
        {

        GPIO_Port->MGPIO_MODER = PinMasks[Copy_enuPin] | MODER_Masks[MGPIO_MODER_ANALOG] << (Copy_enuPin * 2);

        } 

    else if (Copy_enuMode == MGPIO_OUTPUT_PUSH_PULL || Copy_enuMode == MGPIO_OUTPUT_OPEN_DRAIN) 
        {

        GPIO_Port->MGPIO_MODER = PinMasks[Copy_enuPin] | MODER_Masks[MGPIO_MODER_OUTPUT] << (Copy_enuPin * 2);

        }

    else if (Copy_enuMode == MGPIO_AF_PUSH_PULL || Copy_enuMode == MGPIO_AF_OPEN_DRAIN) 
        {

        GPIO_Port->MGPIO_MODER = PinMasks[Copy_enuPin] | MODER_Masks[MGPIO_MODER_AF] << (Copy_enuPin * 2);

        } 

    else 
        {

        GPIO_Port->MGPIO_MODER = PinMasks[Copy_enuPin] | MODER_Masks[MGPIO_MODER_INPUT] << (Copy_enuPin * 2);

        }

    if (Copy_enuMode == MGPIO_INPUT_FLOATING || Copy_enuMode == MGPIO_INPUT_PULL_UP || Copy_enuMode == MGPIO_INPUT_PULL_DOWN) 

        {

        GPIO_Port->MGPIO_PUPDR = PinMasks[Copy_enuPin] | PUPDMasks[Copy_enuMode] << (Copy_enuPin * 2);

        }

    if (Copy_enuMode == MGPIO_OUTPUT_PUSH_PULL || Copy_enuMode == MGPIO_AF_PUSH_PULL)
        {

        GPIO_Port->MGPIO_OTYPER &= ~(1 << Copy_enuPin);

        } 

    else if (Copy_enuMode == MGPIO_OUTPUT_OPEN_DRAIN || Copy_enuMode == MGPIO_AF_OPEN_DRAIN) 
        {

        GPIO_Port->MGPIO_OTYPER |= (1 << Copy_enuPin);

        }

    return RET_enuStatus;
}



MGPIO_enuErrorStatus_t MGPIO_enuSetPinSpeed(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, MGPIO_enuSpeed_t Copy_enuSpeed)
{
    MGPIO_enuErrorStatus_t RET_enuStatus = MGPIO_enuOK;
    MGPIO_registers_t* GPIO_Port = NULL;

    switch (Copy_enuPort) {
        case MGPIO_PORTA: GPIO_Port = MGPIOA; break;
        case MGPIO_PORTB: GPIO_Port = MGPIOB; break;
        case MGPIO_PORTC: GPIO_Port = MGPIOC; break;
        case MGPIO_PORTD: GPIO_Port = MGPIOD; break;
        case MGPIO_PORTE: GPIO_Port = MGPIOE; break;
        case MGPIO_PORTH: GPIO_Port = MGPIOH; break;
        default: return MGPIO_enuNOK; 
    }
    if(Copy_enuSpeed>MGPIO_SPEED_100MHZ&&Copy_enuSpeed<MGPIO_SPEED_2MHZ)
    {
        RET_enuStatus = MGPIO_enuNOK;
    }
    if (Copy_enuPin>15 || Copy_enuPin<0)
    {
        RET_enuStatus = MGPIO_enuNOK;
    }
    
    GPIO_Port->MGPIO_OSPEEDR = PinMasks[Copy_enuPin] | SpeedMasks[Copy_enuSpeed] << (Copy_enuPin * 2);

    return RET_enuStatus;
    
}
MGPIO_enuErrorStatus_t MGPIO_enuSetPinValue_Atomic(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, MGPIO_enuValue_t Copy_enuValue)
{
    MGPIO_enuErrorStatus_t RET_enuStatus = MGPIO_enuOK;
    MGPIO_registers_t* GPIO_Port = NULL;

    switch (Copy_enuPort) {
        case MGPIO_PORTA: GPIO_Port = MGPIOA; break;
        case MGPIO_PORTB: GPIO_Port = MGPIOB; break;
        case MGPIO_PORTC: GPIO_Port = MGPIOC; break;
        case MGPIO_PORTD: GPIO_Port = MGPIOD; break;
        case MGPIO_PORTE: GPIO_Port = MGPIOE; break;
        case MGPIO_PORTH: GPIO_Port = MGPIOH; break;
        default: return MGPIO_enuNOK; 
    }
    if (Copy_enuPin>15 || Copy_enuPin<0)
    {
        RET_enuStatus = MGPIO_enuNOK;
    }
    if (Copy_enuValue == MGPIO_HIGH) 
    {
        GPIO_Port->MGPIO_BSRR = 1 << Copy_enuPin;
    } 
    else if (Copy_enuValue == MGPIO_LOW) 
    {
        GPIO_Port->MGPIO_BSRR = 1 << (Copy_enuPin + 16);
    } 
    else 
    {
        RET_enuStatus = MGPIO_enuNOK;
    }

    return RET_enuStatus;
}

MGPIO_enuErrorStatus_t MGPIO_enuGetPinValue(MGPIO_enuPort_t Copy_enuPort, MGPIO_enuPin_t Copy_enuPin, u32* Copy_enuValue)
{
    MGPIO_enuErrorStatus_t RET_enuStatus = MGPIO_enuOK;
    MGPIO_registers_t* GPIO_Port = NULL;

    if (Copy_enuValue == NULL)
    {
        return MGPIO_enuNOK;
    }

    switch (Copy_enuPort) {
        case MGPIO_PORTA: GPIO_Port = MGPIOA; break;
        case MGPIO_PORTB: GPIO_Port = MGPIOB; break;
        case MGPIO_PORTC: GPIO_Port = MGPIOC; break;
        case MGPIO_PORTD: GPIO_Port = MGPIOD; break;
        case MGPIO_PORTE: GPIO_Port = MGPIOE; break;
        case MGPIO_PORTH: GPIO_Port = MGPIOH; break;
        default: return MGPIO_enuNOK; 
    }

    if (GPIO_Port == NULL)
    {
        return MGPIO_enuNOK;
    }

    if (Copy_enuPin > 15)
    {
        return MGPIO_enuNOK;
    }

    if (GET_BIT(GPIO_Port->MGPIO_IDR, Copy_enuPin) == 1) 
    {
        *Copy_enuValue = MGPIO_HIGH;
    } 
    else 
    {
        *Copy_enuValue = MGPIO_LOW;
    }

    return RET_enuStatus;
}



void MGPIO_enuTogglePin(void)
{
    MGPIOA->MGPIO_ODR ^= (1 << MGPIO_PIN2); // Toggle
    for (volatile int i = 1000000; i > 0; i--); // Delay

}

