/*
 * GPIO.c
 *
 *  Created on: Feb 16, 2023
 *      Author: TAQWA HAMED
 */


#include "../include/STD_TYPES.h"
#include "../include/GPIO.h"
#include "../include/GPIO_prv.h"

/* array of pointers to structure */
static GPIO_t * GPIOx[6] = { GPIOA, GPIOB, GPIOC , GPIOD , GPIOE , GPIOH};

GPIO_tenuErrorStatus GPIO_enuInitPin(GPIO_PINCONFIGS_t * Copy_strPinConfig)
{

	GPIO_tenuErrorStatus LOC_u8Error_State= GPIO_enuNotOK;


	if(Copy_strPinConfig->mode <MODE_NUM)
	{
		GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  &= ~(CLR_MASK << (Copy_strPinConfig->pin *2));
		if(Copy_strPinConfig->mode == INPUT_PULL_UP)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (INPUT_MASK << (Copy_strPinConfig->pin *2));
			GPIOx[Copy_strPinConfig->port]->GPIOX_PUPDR  |= (PULLUP_MASK << (Copy_strPinConfig->pin *2) );
		}
		else if(Copy_strPinConfig->mode == INPUT_PULL_DOWN)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (INPUT_MASK << (Copy_strPinConfig->pin*2) );
			GPIOx[Copy_strPinConfig->port]->GPIOX_PUPDR  |= (PULLDOWN_MASK << (Copy_strPinConfig->pin *2) );
		}
		else if(Copy_strPinConfig->mode == INPUT_FLOATING)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (INPUT_MASK << (Copy_strPinConfig->pin*2) );
		}
		else if(Copy_strPinConfig->mode == INPUT_ANALOG)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (INPUT_MASK << (Copy_strPinConfig->pin*2) );
		}
		else if(Copy_strPinConfig->mode == OUTPUT_OPEN_DRAIN)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (OUTPUT_MASK << (Copy_strPinConfig->pin *2));
			GPIOx[Copy_strPinConfig->port]->GPIOX_OTYPER  |= (OPEN_DRAIN_MASK << Copy_strPinConfig->pin );
		}
		else if(Copy_strPinConfig->mode == OUTPUT_PUSH_PULL)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (OUTPUT_MASK << (Copy_strPinConfig->pin*2) );
			GPIOx[Copy_strPinConfig->port]->GPIOX_OTYPER  |= (PUSH_PULL_MASK << Copy_strPinConfig->pin );
		}
		else if(Copy_strPinConfig->mode == ALTERANTE_PUSH_PULL)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (AF_MASK << (Copy_strPinConfig->pin *2) );
		}
		else if(Copy_strPinConfig->mode == ALTERANTE_OPEN_DRAIN)
		{
			GPIOx[Copy_strPinConfig->port]->GPIOX_MODER  |= (AF_MASK << ( Copy_strPinConfig->pin *2));
		}

	}
	else
	{
		LOC_u8Error_State=GPIO_Invalid_Mode;
	}

	GPIOx[Copy_strPinConfig->port]->GPIOX_OSPEEDR  &= ~(CLR_MASK << (Copy_strPinConfig->pin *2));
	GPIOx[Copy_strPinConfig->port]->GPIOX_OSPEEDR  |= (Copy_strPinConfig->speed << (Copy_strPinConfig->pin*2) );
	return LOC_u8Error_State;

}


GPIO_tenuErrorStatus GPIO_enuSetPinValue(GPIO_PINCONFIGS_t * Copy_strPinConfig , PIN_Value Copy_enumPinValue)
{

	GPIO_tenuErrorStatus LOC_u8Error_State= GPIO_enuNotOK;

	if(Copy_strPinConfig->pin<PIN_NUM)
	{
		if(Copy_enumPinValue==HIGH)
		{

			GPIOx[Copy_strPinConfig->port] ->GPIOX_ODR |=(1<<Copy_strPinConfig->pin);

		}
		else if(Copy_enumPinValue==LOW)
		{

			GPIOx[Copy_strPinConfig->port] ->GPIOX_ODR &= ~(1<<Copy_strPinConfig->pin);
		}
		else
		{
			LOC_u8Error_State=GPIO_INVALID_VALUE;

		}

	}
	else
	{
		LOC_u8Error_State=GPIO_Invalid_Pin;
	}

	return LOC_u8Error_State;
}

GPIO_tenuErrorStatus GPIO_enuTogPinValue(GPIO_PINCONFIGS_t * Copy_strPinConfig)
{
	GPIO_tenuErrorStatus LOC_u8Error_State= GPIO_enuNotOK;
	if(Copy_strPinConfig->pin<PIN_NUM)
	{

		GPIOx[Copy_strPinConfig->port] ->GPIOX_ODR ^= (1<<Copy_strPinConfig->pin);

	}
	else
	{
		LOC_u8Error_State=GPIO_Invalid_Pin;
	}

	return LOC_u8Error_State;
}

GPIO_tenuErrorStatus GPIO_enuGetPinValue(GPIO_PINCONFIGS_t * Copy_strPinConfig, u8 *Add_pu8PinValue)
{
	GPIO_tenuErrorStatus LOC_u8Error_State= GPIO_enuNotOK;

	if(Copy_strPinConfig->pin<PIN_NUM)
		{

		*Add_pu8PinValue=(((GPIOx[Copy_strPinConfig->port] ->GPIOX_ODR )>>Copy_strPinConfig->pin)&0x01);
		}
		else
		{
			LOC_u8Error_State=GPIO_Invalid_Pin;
		}



	return LOC_u8Error_State;
}
GPIO_tenuErrorStatus GPIO_enuSetPortValue(GPIO_PINCONFIGS_t * Copy_strPinConfig,u16 Copy_u16PortValue)
{

	GPIO_tenuErrorStatus LOC_u8Error_State= GPIO_enuNotOK;
	if(Copy_strPinConfig->port <PORT_NUM)
	{
		GPIOx[Copy_strPinConfig->port] ->GPIOX_ODR = Copy_u16PortValue;

	}
	else
	{

		LOC_u8Error_State= GPIO_Invalid_Port;
	}

	return LOC_u8Error_State;
}


GPIO_tenuErrorStatus GPIO_enuSelectAF(GPIO_PINCONFIGS_t * Copy_strPinConfig,AF_VALUE Copy_u8AF)
{
	GPIO_tenuErrorStatus LOC_u8Error_State= GPIO_enuNotOK;

	if(Copy_u8AF< AF_NUM)
	{
		if(Copy_strPinConfig->port <PORT_NUM)
		{
			if(Copy_strPinConfig->pin<PIN_NUM)
			{
				if(Copy_strPinConfig->pin < 8)
				{
					GPIOx[Copy_strPinConfig->port] ->GPIOX_AFRL &= ~(0b1111 << (Copy_strPinConfig->pin*4));
					GPIOx[Copy_strPinConfig->port] ->GPIOX_AFRL |=(Copy_u8AF<< (Copy_strPinConfig->pin*4));
				}
				else if(Copy_strPinConfig->pin > 7 )
				{
					GPIOx[Copy_strPinConfig->port] ->GPIOX_AFRH &= ~(0b1111 << (Copy_strPinConfig->pin*4));
					GPIOx[Copy_strPinConfig->port] ->GPIOX_AFRH |=(Copy_u8AF<< (Copy_strPinConfig->pin*4));
				}
			}
			else
			{
				LOC_u8Error_State= GPIO_Invalid_Pin;
			}

		}
		else
		{
			LOC_u8Error_State= GPIO_Invalid_Port;
		}
	}
	else
	{
		LOC_u8Error_State=GPIO_INVALID_AF;
	}

	return LOC_u8Error_State;

}









