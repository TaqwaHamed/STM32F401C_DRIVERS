#ifndef _SCHED_H
#define _SCHED_H


typedef void(*runnable_cbf_t)(void);

typedef struct{

	char* name;
	u8 priority;
	u32 period_ms;
	u32 start_delay_ms;
	runnable_cbf_t  CBF;

}runnable_t;

typedef enum{
	READY,
	SUSPENDED

}RunnableState;



void sched_voidInit(void);
void sched_voidStart(void);
static void sched(void);
void sched_Add_Runnable(const runnable_t *Copy_strpSched);
void sched_Pause_Runnable(runnable_t *Copy_strpSched,u16 time_ms);











#endif
