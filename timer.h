#ifndef __TIMER_H__
#define __TIMER_H__

#define SYSCTIL_TIMER   ((*(volatile unsigned long*)(0x400FE000+0x604)))
#define Timer_0         ((*(volatile unsigned long*)(0x40030000)))
#define GPTMCFG         ((*(volatile unsigned long*)(Timer_0+0x000)))
#define GPTMTAMR        ((*(volatile unsigned long*)(Timer_0+0x004)))
#define GPTMCTL         ((*(volatile unsigned long*)(Timer_0+0x00c)))
#define GPTMTAILR       ((*(volatile unsigned long*)(Timer_0+0x028)))
#define GPTMICR         ((*(volatile unsigned long*)(Timer_0+0x024)))
#define GPTMRIS         ((*(volatile unsigned long*)(Timer_0+0x01c)))

#define  One_Shot_Timer_mode                0x01
#define  Edge_Time_mode                     0x02
#define  The_timer_counts_down              0x04


#define  GPTM_Timer_A_Enable                0x01
#define  Positive_edge                      0x0


#define GPTM_Timer_A_Interval_Load_Write 16000-1

void timer_init(void);
int time(int time);
#endif
