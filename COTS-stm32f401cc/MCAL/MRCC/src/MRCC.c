#include "MRCC.h"
#include "MRCC_private.h"
#include "STD_TYPES.h"


RCC_Registers_t* RCC = (RCC_Registers_t*) RCC_BASE_ADDRESS;


RCC_enuErrorStatus_t RCC_enuEnableClk(RCC_enuCLK_Types_t Copy_enuCLK_type)
{

      RCC_enuErrorStatus_t RET_enuStatus = RCC_enuOK;
      u32 Loc_Time_out = 500;
      u32 Loc_CheckClkReady;

      
        switch (Copy_enuCLK_type)
        { 
        case RCC_enu_HSI:
            Loc_CheckClkReady = (RCC->RCC_CR & RCC_HSI_RDY_MASK); 
            RCC->RCC_CR |=RCC_HSI_ON_MASK;          /* RCC -> RCC_CR |=(1<<0) */  

            while(!(Loc_CheckClkReady) && Loc_Time_out--)
            {   
                Loc_CheckClkReady = (RCC->RCC_CR & RCC_HSI_RDY_MASK);
            }
            if(!Loc_CheckClkReady)
            {
                RET_enuStatus = RCC_enuNOK;
            }
            break;
        case RCC_enu_HSE:
            Loc_CheckClkReady = (RCC->RCC_CR & RCC_HSE_RDY_MASK); 
            RCC-> RCC_CR |=RCC_HSE_ON_MASK;        /* RCC -> RCC_CR |=(1<<16) */  

            while(!(Loc_CheckClkReady) && Loc_Time_out--)
            {   
                Loc_CheckClkReady = (RCC->RCC_CR & RCC_HSE_RDY_MASK);
            }
            if(!Loc_CheckClkReady)
            {
                RET_enuStatus = RCC_enuNOK;
            }
            break;
        case RCC_enu_PLL:
            Loc_CheckClkReady = (RCC->RCC_CR & RCC_PLL_RDY_MASK); 
            RCC-> RCC_CR |=RCC_PLL_ON_MASK;        /* RCC -> RCC_CR |=(1<<24) */

             while(!(Loc_CheckClkReady) && Loc_Time_out--)
            {   
                Loc_CheckClkReady = (RCC->RCC_CR & RCC_PLL_RDY_MASK);
            }
            if(!Loc_CheckClkReady)
            {
                RET_enuStatus = RCC_enuNOK;
            }
            break;
        
        default:
        RET_enuStatus = RCC_enuNOK;
            break;


        }

            return RET_enuStatus;

}
RCC_enuErrorStatus_t RCC_enuDisableClk(RCC_enuCLK_Types_t Copy_enuCLK_type)
{

      RCC_enuErrorStatus_t RET_enuStatus = RCC_enuOK;
      
        switch (Copy_enuCLK_type)
        { 
        case RCC_enu_HSI:
           // RCC -> RCC_CR &=~(1<<0) 
            RCC-> RCC_CR &=(~RCC_HSI_ON_MASK);
            break;

        case RCC_enu_HSE:
          // RCC -> RCC_CR &=~(1<<16) 
            RCC-> RCC_CR &=(~RCC_HSE_ON_MASK);

            break;
        case RCC_enu_PLL:
           // RCC -> RCC_CR &=~(1<<24) 
            RCC-> RCC_CR &=(~RCC_PLL_ON_MASK);
            break;
        default:
        RET_enuStatus = RCC_enuNOK;
            break;

        }

            return RET_enuStatus;

}

RCC_enuErrorStatus_t RCC_enuGetClkStatus(RCC_enuCLK_Types_t Copy_enuCLK_type, u32 *Add_ret)
{
     RCC_enuErrorStatus_t RET_enuStatus = RCC_enuOK;

     if(Add_ret==NULL)
     {
        RET_enuStatus = RCC_enuNOK;

     }

     else
     {
        switch (Copy_enuCLK_type)
        { 
        case RCC_enu_HSI:
         *Add_ret = (RCC->RCC_CR & RCC_HSI_RDY_MASK)>>2;
            break;
        case RCC_enu_HSE:
          *Add_ret = (RCC->RCC_CR & RCC_HSE_RDY_MASK)>>17;
            break;
        case RCC_enu_PLL:
          *Add_ret = (RCC->RCC_CR & RCC_PLL_RDY_MASK)>>25;
            break;
        default:
        RET_enuStatus = RCC_enuNOK;
            break;
        }
     }
            return RET_enuStatus;


}


RCC_enuErrorStatus_t RCC_enuSysClkSelection(RCC_enuCLK_Types_t Copy_enuCLK_type)
{
        
      RCC_enuErrorStatus_t RET_enuStatus = RCC_enuOK;
          u32 Loc_CheckClkON;
          u32 temp;
     RET_enuStatus = RCC_enuGetClkStatus(Copy_enuCLK_type, &Loc_CheckClkON);

        if(!Loc_CheckClkON)
        {
            RET_enuStatus = RCC_enuNOK;
        }
        else
        {
                switch (Copy_enuCLK_type)
                { 
                case RCC_enu_HSI:
                   temp = ((RCC->RCC_CR&RCC_SW_MASK)|0); /*RCC->RCC_CFGR &= RCC_SELECT_HSI;*/            
                    break;

                case RCC_enu_HSE:
                   temp = ((RCC->RCC_CR&RCC_SW_MASK)|1); /*RCC->RCC_CFGR = RCC_SELECT_HSE;*/            
                    break;

                case RCC_enu_PLL:
                   temp = ((RCC->RCC_CR&RCC_SW_MASK)|2); /*RCC->RCC_CFGR = RCC_SELECT_PLL;*/            
                    break;

                default:
                RET_enuStatus = RCC_enuNOK;
                    break;
                }
               RCC->RCC_CFGR = temp;
    }
                        return RET_enuStatus;

}
RCC_enuErrorStatus_t RCC_enuSetPLLCfg(RCC_PLL_CFG_t* PLL_CFG, u32 HSE_Freq)
{
    RCC_enuErrorStatus_t RET_enuStatus = RCC_enuOK;
    u32 Loc_CheckClkON;
    u32 Loc_CheckPLLON;
    u32 F_IN; 
    u32 F_VCO; 

    if (HSE_Freq < 4000000 || HSE_Freq > 26000000) { 
        return RCC_enuNOK; 
    }

    Loc_CheckClkON = RCC_enuGetClkStatus(PLL_CFG->SysClk, &Loc_CheckClkON);
    Loc_CheckPLLON = RCC_enuGetClkStatus(RCC_enu_PLL, &Loc_CheckPLLON);

    if (PLL_CFG == NULL)
     {
        RET_enuStatus = RCC_enuNOK;
    } 
    else if (Loc_CheckPLLON) 
    {
        RET_enuStatus = RCC_enuNOK;
    } 
    else if (!Loc_CheckClkON) 
    {
        RET_enuStatus = RCC_enuNOK;
    } 
    else 
    {

        if (PLL_CFG->SysClk == RCC_enu_HSI)
         {
            F_IN = RCC_HSI_FREQ; 
            RCC->RCC_PLLCFGR &= ~RCC_PLL_SYSCLK_MASK;
        }

         else if (PLL_CFG->SysClk == RCC_enu_HSE)
          {
            F_IN = HSE_Freq; 
            RCC->RCC_PLLCFGR |= RCC_PLL_SYSCLK_MASK;
        } 
        else 
        {
            RET_enuStatus = RCC_enuNOK;
        }

        F_VCO = (F_IN / PLL_CFG->M) * PLL_CFG->N;

        if (F_VCO < 96000000 || F_VCO > 432000000) 
        { 
            RET_enuStatus = RCC_enuNOK;
        }

        else if (PLL_CFG->Q > 15 || PLL_CFG->Q < 2)
         {
            RET_enuStatus = RCC_enuNOK;
        }
         else if (PLL_CFG->M > 63 || PLL_CFG->M < 2) 
         {
            RET_enuStatus = RCC_enuNOK;
        }
         else if (PLL_CFG->N > 432 || PLL_CFG->N < 192)
          {
            RET_enuStatus = RCC_enuNOK;
        }
         else
          {

            switch (PLL_CFG->P)
             {
                case 2:
                    RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_PLL_P_MASK) | RCC_PLL_P_2_MASK;
                    break;
                case 4:
                    RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_PLL_P_MASK) | RCC_PLL_P_4_MASK;
                    break;
                case 6:
                    RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_PLL_P_MASK) | RCC_PLL_P_6_MASK;
                    break;
                case 8:
                    RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_PLL_P_MASK) | RCC_PLL_P_8_MASK;
                    break;
                default:
                    RET_enuStatus = RCC_enuNOK;
                    break;
            }

            RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & RCC_PLL_N_MASK) | (PLL_CFG->N << 6);
            RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & RCC_PLL_M_MASK) | (PLL_CFG->M << 0);
            RCC->RCC_PLLCFGR = (RCC->RCC_PLLCFGR & RCC_PLL_Q_MASK) | (PLL_CFG->Q << 24);
        }
    }

    return RET_enuStatus;
}




RCC_enuErrorStatus_t RCC_enuControlPeripheralClk(RCC_BUS_t RCC_BUS, u32 RCC_Peripheral, u8 status)
{
    RCC_enuErrorStatus_t RET_enuStatus = RCC_enuOK;

    switch (RCC_BUS)
    {
    case RCC_BUS_AHB1:
        if (status == RCC_ENABLE) {
            RCC->RCC_AHB1ENR |= RCC_Peripheral; // Enable peripheral clock
        } else {
            RCC->RCC_AHB1ENR &= ~RCC_Peripheral; // Disable peripheral clock
        }
        break;

    case RCC_BUS_AHB2:
        if (status == RCC_ENABLE) {
            RCC->RCC_AHB2ENR |= RCC_Peripheral; // Enable peripheral clock
        } else {
            RCC->RCC_AHB2ENR &= ~RCC_Peripheral; // Disable peripheral clock
        }
        break;

    case RCC_BUS_APB1:
        if (status == RCC_ENABLE) {
            RCC->RCC_APB1ENR |= RCC_Peripheral; // Enable peripheral clock
        } else {
            RCC->RCC_APB1ENR &= ~RCC_Peripheral; // Disable peripheral clock
        }
        break;

    case RCC_BUS_APB2:
        if (status == RCC_ENABLE) {
            RCC->RCC_APB2ENR |= RCC_Peripheral; // Enable peripheral clock
        } else {
            RCC->RCC_APB2ENR &= ~RCC_Peripheral; // Disable peripheral clock
        }
        break;

    default:
        RET_enuStatus = RCC_enuNOK;
        break;
    }

    return RET_enuStatus;
}


