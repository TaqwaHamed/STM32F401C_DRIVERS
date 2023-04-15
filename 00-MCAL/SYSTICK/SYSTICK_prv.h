#ifndef _SYSTICK_PRV_H
#define _SYSTICK_PRV_H


/******************** SYSTICK Registers Definitions	**********************************************/

#define SYSTICK_BASE_ADDRESS 		0xE000E010
typedef struct{

	volatile u32 CTRL	;
	volatile u32 LOAD	;
	volatile u32 VAL	;
	volatile u32 CALIB	;

}SYSTICK_REG;

#define SYSTICK					( ( SYSTICK_REG * const ) SYSTICK_BASE_ADDRESS )

/***************************************************************************************************/


#define AHB							(1 << 2)
#define AHB_DEV_8					(0 << 2)

#define SYSTICK_ENABLE_BIT			0
#define EXCEPTION_ENABLED			(1 << 1)
#define EXCEPTION_DISABLED			(0 << 1)

#endif
