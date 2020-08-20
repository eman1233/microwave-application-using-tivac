#include "keypad.h"
#include "lcd.h"
#include "timer.h"
#include "common.h"
static char t;
static char k;
int main(void){
	keypad_row_init();
	keypad_coulnm_init();
	lcd_init();
	k=keypad_getkey();
	t=(char)time(k);
	if((door_sensor&0x1)&&(wait_sensor&0x1)){
	}
	if((GPIODATA_E&start_button)==1){
		GPIODATA_E|=lamp;
		GPIODATA_E|=heater;
		GPIODATA_E|=motor_close;
		lcd_write(t);
	}
	if((GPIODATA_E&cancel_button)){
		GPIODATA_E&=~(unsigned long)heater;
	}
	
}


