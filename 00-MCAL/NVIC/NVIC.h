#ifndef _NVIC_H
#define _NVIC_H

typedef enum{
	WWDG_IRQ	,
	EXTI16_PVD_IRQ		,
	EXTII21_TAMP_STAMP_IRQ	,
	EXTI22RTC_IRQ		,
	FLASH_IRQ	,
	RCC_IRQ	,
	EXTI0_IRQ	,
	EXTI1_IRQ	,
	EXTI2_IRQ	,
	EXTI3_IRQ	,
	EXTI4_IRQ	,
	DMA1_Channel0_IRQ	,
	DMA1_Channel1_IRQ	,
	DMA1_Channel2_IRQ	,
	DMA1_Channel3_IRQ	,
	DMA1_Channel4_IRQ	,
	DMA1_Channel5_IRQ	,
	DMA1_Channel6_IRQ	,
	ADC_IRQ			,
	EXTI9_5=23	,
	TIM1_BRK_TIM9	,
	TIM1_UP_TIM10			,
	TIM1_TRG_COM_TIM11_IRQ			,
	TIM1_CC_IRQ			,
	TIM2		,
	TIM3			,
	TIM4	,
	I2C1_EV_IRQ			,
	I2C1_ER_IRQ			,
	I2C2_EV_IRQ			,
	I2C2_ER_IRQ			,
	SPI1_IRQ			,
	SPI2_IRQ			,
	USART1_IRQ			,
	USART2_IRQ			,
	EXTI15_10_IRQ		,
	EXTI17_RTCAlarm_IRQ		,
	EXTI18_OTG_FS_WKUP_IRQ	,
	DMA1_Channel7_IRQ	,
	SDIO_IRQ			,
	TIM5_IRQ	,
	SPI3_IRQ			,
	DMA2_Channel0_IRQ	,
	DMA2_Channel1_IRQ	,
	DMA2_Channel2_IRQ	,
	DMA2_Channel3_IRQ	,
	DMA2_Channel4_IRQ	,
	OTG_FS_IRQ	,
	DMA2_Channel5_IRQ	,
	DMA2_Channel6_IRQ	,
	DMA2_Channel7_IRQ	,
	USART6_IRQ	,
	I2C3_EV_IRQ	,
	I2C3_ER_IRQ	,
	FPU_IRQ	,
	SPI4_IRQ	,
	IRQ_NUM

}INTERRUPT_NUMBER;



typedef enum{

NVIC_enuOK = 0,
NVIC_enuNotOK,
NVIC_Invalid_IRQ,
NVIC_Nullptr

}NVIC_tenuErrorStatus;

typedef enum
{

	GROUP_PRIORITY_BITS4To7_NONE_SUB_PRIORITY     =   0b000 ,
	GROUP_PRIORITY_BITS5T07_SUB_PRIORITY4         =   0b100 ,
	GROUP_PRIORITY_BITS6T07_SUB_PRIORITY4To5      =   0b101 ,
	GROUP_PRIORITY_BITS7_SUB_PRIORITY4To6         =   0b110 ,
	GROUP_PRIORITY_BITS_NONE_SUB_PRIORITY4To7     =   0b111

}GROUP_PRIORITY;




NVIC_tenuErrorStatus NVIC_enuEnableIRQ ( INTERRUPT_NUMBER Copy_enumIRQN );
NVIC_tenuErrorStatus NVIC_enuDisableIRQ( INTERRUPT_NUMBER Copy_enumIRQN );
NVIC_tenuErrorStatus NVIC_enuSetPendingFlag  ( INTERRUPT_NUMBER Copy_enumIRQN );
NVIC_tenuErrorStatus NVIC_enuClearPendingFlag( INTERRUPT_NUMBER Copy_enumIRQN );
NVIC_tenuErrorStatus NVIC_enuGetActiveFlag   ( INTERRUPT_NUMBER Copy_enumIRQN , u8*Copy_ptrReturnValue );
NVIC_tenuErrorStatus NVIC_enuSetPriorty(INTERRUPT_NUMBER Copy_enumIRQN, u8 Copy_u8riorty);
NVIC_tenuErrorStatus NVIC_enuConfigurePriority(GROUP_PRIORITY Copy_enumPriority);


#endif
