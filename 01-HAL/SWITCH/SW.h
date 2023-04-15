#ifndef _SW_H
#define _SW_H







// CHECK THE READ OF SWITCH IS ONE OF THE FOLLOWING MACROS
#define  PRESSED       ((u8)1)
#define  NOT_PRESSED   ((u8)0)

typedef enum{

	SW_enuNOK = 0,
	SW_enuOK ,
	SW_enuNullPtr

}SW_tenuErrorStatus;

void SW_enuInit(void);
SW_tenuErrorStatus SW_enuRead(u8 SW, u8 * Add_pu8SWValue);
















#endif
