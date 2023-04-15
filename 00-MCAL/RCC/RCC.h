#ifndef _RCC_H
#define _RCC_H


typedef enum{

RCC_enuOK = 0,
RCC_enuNotOK,
RCC_Invalid_PerID
	
}RCC_tenuErrorStatus;



/***************************** PARAMS DEFINITION **************************************/

enum{
	/* These are the values that are used to choose Input
	   Clock source of PLL.
	  You can choose one value to pass it to:
	   void RCC_EnablePLL(u8 PLL_CLKSource, u8 PLL_Value)
	   as the first argument.
	  */
	HSI,
	HSE
};

/* * * * * * * * * * * * * * *
 * Main PLLQ division factor for USB OTG FS *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the Main PLLQ division factor for USB OTG FS
	  You can choose one value to pass it to:
	   void RCC_EnablePLL(u8 PLL_CLKSource, u8 PLL_Value)
	   as the second argument.
	  */

	PLL_input_clock_Q2=2,
	PLL_input_clock_Q3,
	PLL_input_clock_Q4,
	PLL_input_clock_Q5,
	PLL_input_clock_Q6,
	PLL_input_clock_Q7,
	PLL_input_clock_Q8,
	PLL_input_clock_Q9,
	PLL_input_clock_Q10,
	PLL_input_clock_Q11,
	PLL_input_clock_Q12,
	PLL_input_clock_Q13,
	PLL_input_clock_Q14,
	PLL_input_clock_Q15,

};

/* * * * * * * * * * * * * * *
 *  Main PLLP division factor for main system clock
 *
 * * * * * * * * * * * * * * */
enum{

	PLL_input_clock_P2=2,

	PLL_input_clock_P4=4,

	PLL_input_clock_P6=6,

	PLL_input_clock_P8=8

};


/* * * * * * * * * * * * * * *
 *   Main PLLN multiplication factor for VCO
 *  192:432
 * * * * * * * * * * * * * * */
enum{

	PLL_input_clock_N192=192,

	PLL_input_clock_N432=432

};


/* * * * * * * * * * * * * * *
 *  Division factor for the main PLLM  and audio PLL (PLLI2S) input clock
 *  you should take value from 2 to 63
 * * * * * * * * * * * * * * */
enum{

	PLL_input_clock_M2=2,

    PLL_input_clock_M63=63,
};


/* * * * * * * * * * * * * * *
 *   RCC_AHB1ENR Registers    *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   RCC_tenuErrorStatus RCC_DisableCLK(uint8 peripheralIdx)
	   RCC_tenuErrorStatus RCC_EnableCLK(uint8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */

	GPIOAEN,
	GPIOBEN,
	GPIOCEN,
	GPIODEN,
	GPIOEEN,
	RES11,
	RES22,
	GPIOHEN,
    RES33,
	RES44,
	RES55,
	RES66,
	CRCEN,
    RES77,
	RES88,
	RES99,
	RES89,
	RES87,
	RES86,
	RES85,
	RES84,
	DMA1EN,
	DMA2EN,

};


/* * * * * * * * * * * * * * *
 *   RCC_AHB2ENR Registers    *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   RCC_tenuErrorStatus RCC_DisableCLK(u8 peripheralIdx)
	   RCC_tenuErrorStatus RCC_EnableCLK(u8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */

	RES844=32,
	RES83,
	RES82,
	RES81,
    RES80,
    RES79,
    RES78,
	OTGFSEN


};


/* * * * * * * * * * * * * * *
 *   RCC_APB1ENR Registers   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   RCC_tenuErrorStatus RCC_DisableCLK(u8 peripheralIdx)
	   RCC_tenuErrorStatus RCC_EnableCLK(u8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	TIM2EN = 64,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	RES1,
	RES2,
	RES3,
	RES4,
	RES5,
	RES6,
	RES7,
	WWDGEN,
	RES8,
	RES9,
	SPI2,
	SPI3,
	RES10,
	USART2EN,
	RES111,
	RES12,
	RES13,
	I2C1EN,
	I2C2EN,
	I2C3EN,
	RES14,
	RES15,
	RES16,
	RES17,
	PWREN,
	RES18,
	RES19,
	RES20

};

/* * * * * * * * * * * * * * *
 *   RCC_APB2ENR Registers   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   RCC_tenuErrorStatus RCC_DisableCLK(u8 peripheralIdx)
	   RCC_tenuErrorStatus RCC_EnableCLK(u8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */

	TIM1EN=96,
	res1,
	res2,
	res3,
	USART1EN,
	USART6EN,
	res4,
	res5,
	ADC1EN,
	res6,
	res7,
	SDIOEN,
	SPI1EN,
	SPI4EN,
	SYSCFGEN,
	res8,
	TIM9EN,
    TIM10EN,
    TIM11EN,
	PerNUM



};



/**************************   APIS  *****************************************/

/* void RCC_EnableHSI(void)
 * Function Description: Configure RCC module to operate in
 *  HSI(High Speed Internal) mode.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_EnableHSI(void);

/* void RCC_EnableHSE(void)
 * Function Description: Configure RCC module to operate in
   HSE(High Speed External) mode.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_EnableHSE(void);

/* void AHB_Prescaler(uint8 AHB_PrescalerValue)
 * Function Description: Set the value of AHB Prescaler.
 * Parameters(In) : AHB_PrescalerValue --> prescaler value.
 * There are three options for AHB_PrescalerValue:
    - AHB_SYSCLK_not_divided
	- AHB_SYSCLK_divided_by_2
	- AHB_SYSCLK_divided_by_4
	- AHB_SYSCLK_divided_by_8
	- AHB_SYSCLK_divided_by_16
	- AHB_SYSCLK_divided_by_64
	- AHB_SYSCLK_divided_by_128
	- AHB_SYSCLK_divided_by_256
	- AHB_SYSCLK_divided_by_512
 * Parameters(Out) : None.
 * */
void AHB_Prescaler(u8 AHB_PrescalerValue);

/* void APB1_Prescaler(uint8 APB1_PrescalerValue)
 * Function Description: Set the value of APB1 Prescaler.
 * Parameters(In) : APB1_PrescalerValue --> prescaler value.
 * There are three options for APB1_PrescalerValue:
	- APB1_HCLK_not_divided
	- APB1_HCLK_divided_by_2
	- APB1_HCLK_divided_by_4
	- APB1_HCLK_divided_by_8
	- APB1_HCLK_divided_by_16
 * Parameters(Out) : None.
 * */
void APB1_Prescaler(u8 APB1_PrescalerValue);


/* void APB2_Prescaler(uint8 APB2_PrescalerValue)
 * Function Description: Set the value of APB2 Prescaler.
 * Parameters(In) : APB2_PrescalerValue --> prescaler value.
 * There are three options for APB2_PrescalerValue:
	- APB2_HCLK_not_divided
	- APB2_HCLK_divided_by_2
	- APB2_HCLK_divided_by_4
	- APB2_HCLK_divided_by_8
	- APB2_HCLK_divided_by_16
 * Parameters(Out) : None.
 * */
void APB2_Prescaler(u8 APB2_PrescalerValue);

/* void RCC_EnablePLL(u8 PLL_CLKSource, u8 PLL_Value)
  Function Description: Configure RCC module to operate in
   PLL(Phase Locked Loop) mode.
   Parameters(In) : - PLL_CLKSource --> The clock source to
   the PLL.
    - PLL_Value --> the values that are used to choose the PLL
      Multiplication factor.
 * There are three options for PLL_CLKSource:
    - Half_HSI
    - Half_HSE
    - HSE
*/

void RCC_EnablePLL(u8 RCC_PLLCLKSource, u32 RCC_PLLValue);



/* void RCC_EnableCLK(u8 peripheralIdx);
 * Function Description: Enable specific hardware module
   in the MC.
 * Parameters(In) : peripheralIdx --> hardware module.
 * Parameters(Out): Function error state
 * There are Multiple options for peripheralIdx I declared them in definitions catagory

*/
RCC_tenuErrorStatus RCC_EnableCLK(u8 peripheralId);

/* void RCC_DisableCLK(u8 peripheralIdx);
 * Function Description: Disable specific hardware module
   in the MC.
 * Parameters(In) : peripheralIdx --> hardware module.
 * Parameters(Out): Function error state
 * There are Multiple options for peripheralIdx I declared them in definitions catagory

*/
RCC_tenuErrorStatus RCC_DisableCLK(u8 peripheralId);


/* void RCC_Config(void)
 * Function Description: Configure RCC based on
   the user configuration.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_Config(void);





















#endif
