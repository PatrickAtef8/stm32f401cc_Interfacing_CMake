#ifndef MGPIO_PRIVATE_H
#define _MGPIO_PRIVATE_H

#include "STD_TYPES.h"

#define MGPIOA_BASE_ADDRESS              0x40020000
#define MGPIOB_BASE_ADDRESS              0x40020400
#define MGPIOC_BASE_ADDRESS              0x40020800
#define MGPIOD_BASE_ADDRESS              0x40020C00
#define MGPIOE_BASE_ADDRESS              0x40021000
#define MGPIOH_BASE_ADDRESS              0x40021C00

#define MGPIOA_INPUT_MASK                0x00000000
#define MGPIOA_OUTPUT_MASK               0x00000001
#define MGPIOA_AF_MASK                   0x00000002
#define MGPIOA_ANALOG_MASK               0x00000003



#define MGPIO_LOW_SPEED_MASK             0x00000000
#define MGPIO_MEDIUM_SPEED_MASK          0x00000001
#define MGPIO_HIGH_SPEED_MASK            0x00000002
#define MGPIO_VERY_HIGH_SPEED_MASK       0x00000003



#define MGPIO_OUTPUT_PUSH_PULL_MASK      0x00000000
#define MGPIO_OUTPUT_OPEN_DRAIN_MASK     0x00000001


#define MGPIO_NO_PULL_UP_DOWN_MASK       0x00000000
#define MGPIO_PULL_UP_MASK               0x00000001
#define MGPIO_PULL_DOWN_MASK             0x00000002




#define GPIO_MODER_PIN0_MASK   0xFFFFFFFC  // Mask for Pin 0 (clear bits 0 and 1)
#define GPIO_MODER_PIN1_MASK   0xFFFFFFF3  // Mask for Pin 1 (clear bits 2 and 3)
#define GPIO_MODER_PIN2_MASK   0xFFFFFFCF  // Mask for Pin 2 (clear bits 4 and 5)
#define GPIO_MODER_PIN3_MASK   0xFFFFFF3F  // Mask for Pin 3 (clear bits 6 and 7)
#define GPIO_MODER_PIN4_MASK   0xFFFFFCFF  // Mask for Pin 4 (clear bits 8 and 9)
#define GPIO_MODER_PIN5_MASK   0xFFFFF3FF  // Mask for Pin 5 (clear bits 10 and 11)
#define GPIO_MODER_PIN6_MASK   0xFFFFCFFF  // Mask for Pin 6 (clear bits 12 and 13)
#define GPIO_MODER_PIN7_MASK   0xFFFF3FFF  // Mask for Pin 7 (clear bits 14 and 15)
#define GPIO_MODER_PIN8_MASK   0xFFFCFFFF  // Mask for Pin 8 (clear bits 16 and 17)
#define GPIO_MODER_PIN9_MASK   0xFFF3FFFF  // Mask for Pin 9 (clear bits 18 and 19)
#define GPIO_MODER_PIN10_MASK  0xFFCFFFFF  // Mask for Pin 10 (clear bits 20 and 21)
#define GPIO_MODER_PIN11_MASK  0xFF3FFFFF  // Mask for Pin 11 (clear bits 22 and 23)
#define GPIO_MODER_PIN12_MASK  0xFCFFFFFF  // Mask for Pin 12 (clear bits 24 and 25)
#define GPIO_MODER_PIN13_MASK  0xF3FFFFFF  // Mask for Pin 13 (clear bits 26 and 27)
#define GPIO_MODER_PIN14_MASK  0xCFFFFFFF  // Mask for Pin 14 (clear bits 28 and 29)
#define GPIO_MODER_PIN15_MASK  0x3FFFFFFF  // Mask for Pin 15 (clear bits 30 and 31)


typedef struct 
{
    volatile u32 MGPIO_MODER;
    volatile u32 MGPIO_OTYPER;
    volatile u32 MGPIO_OSPEEDR;
    volatile u32 MGPIO_PUPDR;
    volatile u32 MGPIO_IDR;
    volatile u32 MGPIO_ODR;
    volatile u32 MGPIO_BSRR;
    volatile u32 MGPIO_LCKR;
    volatile u32 MGPIO_AFRL;
    volatile u32 MGPIO_AFRH;
    
}MGPIO_registers_t;

const u32 PinMasks[]= 
{
    GPIO_MODER_PIN0_MASK,
    GPIO_MODER_PIN1_MASK,
    GPIO_MODER_PIN2_MASK,
    GPIO_MODER_PIN3_MASK,
    GPIO_MODER_PIN4_MASK,
    GPIO_MODER_PIN5_MASK,
    GPIO_MODER_PIN6_MASK,
    GPIO_MODER_PIN7_MASK,
    GPIO_MODER_PIN8_MASK,
    GPIO_MODER_PIN9_MASK,
    GPIO_MODER_PIN10_MASK,
    GPIO_MODER_PIN11_MASK,
    GPIO_MODER_PIN12_MASK,
    GPIO_MODER_PIN13_MASK,
    GPIO_MODER_PIN14_MASK,
    GPIO_MODER_PIN15_MASK
};

const u32 MODER_Masks[] = 
{
    MGPIOA_INPUT_MASK, // 0
    MGPIOA_OUTPUT_MASK, // 1
    MGPIOA_AF_MASK,  // 2
    MGPIOA_ANALOG_MASK // 3
};

const u32 OTypeMasks[] = 
{
    MGPIO_OUTPUT_PUSH_PULL_MASK, // 0 
    MGPIO_OUTPUT_OPEN_DRAIN_MASK // 1
};


const u32 SpeedMasks[] = 
{
    MGPIO_LOW_SPEED_MASK,
    MGPIO_MEDIUM_SPEED_MASK,
    MGPIO_HIGH_SPEED_MASK,
    MGPIO_VERY_HIGH_SPEED_MASK
};

const u32 PUPDMasks[] = 
{
    MGPIO_NO_PULL_UP_DOWN_MASK,
    MGPIO_PULL_UP_MASK,
    MGPIO_PULL_DOWN_MASK
};


#endif