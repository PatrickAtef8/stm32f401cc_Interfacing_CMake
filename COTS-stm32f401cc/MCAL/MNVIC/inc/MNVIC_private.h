#ifndef MNVIC_PRIVATE_H
#define MNVIC_PRIVATE_H
 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define MNVIC_BASE_ADDRESS 0xE000E100

#define SCB_BASE_ADDRESS 0xE000ED00


#define MNVIC_IRQ_COUNT      (240U)
#define MNVIC_REG_COUNT      (8U)
#define MNVIC_BITS_PER_REG   (32U)


#define MNVIC_GROUP_4_SUB_0  0x05FA0300 //el 4 bit yb2o group w mafesh sub group
#define MNVIC_GROUP_3_SUB_1  0x05FA0400 //el 3 bit yb2o group w 1 bit sub group
#define MNVIC_GROUP_2_SUB_2  0x05FA0500 //el 2 bit yb2o group w 2 bit sub group
#define MNVIC_GROUP_1_SUB_3  0x05FA0600 //el 1 bit yb2o group w 3 bit sub group
#define MNVIC_GROUP_0_SUB_4  0x05FA0700 // 4 bit sub group w mafesh group


typedef struct {
    volatile u32 MNVIC_ISER[8];  
    volatile u32 MNVIC_RESERVED0[24]; 
    volatile u32 MNVIC_ICER[8]; 
    volatile u32 MNVIC_RESERVED1[24];
    volatile u32 MNVIC_ISPR[8];  
    volatile u32 MNVIC_RESERVED2[24]; 
    volatile u32 MNVIC_ICPR[8]; 
    volatile u32 MNVIC_RESERVED3[24]; 
    volatile u32 MNVIC_IABR[8];  
    volatile u32 MNVIC_RESERVED4[56]; 
    volatile u8  MNVIC_IPR[240]; 
    volatile u32 MNVIC_RESERVED5[644]; 
    volatile u32 MNVIC_STIR;     
} MNVIC_REG_t;
                                                                             
                                                                             
typedef struct {                                            
    volatile u32 MNVIC_CPUID;                                                                          
    volatile u32 MNVIC_ICSR;                                                                                     
    volatile u32 MNVIC_VTOR;                                                                                    
    volatile u32 MNVIC_AIRCR;                                                                                     
    volatile u32 MNVIC_SCR;                                                                                
    volatile u32 MNVIC_CCR;                                                                                       
    volatile u8  MNVIC_SHPR[12];                                                                                 
    volatile u32 MNVIC_SHCRS;                                                                                   
    volatile u32 MNVIC_CFSR;                                                                                      
    volatile u32 MNVIC_HFSR;                                                                                 
    volatile u32 MNVIC_DFSR;                                                                                   
    volatile u32 MNVIC_MMFAR;                                                                                    
    volatile u32 MNVIC_BFAR;                                                                                 
    volatile u32 MNVIC_AFSR;                                                                                      
} SCB_Type;                                                                             




#endif
