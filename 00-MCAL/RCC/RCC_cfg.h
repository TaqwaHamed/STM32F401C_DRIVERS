/*
 * RCC_cfg.h
 *
 *  Created on: Feb 5, 2023
 *      Author: TAQWA HAMED
 */

#ifndef 01_MCAL_00_RCC_RCC_CFG_H_
#define 01_MCAL_00_RCC_RCC_CFG_H_


/*
   select RCC clk source

   Enable_HSI
   Enable_HSE
   Enable_PLL

  */
#define RCC_CLK_SRC 					Enable_HSI

//put 1 to Enable &  0 to Disable
#define Enable_AHB	     				1
#define Enable_APB1						0
#define Enable_APB2						0

#if(RCC_CLK_SRC==Enable_PLL)

/* * * * * * * * * * * *
 *   PLL CLK Source    *
 * * * * * * * * * * * */
/*
    HSI,
	HSE
  */
#define PLL_CLK_Source					HSE

/* * * * * * * * * * * * * * *
 *  Main PLLQ division factor for USB OTG FS
 *
 * * * * * * * * * * * * * * */
/*
	PLL_input_clock_Q2,
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

	*/


/* * * * * * * * * * * * * * *
 *  Main PLLP division factor for main system clock
 *
 * * * * * * * * * * * * * * */
/*
	PLL_input_clock_P2,

	PLL_input_clock_P4,

	PLL_input_clock_P6,

	PLL_input_clock_P8,


	*/

/* * * * * * * * * * * * * * *
 *   Main PLLN multiplication factor for VCO
 *   you should take value from 192 to 432
 * * * * * * * * * * * * * * */
/*
 *  Examples:
 *
	PLL_input_clock_N192=192,

	PLL_input_clock_N432=432


	*/


/* * * * * * * * * * * * * * *
 *  Division factor for the main PLLM  and audio PLL (PLLI2S) input clock
 *  you should take value from 2 to 63
 * * * * * * * * * * * * * * */
/*
 *   Examples:
 *
	PLL_input_clock_M2=2,

	PLL_input_clock_M63=63,


	*/

#define PLL_DIVISION_FACTOR_Q	      PLL_input_clock_Q15
#define PLL_DIVISION_FACTOR_P	      PLL_input_clock_P8
#define PLL_MULTIPLICATION_FACTOR_N	  PLL_input_clock_N432
#define PLL_DIVISION_FACTOR_M	      PLL_input_clock_M63





#endif



#if(Enable_AHB1)
/* * * * * * * * * * * * * * *
 *   AHB Prescaler Factor    *
 * * * * * * * * * * * * * * */
/*
 	AHB_SYSCLK_not_divided,
	AHB_SYSCLK_divided_by_2,
	AHB_SYSCLK_divided_by_4,
	AHB_SYSCLK_divided_by_8,
	AHB_SYSCLK_divided_by_16,
	AHB_SYSCLK_divided_by_64,
	AHB_SYSCLK_divided_by_128,
	AHB_SYSCLK_divided_by_256,
	AHB_SYSCLK_divided_by_512
 */
#define AHB_Prescaler_Factor			AHB_SYSCLK_divided_by_2
#endif




#if(Enable_AHB)
/* * * * * * * * * * * * * * *
 *   APB1 Prescaler Factor   *
 * * * * * * * * * * * * * * */
/*
	AHB_HCLK_not_divided
	AHB_HCLK_divided_by_2
	AHB_HCLK_divided_by_4
	AHB_HCLK_divided_by_8
	AHB_HCLK_divided_by_16
    AHB_HCLK_divided_by_64
    AHB_HCLK_divided_by_128
    AHB_HCLK_divided_by_256
    AHB_HCLK_divided_by_512

  */
#define AHB_Prescaler_Factor			AHB_HCLK_divided_by_2
#endif



#if(Enable_APB1)
/* * * * * * * * * * * * * * *
 *   APB1 Prescaler Factor   *
 * * * * * * * * * * * * * * */
/*
	APB_HCLK_not_divided,
	APB_HCLK_divided_by_2,
	APB_HCLK_divided_by_4,
	APB_HCLK_divided_by_8,
	APB_HCLK_divided_by_16
 */
#define APB1_Prescaler_Factor			APB_HCLK_not_divided
#endif

#if(Enable_APB2)
/* * * * * * * * * * * * * * *
 *   APB2 Prescaler Factor   *
 * * * * * * * * * * * * * * */
/*
	APB_HCLK_not_divided,
	APB_HCLK_divided_by_2,
	APB_HCLK_divided_by_4,
	APB_HCLK_divided_by_8,
	APB_HCLK_divided_by_16
 */
#define APB2_Prescaler_Factor			APB_HCLK_not_divided
#endif





#endif /* 01_MCAL_00_RCC_RCC_CFG_H_ */
