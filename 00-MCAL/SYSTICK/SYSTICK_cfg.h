#ifndef _SYSTICK_CFG_H
#define _SYSTICK_CFG_H



/************* Available Options **************/

		/* 1- AHB			*/
		/* 2- AHB_DEV_8		*/

#define SYSTICK_CLOCK_SOURCE	AHB_DEV_8

/************* Available Options 	 **************/

		/* 1- EXCEPTION_ENABLED	 */
		/* 2- EXCEPTION_DISABLED */

#define SYSTICK_EXCEPTION		EXCEPTION_ENABLED
#define SYSTICK_CLOCK           1





#endif
