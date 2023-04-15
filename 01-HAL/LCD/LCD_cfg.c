/*
 * LCD_cfg.c
 *
 * Created: 2/10/2023 1:23:25 PM
 *  Author: TAQWA HAMED
 */ 

#include "STD_TYPES.h"
#include "GPIO.h"
#include "LCD_cfg.h"

GPIO_PINCONFIGS_t LCD[11] = {
		{PORTA, PIN0,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN1,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN2,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN3,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN4,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN5,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN6,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN7,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN8,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN9,OUTPUT_PUSH_PULL,Medium_speed},
		{PORTA, PIN10,OUTPUT_PUSH_PULL,Medium_speed},
};





