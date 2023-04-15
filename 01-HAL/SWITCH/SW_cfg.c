/*
 * SW_cfg.c
 *
 *  Created on: Feb 22, 2023
 *      Author: TAQWA HAMED
 */



#include "STD_TYPES.h"
#include "GPIO.h"
#include "SW_cfg.h"


SW_cfg_t SW_strSWCfg[SW_count] = {

	[SW_start]={.port=PORTA,.pin=PIN0,.mode=INPUT_PULL_UP,.speed=Medium_speed,.Type=Pull_Up},
	[SW_stop]={.port=PORTA,.pin=PIN2,.mode=INPUT_PULL_DOWN,.speed=Medium_speed,.Type=Pull_Down}


};
