#include "timer.h"
#include "common.h"
void timer_init(void){
	SYSCTIL_TIMER|=0x01;
	GPTMCTL&=~(unsigned long)GPTM_Timer_A_Enable;
	GPTMCFG&=~(unsigned long)0x01;
	GPTMTAMR|=(One_Shot_Timer_mode )|(Edge_Time_mode );
	GPTMTAMR&=~(unsigned long)The_timer_counts_down;
	GPTMTAILR|=GPTM_Timer_A_Interval_Load_Write;
	GPTMICR&=~(unsigned long)0x1;
	GPTMCTL|=GPTM_Timer_A_Enable;
}

int time(int time){
	static int t;
	timer_init();
	for(int i=0;i<time;i++){
		while((GPTMRIS&0x01)==0){
			GPTMICR=0x01;
			t=i;
		}
	}
	return t;
}
