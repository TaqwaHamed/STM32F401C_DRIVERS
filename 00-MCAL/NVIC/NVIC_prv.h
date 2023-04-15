#ifndef _NVIC_PRV_H
#define _NVIC_PRV_H



/******************** NVIC Registers Definitions	****************************************/



typedef struct {

	volatile u32 ISER[8];
	volatile u32 RESERVED1[24];
	volatile u32 ICER[8];
	volatile u32 RESERVED2[24];
	volatile u32 ISPR[8];
	volatile u32 RESERVED3[24];
	volatile u32 ICPR[8];
	volatile u32 RESERVED4[24];
	volatile u32 IABR[8];
	volatile u32 RESERVED5[57];
	volatile u8 IPR[240];

}NVIC_REG;

#define NVIC_BASE_ADDRESS 			0xE000E100
#define NVIC			( ( NVIC_REG*const ) NVIC_BASE_ADDRESS )
/*************************************************************************************************/

/************SCB REG*******/

#define AIRCR         * ( (u32*const ) 0xE000ED0C )




#endif
