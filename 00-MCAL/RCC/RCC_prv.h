#ifndef _RCC_PRV_H
#define _RCC_PRV_H



/*******************************Registers definition*********************************************/

typedef struct{
	u32 RCC_CR        ;
	u32 RCC_PLLCFGR   ;
	u32 RCC_CFGR      ;
	u32 RCC_CIR       ;
	u32 RCC_AHB1RSTR  ;
	u32 RCC_AHB2RSTR  ;
	u32 RCC_RES1      ;
	u32 RCC_RES2      ;
	u32 RCC_APB1RSTR  ;
	u32 RCC_APB2RSTR  ;
	u32 RCC_RES3      ;
	u32 RCC_RES4      ;
	u32 RCC_AHB1ENR   ;
	u32 RCC_AHB2ENR   ;
	u32 RCC_RES5      ;
	u32 RCC_RES6      ;
	u32 RCC_APB1ENR   ;
	u32 RCC_APB2ENR   ;
	u32 RCC_RES7      ;
	u32 RCC_RES8      ;
	u32 RCC_AHB1LPENR ;
	u32 RCC_AHB2LPENR ;
	u32 RCC_RES9      ;
	u32 RCC_RES10     ;
	u32 RCC_APB1LPENR ;
	u32 RCC_APB2LPENR ;
	u32 RCC_RES11     ;
	u32 RCC_RES12     ;
	u32 RCC_BDCR      ;
	u32 RCC_CSR       ;
	u32 RCC_RES13     ;
	u32 RCC_RES14     ;
	u32 RCC_SSCGR     ;
	u32 RCC_PLLI2SCFGR;
	u32 RCC_RES15     ;
	u32 RCC_DCKCFGR   ;

}RCC_t;


/*******************************Base Address definition*********************************************/

#define RCC_BASE_ADDRESS    0x40023800
#define RCC                 ((volatile RCC_t*)RCC_BASE_ADDRESS)

/*******************************Registers bits*********************************************/
#define HSION         0
#define HSIRDY         1
#define HSEON         16
#define HSERDY         17
#define PLLON         24
#define PLLRDY        25
#define PLLI2SON        24
#define PLLI2SRDY       25
#define PLLSRC        22
#define SW0          0
#define SW1          1
#define HPRE0         4
#define PRE10         10
#define PRE20         13
#define  PLLM0        0
#define  PLLN         6
#define  PLLP0        16
#define  PLLQ0        24


#define  APB_HCLK_not_divided    0b000
#define  APB_HCLK_divided_by_2   0b100
#define  APB_HCLK_divided_by_4   0b101
#define  APB_HCLK_divided_by_8   0b110
#define  APB_HCLK_divided_by_16  0b111


#define  AHB_HCLK_not_divided      0b0000
#define  AHB_HCLK_divided_by_2     0b1000
#define  AHB_HCLK_divided_by_4     0b1001
#define  AHB_HCLK_divided_by_8     0b1010
#define  AHB_HCLK_divided_by_16    0b1011
#define  AHB_HCLK_divided_by_64    0b1100
#define  AHB_HCLK_divided_by_128   0b1101
#define  AHB_HCLK_divided_by_256   0b1110
#define  AHB_HCLK_divided_by_512   0b1111

#define SIZE_OF_REGISTER 32

#define PERIPHERAL_IN_RCC_AHB1ENR    (peripheralId < 32)
#define PERIPHERAL_IN_RCC_AHB2ENR    (peripheralId < 64)
#define PERIPHERAL_IN_RCC_APB1ENR   (peripheralId < 96)
#define PERIPHERAL_IN_RCC_APB2ENR   (peripheralId < 128)


#define Enable_HSI						0
#define Enable_HSE						1
#define Enable_PLL						2


#endif
