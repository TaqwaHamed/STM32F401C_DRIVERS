#ifndef _SYSTICK_H
#define _SYSTICK_H



void SYSTICK_voidSetConfig(void);
void SYSTICK_voidStart(void);
void SYSTICK_voidStop(void);
void SYSTICK_voidSetPeriodusSYNC( u32 Copy_u32periodMs);
void SYSTICK_voidSetPeriodmsSYNC( u32 Copy_u32periodms);
void SYSTICK_voidSetPeriodmsASYNC( u32 Copy_u32periodms , void(*CALLBACK)(void));
void SYSTICK_voidSetcountTime( u32 Copy_u32CountTime);


#endif
