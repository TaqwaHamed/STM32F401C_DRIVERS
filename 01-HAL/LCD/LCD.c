/*
 * LCD.c
 *
 * Created: 2/10/2023 12:56:26 PM
 *  Author: TAQWA HAMED
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "RCC.h"
#include "LCD.h"
#include "LCD_prv.h"
#include "LCD_cfg.h"
#include "delay.h"

extern GPIO_PINCONFIGS_t LCD[11];

static Lcd_tenuInitState Init_state=Lcd_enuStart;

static Lcd_tenuRequest Lcd_prvRequest = Lcd_enuNoRequest;

static u8* Lcd_prvString;

static u8 Lcd_prvLineNumber;

static u8 Lcd_prvColNumber;

static u8 Lcd_prvCommand;

void LCD_voidSaveString(u8*Copy_ptrStringptr)
{
	Lcd_prvString = Copy_ptrStringptr;
}
void LCD_voidSavePosition(u8 Copy_u8LineNumber , u8 Copy_u8ColNumber)
{
	Lcd_prvLineNumber = Copy_u8LineNumber;
	Lcd_prvColNumber = Copy_u8ColNumber;
}
void LCD_voidRequestMode(Lcd_tenuRequest Copy_enumLcdRequest)
{
	Lcd_prvRequest = Copy_enumLcdRequest;
}

void LCD_voidInit(void)
{
	_delay_ms(50);
	GPIO_enuSetPinValue(&LCD[LCD_RW_PIN], LOW);



	LCD_voidSend_Command(LCD_FUNCTION_8BIT_2LINES);
	_delay_ms(1);
	LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_voidSend_Command(LCD_CLEAR_SCREEN);
	_delay_ms(2);
	LCD_voidSend_Command(LCD_ENTRY_MODE);
	_delay_ms(2);




}

void LCD_voidHelper_Init(void)
{
	for(u8 i=0;i<LCD_PIN_NUM;i++)
	{

		GPIO_enuInitPin(&LCD[i]);

		switch(LCD[i].port)
		{

		case PORTA:
			RCC_EnableCLK(GPIOAEN);
			break;

		case PORTB:
			RCC_EnableCLK(GPIOBEN);
			break;

		case PORTC:
			RCC_EnableCLK(GPIOCEN);
			break;

		case PORTD:
			RCC_EnableCLK(GPIODEN);
			break;

		case PORTE:
			RCC_EnableCLK(GPIOEEN);
			break;

		case PORTH:
			RCC_EnableCLK(GPIOHEN);
			break;

		}


	}

}


void Lcd_vidInitSequence(void)
{

	static u8 LCD_EN_Value=LOW;
	switch(Init_state)
	{

	case Lcd_enuStart:

		LCD_voidHelper_Init();
		GPIO_enuSetPinValue(&LCD[LCD_RW_PIN], LOW);
		Init_state=Lcd_enuFunctionSet;
		break;

	case Lcd_enuFunctionSet:


		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_FUNCTION_8BIT_2LINES);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuReturnHome;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}

		break;

	case Lcd_enuReturnHome:

		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_RETURN_HOME);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuClear;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}

		break;
	case Lcd_enuClear:

		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_CLEAR_SCREEN);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuDisplayControl;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}


		break;
	case Lcd_enuDisplayControl:

		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_DISP_ON_CURSOR_BLINKING);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuEntryMode;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}





		break;

	case Lcd_enuEntryMode:
		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_ENTRY_MODE);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuCursorDisplayControl;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}

		break;

	case Lcd_enuCursorDisplayControl:
		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuHomePosition;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}

		break;
	case Lcd_enuHomePosition:
		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &LCD_EN_Value);
		if (!LCD_EN_Value)
		{
			LCD_voidSend_Command(LCD_CLEAR_SCREEN);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

		}
		else
		{
			Init_state=Lcd_enuDone;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}

		break;

	default:
		break;

	}


}

static void Lcd_vidWriteSequence(void)
{
	static Lcd_tenuWriteProcess Loc_prvState = Lcd_enuGotoXY;

	static u8 loc_u8Iterator = 0;

	u8 Loc_u8Enable = 0;

	switch(Loc_prvState)
	{
	case Lcd_enuGotoXY:
		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &Loc_u8Enable);
		if (!Loc_u8Enable)
		{
			LCD_voidGotoxy(Lcd_prvLineNumber, Lcd_prvColNumber);
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);
		}
		else
		{
			Loc_prvState++;
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
		}

		break;

	case Lcd_enuWrite:

		GPIO_enuGetPinValue(&LCD[LCD_EN_PIN], &Loc_u8Enable);
		if (Lcd_prvString[loc_u8Iterator] != '\0')
		{
			LCD_voidSend_Char(Lcd_prvString[loc_u8Iterator]);
			loc_u8Iterator++;
		}
		else if (!Loc_u8Enable)
		{
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);
			Loc_prvState++;
		}
		else
		{
			GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);
			Lcd_prvRequest = Lcd_enuNoRequest;
			Loc_prvState = Lcd_enuGotoXY;
		}

		break;

	}
}

void Lcd_vidTask(void)
{
	if (Init_state != Lcd_enuDone)
	{
		Lcd_vidInitSequence();
	}
	else
	{
		switch(Lcd_prvRequest)
		{
		case Lcd_enuWritingProcess:

			Lcd_vidWriteSequence();

			break;

		case Lcd_enuSendCommand:

			LCD_voidSend_Command(Lcd_prvCommand);

			break;

		case Lcd_enuNoRequest:

			// Do Nothing

			break;

		}
	}
}





void LCD_voidSend_Command(u8 Copy_u8Command)
{

	//* RS ----> LOW " COMMAND"
	GPIO_enuSetPinValue(&LCD[LCD_RS_PIN],LOW);
	LCD_voidLatch(Copy_u8Command);


}

static void LCD_voidSend_Enable_Trigger()
{
	GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);
	_delay_ms(5);
	GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], LOW);}


void LCD_voidSend_Char( u8 Copy_u8Char)
{
	GPIO_enuSetPinValue(&LCD[LCD_RS_PIN], HIGH);
	LCD_voidLatch(Copy_u8Char);
}



void LCD_voidSend_Number( u32 Copy_u32num)
{

	u32 LOC_u32Reversed = 1 ;

	if( Copy_u32num == 0 ){ LCD_voidSend_Char('0'); }

	else{

		while ( Copy_u32num != 0 ){

			LOC_u32Reversed = ( LOC_u32Reversed * 10 ) + ( Copy_u32num % 10 );
			Copy_u32num /= 10 ;

		}

		while ( LOC_u32Reversed != 1 )
		{
			GPIO_enuSetPinValue(&LCD[LCD_RS_PIN], HIGH);
			LCD_voidSend_Char( ( LOC_u32Reversed % 10 ) + 48 );
			LOC_u32Reversed /= 10 ;

		}

	}


}


void LCD_voidSend_Float_Number(f32 Copy_f32num)
{
	u8 str [16];


	LCD_voidSend_Number((u64)Copy_f32num ); 
	LCD_voidSend_Char('.'); 

	u64 Local_u64tempNumber = Copy_f32num*1000000;

	if( Local_u64tempNumber%10 >=5 )
	{
		LCD_voidSend_Number((u64)((( Local_u64tempNumber/10)+1) % 100000));
	}
	else
	{
		LCD_voidSend_Number((u64)(( Local_u64tempNumber/10) % 100000)); 
	}


}


void LCD_voidDrawSpecialChar(	u8 Copy_u8Row ,u8 Copy_u8Col ,u8 Block, u8 * Copy_u8ArrPatterns)
{


	/* Get the address of CGRAM */
	u8 Local_Add = Block * LCD_BLOCK_SIZE;

	LCD_voidSend_Command(Local_Add +LCD_SET_CGRAM_ADDRESS);
	u8 counter = 0;
	while(counter<8)
	{
		LCD_voidSend_Char(Copy_u8ArrPatterns[counter]);
		counter++;
	}


	LCD_voidGotoxy(Copy_u8Row,Copy_u8Col);
	LCD_voidSend_Char(Block);
}











static void LCD_voidLatch(u8 copy_u8Data)
{

	// set RW as  write operation,EN LOW

	GPIO_enuSetPinValue(&LCD[LCD_RW_PIN], LOW);
	GPIO_enuSetPinValue(&LCD[LCD_EN_PIN], HIGH);

	GPIO_enuSetPinValue(&LCD[LCD_D7_PIN],GET_BIT (copy_u8Data,7));
	GPIO_enuSetPinValue(&LCD[LCD_D6_PIN], GET_BIT(copy_u8Data,6));
	GPIO_enuSetPinValue(&LCD[LCD_D5_PIN], GET_BIT(copy_u8Data,5));
	GPIO_enuSetPinValue(&LCD[LCD_D4_PIN], GET_BIT(copy_u8Data,4));
	GPIO_enuSetPinValue(&LCD[LCD_D3_PIN], GET_BIT(copy_u8Data,3));
	GPIO_enuSetPinValue(&LCD[LCD_D2_PIN], GET_BIT(copy_u8Data,2));
	GPIO_enuSetPinValue(&LCD[LCD_D1_PIN], GET_BIT(copy_u8Data,1));
	GPIO_enuSetPinValue(&LCD[LCD_D0_PIN], GET_BIT(copy_u8Data,0));
	LCD_voidSend_Enable_Trigger();





}



void LCD_voidSend_String(u8 *Copy_u8data)
{

	u8 LOC_u8Iterator=0;

	while(Copy_u8data[LOC_u8Iterator]!= '\0')
	{
		LCD_voidSend_Char(Copy_u8data[LOC_u8Iterator]);
		LOC_u8Iterator++;

	}


}	

void LCD_voidGotoxy(u8 Copy_u8line ,u8 Copy_u8position)
{
	if( Copy_u8line == LCD_ROW_1 )
	{
		LCD_voidSend_Command(LCD_SET_DDRAM_ADDRESS + ( Copy_u8position - 1 ) );
	}
	else if( Copy_u8line == LCD_ROW_2 )
	{
		LCD_voidSend_Command(LCD_SET_DDRAM_ADDRESS + 0x40 + ( Copy_u8position - 1 ) );
	}
}

void LCD_voidCLEAR_SCREEN(void)
{

	LCD_voidSend_Command(LCD_CLEAR_SCREEN);
	_delay_ms(2);

}
