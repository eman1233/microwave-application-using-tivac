#include "common.h"
void init (void){
	SYSCTIL_GPIO|=0x10;
	GPIODEN_E|=(start_button)|(door_sensor)|(wait_sensor)|(lamp)|(motor_close)|(cancel_button)|(heater);
	GPIODIR_E|=(motor_close)|(heater);
	GPIODIR_E&=~(unsigned long)((start_button)|(wait_sensor)|(door_sensor)|(cancel_button));
}
