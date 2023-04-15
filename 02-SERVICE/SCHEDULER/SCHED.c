#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SCHED.h"
#include "SCHED_cfg.h"



typedef struct{

	runnable_t *runnable;
	u8 state;
	u32 remain_time_ms;

}runnable_state_t;


 runnable_state_t runnables_arr[max_runnable_num]={{0}};


void sched_voidInit(void)
{
	SYSTICK_voidSetConfig();
	SYSTICK_voidSetPeriodmsASYNC( 1,sched);

}

void sched_voidStart(void)
{
	SYSTICK_voidStart();
}



void sched_Add_Runnable(const runnable_t *Copy_strpSched)
{
	if(Copy_strpSched)
	{

		if(runnables_arr[Copy_strpSched->priority].runnable==NULL)
		{
			runnables_arr[Copy_strpSched->priority].runnable=Copy_strpSched;
			runnables_arr[Copy_strpSched->priority].remain_time_ms=Copy_strpSched->start_delay_ms;
			runnables_arr[Copy_strpSched->priority].state = READY;

		}

	}
}


static void sched(void)
{
	u8 l_TasksIterator = 0;
	for (l_TasksIterator = 0 ; l_TasksIterator<max_runnable_num; l_TasksIterator++)
	{
		if (runnables_arr[l_TasksIterator].remain_time_ms == 0)
		{
			if ( runnables_arr[l_TasksIterator].state == READY)
			{
				if(runnables_arr[l_TasksIterator].runnable != NULL)
				{
				runnables_arr[l_TasksIterator].runnable->CBF();
				runnables_arr[l_TasksIterator].remain_time_ms = runnables_arr[l_TasksIterator].runnable->period_ms;
				}
			}
		}
		else
		{
			runnables_arr[l_TasksIterator].remain_time_ms--;
		}
	}

}
