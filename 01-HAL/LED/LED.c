/*
 * LED.c
 *
 *  Created on: Feb 21, 2023
 *      Author: TAQWA HAMED
 */


#include "STD_TYPES.h"
#include "GPIO.h"
#include "LED_cfg.h"
#include "LED.h"

extern led_cfg_t LED_strLedCfg[led_count] ;

void Led_enuInit(void)
{

	GPIO_PINCONFIGS_t GPIO_CONFIG;

	for(u8 i=0; i<led_count;i++)
	{
		GPIO_CONFIG.mode=LED_strLedCfg[i].mode;
		GPIO_CONFIG.pin=LED_strLedCfg[i].pin;
		GPIO_CONFIG.port=LED_strLedCfg[i].port;
		GPIO_CONFIG.speed=LED_strLedCfg[i].speed;
		GPIO_enuInitPin(&GPIO_CONFIG);
	}



}





LED_tenuErrorStatus Led_enuSet_State(u8 Led , u8 State)
{
	LED_tenuErrorStatus Loc_u8State=LED_enuNOK;

	GPIO_PINCONFIGS_t GPIO_CONFIG;
	GPIO_CONFIG.pin=LED_strLedCfg[Led].pin;
	GPIO_CONFIG.port=LED_strLedCfg[Led].port;

	GPIO_enuSetPinValue(&GPIO_CONFIG,State ^LED_strLedCfg[Led].Type);

	return Loc_u8State;
}
