
#ifndef _GPIO_H
#define _GPIO_H





typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH,
	PORT_NUM
}PORT_NUMBER;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN_NUM

}PIN_NUMBER;

typedef enum
{
	    INPUT_PULL_UP 		     ,
		INPUT_PULL_DOWN		     ,
		INPUT_FLOATING		     ,
		INPUT_ANALOG		     ,
		OUTPUT_OPEN_DRAIN         ,
		OUTPUT_PUSH_PULL          ,
		ALTERANTE_PUSH_PULL       ,
		ALTERANTE_OPEN_DRAIN      ,
		MODE_NUM

}PIN_MODE;


typedef enum
{
	 Low_speed        =0b00,
	 Medium_speed     =0b01,
	 High_speed       =0b10,
	 Very_high_speed  =0b11

}SPEED_MODE;

typedef struct
{
	PORT_NUMBER port;
	PIN_NUMBER pin	;
	PIN_MODE mode;
    SPEED_MODE speed;
}GPIO_PINCONFIGS_t;



typedef enum
{
	LOW ,
	HIGH
}PIN_Value;


typedef enum
{

	AF0_System         = 0b0000,
	AF1_TIM1_2         = 0b0001,
	AF2_TIM3_4_5       = 0b0010,
	AF3_TIM9_10_11     = 0b0011,
	AF4_I2C1_2_3       = 0b0100,
	AF5_SPI1_2_3_4     = 0b0101,
	AF6_SPI3           = 0b0110,
	AF7_USART1_2       = 0b0111,
	AF8_USART6         = 0b1000,
	AF9_I2C2_3         = 0b1001,
	AF10_OTG_FS        = 0b1010,
	AF11               = 0b1011,
	AF12_SDIO          = 0b1100,
	AF13               = 0b1101,
	AF14               = 0b1110,
	AF15_EVENTOUT      = 0b1111,
	AF_NUM


}AF_VALUE;
typedef enum{

GPIO_enuOK = 0,
GPIO_enuNotOK,
GPIO_Invalid_Pin,
GPIO_Invalid_Port,
GPIO_Invalid_Mode,
GPIO_INVALID_VALUE,
GPIO_INVALID_AF
}GPIO_tenuErrorStatus;


/******************************************** APIS **********************************************************/


GPIO_tenuErrorStatus GPIO_enuInitPin(GPIO_PINCONFIGS_t * Copy_strPinConfig);
GPIO_tenuErrorStatus GPIO_enuSetPinValue(GPIO_PINCONFIGS_t * Copy_strPinConfig,PIN_Value Copy_enumPinValue);
GPIO_tenuErrorStatus GPIO_enuGetPinValue(GPIO_PINCONFIGS_t * Copy_strPinConfig, u8 *Add_pu8PinValue);
GPIO_tenuErrorStatus GPIO_enuTogPinValue(GPIO_PINCONFIGS_t * Copy_strPinConfig);
GPIO_tenuErrorStatus GPIO_enuSetPortValue(GPIO_PINCONFIGS_t * Copy_strPinConfig,u16 Copy_u16PortValue);
GPIO_tenuErrorStatus GPIO_enuSelectAF(GPIO_PINCONFIGS_t * Copy_strPinConfig,AF_VALUE Copy_u8AF);


/**************************************************************************************************************/



#endif
