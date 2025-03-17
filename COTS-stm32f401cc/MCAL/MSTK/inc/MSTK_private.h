#ifndef _MSTK_PRIVATE_H
#define _MSTK_PRIVATE_H


#define MSTK_BASE_ADDRESS 0xE000E010;



typedef struct{
    volatile u32 MSTK_CTRL;
    volatile u32 MSTK_LOAD;
    volatile u32 MSTK_VAL;
    volatile u32 MSTK_CALIB;

}MSTK_REG_t;



typedef enum{
    ENABLE_MSTK = 0,
    TICKINT_MSTK = 1,
    CLKSOURCE_MSTK = 2,
    COUNTFLAG_MSTK = 16
}CTRL_REG_BIT_t;





#endif