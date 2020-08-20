#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#define PORTA            ((*(volatile unsigned long*)(0x40004000)))
#define PORTB            ((*(volatile unsigned long*)(0x40005000)))
	
#define row      PORTA      //output
#define colunm   PORTB      //input

#define SYSCTIL_GPIO   ((*(volatile unsigned long*)(0x400FE000+0x608)))
#define GPIODATA_A        ((*(volatile unsigned long*)(row +0x000)))
#define GPIODIR_A         ((*(volatile unsigned long*)(row +0x400)))
#define GPIODEN_A         ((*(volatile unsigned long*)(row +0x51c)))
#define GPIODATA_B        ((*(volatile unsigned long*)(colunm+0x000)))
#define GPIODIR_B         ((*(volatile unsigned long*)(colunm+0x400)))
#define GPIODEN_B         ((*(volatile unsigned long*)(colunm+0x51c)))

#define D0 0x01
#define D1 0x02
#define D2 0x04
#define D3 0x08

#define D4 0x01
#define D5 0x02
#define D6 0x04
#define D7 0x08

void delayUs(int n);
void keypad_row_init(void);
void keypad_coulnm_init(void);
unsigned char keypad_getkey(void);
unsigned char key(void);
#endif
