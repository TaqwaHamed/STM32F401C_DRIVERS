/*
 * NVIC.c
 *
 *  Created on: Mar 3, 2023
 *      Author: TAQWA HAMED
 */



#include "STD_TYPES.h"
#include"NVIC_prv.h"
#include "NVIC.h"




NVIC_tenuErrorStatus NVIC_enuEnableIRQ ( INTERRUPT_NUMBER Copy_enumIRQN )
{

	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;
	u8 LOC_u8REG_Index = Copy_enumIRQN / 32 ;
		u8 LOC_u8BIT_Value = Copy_enumIRQN % 32 ;
		if ( Copy_enumIRQN >IRQ_NUM )
		{
			LOC_enuState = NVIC_Invalid_IRQ;
		}
		else
		{
			NVIC->ISER[LOC_u8REG_Index] = ( 1 << LOC_u8BIT_Value );
			LOC_enuState=NVIC_enuOK;
		}

	return LOC_enuState;
}


NVIC_tenuErrorStatus NVIC_enuDisableIRQ ( INTERRUPT_NUMBER Copy_enumIRQN )
{

	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;
	u8 LOC_u8REG_Index = Copy_enumIRQN / 32 ;
		u8 LOC_u8BIT_Value = Copy_enumIRQN % 32 ;
		if ( Copy_enumIRQN >IRQ_NUM )
		{
			LOC_enuState = NVIC_Invalid_IRQ;
		}
		else
		{
			NVIC->ICER[LOC_u8REG_Index] = ( 1 << LOC_u8BIT_Value );
			LOC_enuState=NVIC_enuOK;
		}

	return LOC_enuState;
}


NVIC_tenuErrorStatus NVIC_enuSetPendingFlag  ( INTERRUPT_NUMBER Copy_enumIRQN )
{
	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;

	u8 LOC_u8REG_Index = Copy_enumIRQN / 32 ;
		u8 LOC_u8BIT_Value = Copy_enumIRQN % 32 ;
		if ( Copy_enumIRQN >IRQ_NUM )
		{
			LOC_enuState = NVIC_Invalid_IRQ;
		}
		else
		{
			NVIC->ISPR[LOC_u8REG_Index] = ( 1 << LOC_u8BIT_Value );
			LOC_enuState=NVIC_enuOK;
		}

	return LOC_enuState;
}


NVIC_tenuErrorStatus NVIC_enuClearPendingFlag  ( INTERRUPT_NUMBER Copy_enumIRQN )
{
	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;

	u8 LOC_u8REG_Index = Copy_enumIRQN / 32 ;
		u8 LOC_u8BIT_Value = Copy_enumIRQN % 32 ;
		if ( Copy_enumIRQN >IRQ_NUM )
		{
			LOC_enuState = NVIC_Invalid_IRQ;
		}
		else
		{
			NVIC->ICPR[LOC_u8REG_Index] = ( 1 << LOC_u8BIT_Value );
			LOC_enuState=NVIC_enuOK;
		}

	return LOC_enuState;
}


NVIC_tenuErrorStatus NVIC_enuGetActiveFlag   ( INTERRUPT_NUMBER Copy_enumIRQN , u8*Copy_ptrReturnValue )
{

	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;

		u8 LOC_u8REG_Index = Copy_enumIRQN / 32 ;
			u8 LOC_u8BIT_Value = Copy_enumIRQN % 32 ;
			if ( Copy_enumIRQN >IRQ_NUM )
			{
				LOC_enuState = NVIC_Invalid_IRQ;
			}
			else
			{
				if(Copy_ptrReturnValue!=NULL)
				{

				*Copy_ptrReturnValue=(((NVIC->IABR[LOC_u8REG_Index]) >> (LOC_u8BIT_Value)) & 1);
				LOC_enuState=NVIC_enuOK;
				}
				else
				{
					LOC_enuState=NVIC_Nullptr;
				}
			}

		return LOC_enuState;

}


NVIC_tenuErrorStatus NVIC_enuSetPriorty(INTERRUPT_NUMBER Copy_enumIRQN, u8 Copy_u8riorty)
{

	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;

			if ( Copy_enumIRQN >IRQ_NUM )
			{
				LOC_enuState = NVIC_Invalid_IRQ;
			}
			else
			{
				NVIC->IPR[Copy_enumIRQN]=(Copy_u8riorty<<4);
				LOC_enuState=NVIC_enuOK;

			}

		return LOC_enuState;


}


NVIC_tenuErrorStatus NVIC_enuConfigurePriority(GROUP_PRIORITY Copy_enumPriority)
{
	NVIC_tenuErrorStatus LOC_enuState=NVIC_enuNotOK;

	AIRCR=  0x5FA<<16 | Copy_enumPriority<<8;

	return LOC_enuState;
}
