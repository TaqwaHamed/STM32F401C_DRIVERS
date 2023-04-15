#ifndef _SW_cfg_H
#define _SW_cfg_H





typedef struct{

	u8 port;
	u8 pin;
	u8 mode;
	u8 speed;
	u8 Type;
    char *name;

}SW_cfg_t;


typedef enum{

	Pull_Up,
	Pull_Down,
	Floating

}Type;

typedef enum{


	SW_stop,
	SW_start,
	SW_count

}name;









#endif
