


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_cfg.h"


void(*SYSTICK_CALLBACK)(void);

void SYSTICK_voidSetConfig(void)
{
	SYSTICK->CTRL= (SYSTICK_CLOCK_SOURCE | SYSTICK_EXCEPTION);
}



void SYSTICK_voidStart(void)
{

	SYSTICK->CTRL|=1<<SYSTICK_ENABLE_BIT;


}

void SYSTICK_voidStop(void)
{

	SYSTICK->CTRL &=~(1<<SYSTICK_ENABLE_BIT);


}

void SYSTICK_voidSetcountTime( u32 Copy_u32CountTime)
{
	SYSTICK->LOAD=Copy_u32CountTime;
}



void SYSTICK_voidSetPeriodusSYNC( u32 Copy_u32periodms)
{

	f32 tick_time=0;
	u32 counts=0;

	tick_time=(1/SYSTICK_CLOCK);
	counts=Copy_u32periodms/tick_time;
	SYSTICK->LOAD=counts;
	SYSTICK->CTRL|=1<<SYSTICK_ENABLE_BIT;
	// pool flag
	while( GET_BIT(SYSTICK->CTRL, 16)==0 );

}


void SYSTICK_voidSetPeriodmsSYNC( u32 Copy_u32periodms)
{

	f32 tick_time=0;
	u32 counts=0;

	tick_time=1.0/SYSTICK_CLOCK;
	counts=(Copy_u32periodms/tick_time)*1000;
	SYSTICK->LOAD=counts;
	SYSTICK->CTRL|=1<<SYSTICK_ENABLE_BIT;
	///pooling on flag
	while( GET_BIT(SYSTICK->CTRL, 16)==0 );
}


void SYSTICK_voidSetPeriodmsASYNC( u32 Copy_u32periodms , void(*CALLBACK)(void))
{

	f32 tick_time=0;
	u32 counts=0;

	tick_time=1/SYSTICK_CLOCK;
	counts=(Copy_u32periodms/tick_time)*1000;
	SYSTICK->LOAD=counts;
	SYSTICK_CALLBACK=CALLBACK;

}


void SysTick_Handler(void)
{

	if(SYSTICK_CALLBACK!=NULL)
	{
		SYSTICK_CALLBACK();
	}
}
