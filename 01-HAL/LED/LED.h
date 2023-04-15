#ifndef _LED_H
#define _LED_H





#define STATE_ON       1
#define STATE_OFF      0

typedef enum{

	LED_enuNOK = 0,
	LED_enuOK ,
	LED_enuNullPtr

}LED_tenuErrorStatus;



void Led_enuInit(void);
LED_tenuErrorStatus Led_enuSet_State(u8 Led , u8 State);

















#endif
