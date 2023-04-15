
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
#include "../include/RCC.h"
#include "../include/RCC_prv.h"


void RCC_EnableHSI(void)
{
	u32 LOC_u8TempReg=0;
	SET_BIT(RCC -> RCC_CR, HSION);
	while(BIT_IS_CLEAR(RCC -> RCC_CR, HSIRDY)); //Polling until HSI is ready.
	CLR_BIT(LOC_u8TempReg, SW0);
	CLR_BIT(LOC_u8TempReg, SW1);
	RCC -> RCC_CFGR=LOC_u8TempReg;
}


void RCC_EnableHSE(void)
{
	u32 LOC_u8TempReg=0;
	SET_BIT(RCC -> RCC_CR, HSEON);
	while(BIT_IS_CLEAR(RCC -> RCC_CR, HSERDY)); //Polling until HSE is ready.
	SET_BIT(LOC_u8TempReg, SW0);
	CLR_BIT(LOC_u8TempReg, SW1);
	RCC -> RCC_CFGR=LOC_u8TempReg;
}


void RCC_EnablePLL(u8 RCC_PLLCLKSource, u32 RCC_PLLValue)
{
	u32 LOC_u32TimeOut=0;
	 RCC->RCC_PLLCFGR=0;
    RCC->RCC_PLLCFGR=RCC_PLLValue;



	SET_BIT(RCC -> RCC_CR, PLLON); //Enable PLL.
	while(BIT_IS_CLEAR(RCC -> RCC_CR, PLLRDY)) //Polling until PLL is ready.
	{
		LOC_u32TimeOut++;
				if ( LOC_u32TimeOut == 10000 )
				{
					/* Time Out  */
				}

	}

	switch(RCC_PLLCLKSource){
	case HSI:
		CLR_BIT(RCC -> RCC_PLLCFGR, PLLSRC);
		break;

	case HSE:
		SET_BIT(RCC -> RCC_PLLCFGR, PLLSRC);

		break;
	default :
		// Error Message
		break;
	}

}



void AHB_Prescaler(u8 AHB_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFFF0F) | (AHB_PrescalerValue << HPRE0);
}

void APB1_Prescaler(u8 APB1_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFE3FF) | (APB1_PrescalerValue << PRE10);
}

void APB2_Prescaler(u8 APB2_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFF1FFF) | (APB2_PrescalerValue << PRE20);
}


RCC_tenuErrorStatus RCC_EnableCLK(u8 peripheralId)
{
	RCC_tenuErrorStatus LOC_enuState=RCC_enuOK;

	if(peripheralId<PerNUM)
	{
		if(PERIPHERAL_IN_RCC_AHB1ENR)
		{ //Check if this HW module is in RCC_AHBENR Register.
			SET_BIT(RCC -> RCC_AHB1ENR, peripheralId);
		}
		else if(PERIPHERAL_IN_RCC_AHB2ENR)
		{
			peripheralId %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 32
			SET_BIT(RCC -> RCC_AHB2ENR, peripheralId);
		}
		else if(PERIPHERAL_IN_RCC_APB2ENR)
		{
			peripheralId %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 32
			SET_BIT(RCC -> RCC_APB2ENR, peripheralId);
		}
		else if(PERIPHERAL_IN_RCC_APB1ENR)
		{
			peripheralId %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 96
			SET_BIT(RCC -> RCC_APB1ENR, peripheralId);
		}

	}
	else
	{
		LOC_enuState=RCC_Invalid_PerID;
	}

	return LOC_enuState;
}



RCC_tenuErrorStatus RCC_DisableCLK(u8 peripheralId)
{
	RCC_tenuErrorStatus LOC_enuState=RCC_enuOK;

	if(peripheralId<PerNUM)
	{
		if(PERIPHERAL_IN_RCC_AHB1ENR)
		{ //Check if this HW module is in RCC_AHBENR Register.
			CLR_BIT(RCC -> RCC_AHB1ENR, peripheralId);
		}
		else if(PERIPHERAL_IN_RCC_AHB2ENR)
		{
			peripheralId %= SIZE_OF_REGISTER;
			CLR_BIT(RCC -> RCC_AHB2ENR, peripheralId);
		}
		else if(PERIPHERAL_IN_RCC_APB2ENR)
		{
			peripheralId %= SIZE_OF_REGISTER;
			CLR_BIT(RCC -> RCC_APB2ENR, peripheralId);
		}
		else if(PERIPHERAL_IN_RCC_APB1ENR)
		{
			peripheralId %= SIZE_OF_REGISTER;
			CLR_BIT(RCC -> RCC_APB1ENR, peripheralId);
		}

	}
	else
	{
		LOC_enuState=RCC_Invalid_PerID;
	}

	return LOC_enuState;

}


void RCC_Config(void){

#if(RCC_CLK_SRC==Enable_HSI)
	RCC_EnableHSI();
#elif(RCC_CLK_SRC==Enable_HSE)
	RCC_EnableHSE();
#elif(RCC_CLK_SRC==Enable_PLL)

	RCC_EnablePLL(PLL_CLK_Source, ((PLL_DIVISION_FACTOR_M) | (PLL_MULTIPLICATION_FACTOR_N<<6)|(PLL_DIVISION_FACTOR_P<<16)|(PLL_DIVISION_FACTOR_Q<<24)));
#else
	/* Error message: No system clock is enabled */
#endif


#if(Enable_AHB)
	AHB_Prescaler(AHB_Prescaler_Factor);
#endif


#if(Enable_APB1)
	APB1_Prescaler(APB1_Prescaler_Factor);
#endif

#if(Enable_APB2)
	APB2_Prescaler(APB2_Prescaler_Factor);
#endif


}












