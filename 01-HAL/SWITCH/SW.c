/*
 * SW.c
 *
 *  Created on: Feb 22, 2023
 *      Author: TAQWA HAMED
 */



#include "STD_TYPES.h"
#include "GPIO.h"
#include "SW_cfg.h"
#include "SW.h"


extern SW_cfg_t SW_strSWCfg[SW_count] ;

void SW_enuInit(void)
{
	GPIO_PINCONFIGS_t GPIO_CONFIG;

	for(u8 i=0; i<SW_count;i++)
	{
		GPIO_CONFIG.mode=SW_strSWCfg[i].mode;
		GPIO_CONFIG.pin=SW_strSWCfg[i].pin;
		GPIO_CONFIG.port=SW_strSWCfg[i].port;
		GPIO_CONFIG.speed=SW_strSWCfg[i].speed;
		GPIO_enuInitPin(&GPIO_CONFIG);
	}


}

SW_tenuErrorStatus SW_enuRead(u8 SW, u8 * Add_pu8SWValue)
{
	SW_tenuErrorStatus Loc_u8State=SW_enuNOK;

	GPIO_PINCONFIGS_t GPIO_CONFIG;
	GPIO_CONFIG.pin=SW_strSWCfg[SW].pin;
	GPIO_CONFIG.port=SW_strSWCfg[SW].port;

	GPIO_enuGetPinValue(&GPIO_CONFIG,&Add_pu8SWValue);
	// Pull Up   (0 ---> PRESSED)    TYPE  ^ Value = STATE ---> 1 ^ 0  = 1
	// PULL DOWN ( 1 --> PRESSED)	 TYPE  ^ Value = STATE ---> 0 ^ 1  = 1
	// PRESSED ---> 1
	*Add_pu8SWValue ^= SW_strSWCfg[SW].Type;
	return Loc_u8State;
}
