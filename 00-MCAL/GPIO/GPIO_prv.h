#ifndef _GPIO_PRV_H
#define _GPIO_PRV_H





/******************** GPIO Registers Definitions	****************************************/



typedef struct{

	u32 GPIOX_MODER;
	u32 GPIOX_OTYPER;
	u32 GPIOX_OSPEEDR;
	u32 GPIOX_PUPDR;
	u32 GPIOX_IDR;
	u32 GPIOX_ODR;
	u32 GPIOX_BSRR;
	u32 GPIOX_LCKR;
	u32 GPIOX_AFRL;
	u32 GPIOX_AFRH;

}GPIO_t;

/***************************************************************************************************/


/*******************************Base Address definition*********************************************/

#define GPIOA_BASE_ADDRESS    0x40020000
#define GPIOB_BASE_ADDRESS    0x40020400
#define GPIOC_BASE_ADDRESS    0x40020800
#define GPIOD_BASE_ADDRESS    0x40020C00
#define GPIOE_BASE_ADDRESS    0x40021000
#define GPIOH_BASE_ADDRESS    0x40021C00

#define GPIOA				( ( volatile GPIO_t * const ) GPIOA_BASE_ADDRESS)
#define GPIOB				( ( volatile GPIO_t * const ) GPIOB_BASE_ADDRESS)
#define GPIOC				( ( volatile GPIO_t * const ) GPIOC_BASE_ADDRESS)
#define GPIOD				( ( volatile GPIO_t * const ) GPIOD_BASE_ADDRESS)
#define GPIOE				( ( volatile GPIO_t * const ) GPIOE_BASE_ADDRESS)
#define GPIOH   			( ( volatile GPIO_t * const ) GPIOH_BASE_ADDRESS)

/******************************************************************************************************/


/****************************************** MASKS ************************************************************/

 #define    INPUT_MASK          0b00
 #define    OUTPUT_MASK         0b01
 #define    AF_MASK             0b10
 #define    ANALOG_MASK         0b11

#define    PUSH_PULL_MASK        0b0
#define    OPEN_DRAIN_MASK       0b1

#define    PULLUP_MASK          0b01
#define    PULLDOWN_MASK        0b10
#define    CLR_MASK             0b11










#endif

