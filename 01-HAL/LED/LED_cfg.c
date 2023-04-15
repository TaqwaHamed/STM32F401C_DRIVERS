/*
 * LED_cfg.c
 *
 *  Created on: Feb 21, 2023
 *      Author: TAQWA HAMED
 */



#include "STD_TYPES.h"
#include "GPIO.h"
#include "LED_cfg.h"


led_cfg_t LED_strLedCfg[led_count] = {
	[led_alarm]={.port=PORTA,.pin=PIN0,.mode=OUTPUT_PUSH_PULL,.speed=Medium_speed,.Type=Active_High},
	[led_start]={.port=PORTA,.pin=PIN1,.mode=OUTPUT_PUSH_PULL,.speed=Medium_speed,.Type=Active_High},
	[led_stop]={.port=PORTA,.pin=PIN2,.mode=OUTPUT_PUSH_PULL,.speed=Medium_speed,.Type=Active_Low},
	[led_warning]={.port=PORTA,.pin=PIN3,.mode=OUTPUT_PUSH_PULL,.speed=Medium_speed,.Type=Active_Low}


};
