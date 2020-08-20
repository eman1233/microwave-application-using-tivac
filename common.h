#ifndef __COMMON_H__
#define __COMMON_H__

#define SYSCTIL_GPIO   ((*(volatile unsigned long*)(0x400FE000+0x608)))
#define PORTE           ((*(volatile unsigned long*)(0x40024000)))
#define GPIODATA_E      ((*(volatile unsigned long*)(PORTE +0x000)))
#define GPIODIR_E       ((*(volatile unsigned long*)(PORTE +0x400)))
#define GPIODEN_E       ((*(volatile unsigned long*)(PORTE+0x51c)))

#define start_button 0x01
#define door_sensor  0x02
#define wait_sensor 0x04
#define lamp 0x8
#define motor_close 0x10
#define cancel_button 0x20
#define heater 0x40

void init (void);
#endif
