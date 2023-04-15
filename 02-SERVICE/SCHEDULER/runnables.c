#include "STD_TYPES.h"
#include "GPIO.h"
#include "LCD.h"
#include "SCHED.h"

void app1_runnable(void)
{

	GPIO_PINCONFIGS_t config;
	config.mode=OUTPUT_PUSH_PULL;
	config.pin=PIN0;
	config.port=PORTA;
	config.speed=Medium_speed;
	GPIO_enuInitPin(&config);
	GPIO_enuTogPinValue(&config);

}

void app2_runnable(void)
{

	GPIO_PINCONFIGS_t config;
	config.mode=OUTPUT_PUSH_PULL;
	config.pin=PIN1;
	config.port=PORTA;
	config.speed=Medium_speed;
	GPIO_enuInitPin(&config);
	GPIO_enuTogPinValue(&config);

}
void app3_runnable(void)
{

	GPIO_PINCONFIGS_t config;
	config.mode=OUTPUT_PUSH_PULL;
	config.pin=PIN2;
	config.port=PORTA;
	config.speed=Medium_speed;
	GPIO_enuInitPin(&config);
	GPIO_enuTogPinValue(&config);

}
void app4_runnable(void)
{
	LCD_voidSavePosition(1 , 1);
	LCD_voidSaveString("My 1st Scheduler");
	LCD_voidRequestMode(Lcd_enuWritingProcess);
}

void app5_runnable(void)
{
	LCD_voidSavePosition(1 , 1);
	LCD_voidSaveString("Using LCD");
	LCD_voidRequestMode(Lcd_enuWritingProcess);
}

void app6_runnable(void)
{
	LCD_voidSavePosition(1 , 1);
	LCD_voidSaveString("STATE MACHINE ^_^");
	LCD_voidRequestMode(Lcd_enuWritingProcess);
}



static const runnable_t app1={
		.name="runnable_app1",
		.period_ms=500,
		.start_delay_ms=0,
		.priority=1,
		.CBF=app1_runnable
};

static const runnable_t app2={
		.name="runnable_app2",
		.period_ms=1000,
		.start_delay_ms=1,
		.priority=2,
		.CBF=app2_runnable
};

static const runnable_t app3={
		.name="runnable_app3",
		.period_ms=1500,
		.start_delay_ms=2,
		.priority=3,
		.CBF=app3_runnable
};

static const runnable_t app4={
		.name="runnable_app4",
		.period_ms=2,
		.start_delay_ms=3,
		.priority=0,
		.CBF=Lcd_vidTask
};

static const runnable_t app5={
		.name="runnable_app5",
		.period_ms=2000,
		.start_delay_ms=1000,
		.priority=1,
		.CBF=app4_runnable
};
static const runnable_t app6={
		.name="runnable_app6",
		.period_ms=2000,
		.start_delay_ms=1500,
		.priority=2,
		.CBF=app5_runnable
};

static const runnable_t app7={
		.name="runnable_app7",
		.period_ms=2000,
		.start_delay_ms=2000,
		.priority=3,
		.CBF=app6_runnable
};


void APP_INIT(void)
{
//	sched_Add_Runnable(&app1);
//	sched_Add_Runnable(&app2);
//	sched_Add_Runnable(&app3);
	sched_Add_Runnable(&app4);
	sched_Add_Runnable(&app5);
	sched_Add_Runnable(&app6);
	sched_Add_Runnable(&app7);
}
