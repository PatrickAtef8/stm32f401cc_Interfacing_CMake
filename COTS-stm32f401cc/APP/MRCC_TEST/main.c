#include "MRCC.h"
#include "MRCC_private.h"
#include "STD_TYPES.h"

#define GPIOA_BASE_ADDR 0x40020000U  // GPIOA base address (you can change this according to your MCU)
#define GPIOA_MODER      (*(volatile u32*)(GPIOA_BASE_ADDR + 0x00))  // GPIOA mode register
#define GPIOA_ODR        (*(volatile u32*)(GPIOA_BASE_ADDR + 0x14))  // GPIOA output data register

#define GPIO_PIN_5       (1 << 5)  // GPIO pin 5



int main(void)
{
    RCC_enuErrorStatus_t status;
    u32 clkStatus;

    // Step 1: Enable the HSI clock
    status = RCC_enuEnableClk(RCC_enu_HSI);
    if (status != RCC_enuOK)
    {
        // Handle error, possibly blink an LED or indicate failure
        while(1);  // Infinite loop to indicate failure
    }

    // Step 2: Check if the HSI clock is ready
    // status = RCC_enuGetClkStatus(RCC_enu_HSI, &clkStatus);
    // if (status != RCC_enuOK || clkStatus == 0)
    // {
    //     // Handle error, possibly blink an LED or indicate failure
    //     while(1);  // Infinite loop to indicate failure
    // }

    // Step 3: Select HSI as the system clock
    // status = RCC_enuSysClkSelection(RCC_enu_HSI);
    // if (status != RCC_enuOK)
    // {
    //     // Handle error, possibly blink an LED or indicate failure
    //     while(1);  // Infinite loop to indicate failure
    // }

    // Step 4: Enable GPIOA clock (AHB1 peripheral clock for GPIOA)
    status = RCC_enuControlPeripheralClk(RCC_BUS_AHB1, RCC_AHB1_GPIOA, RCC_ENABLE);
    if (status != RCC_enuOK)
    {
        // Handle error, possibly blink an LED or indicate failure
        while(1);  // Infinite loop to indicate failure
    }

    // Step 5: Configure GPIOA pin 5 as output
    // Set MODER[10:9] = 01 (output mode for pin 5)
    GPIOA_MODER &= ~(0x3 << 10);   // Clear bits for pin 5
    GPIOA_MODER |= (0x1 << 10);    // Set pin 5 to output mode

    // Step 6: Toggle GPIOA pin 5 to simulate LED blink
    while (1)
    {
        // Toggle pin 5 by flipping the bit in ODR register
        GPIOA_ODR ^= GPIO_PIN_5;  // Toggle pin 5
        for (int i = 0; i < 1000000; i++);  // Simple delay loop
    }

    return 0;  // Never reached
}
