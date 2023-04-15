#ifndef _LED_cfg_H
#define _LED_cfg_H





typedef struct{

	u8 port;
	u8 pin;
	u8 mode;
	u8 speed;
	u8 Type;
    char *name;

}led_cfg_t;


typedef enum{

	Active_High,
	Active_Low


}Type;

typedef enum{

	led_alarm,
	led_start,
	led_stop,
	led_warning,
	led_count

}name;
















#endif
