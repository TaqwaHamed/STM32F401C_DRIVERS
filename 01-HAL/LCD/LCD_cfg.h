/*
 * LCD_cfg.h
 *
 * Created: 2/10/2023 12:57:10 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#define EIGHT_BIT	0
#define FOUR_BIT	1

#define LOW_NIBBLE	0
#define HIGH_NIBBLE	1

/*	
   select LCD_MODE:
   	EIGHT_BIT
	FOUR_BIT   	
*/
#define LCD_MODE		EIGHT_BIT

#if LCD_MODE==FOUR_BIT
/*	
   select :
   	LOW_NIBBLE
	HIGH_NIBBLE   	
*/
#define NIBBLE  LOW_NIBBLE

#endif

#define LCD_BLOCK_SIZE   8


typedef enum{
	 LCD_RS_PIN ,
	 LCD_RW_PIN ,
	 LCD_EN_PIN ,
	 LCD_D0_PIN ,
	 LCD_D1_PIN ,
	 LCD_D2_PIN ,
	 LCD_D3_PIN ,
	 LCD_D4_PIN ,
	 LCD_D5_PIN ,
	 LCD_D6_PIN ,
	 LCD_D7_PIN,
	 LCD_PIN_NUM
}LCD_Pins;



#endif /* LCD_CFG_H_ */
