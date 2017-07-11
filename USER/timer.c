#include "config.h"

void Timer0Init(){

	TMOD &= 0xf0 ;
	TMOD |= 0x01 ; //定时器0工作方式1
	TH0 = 0xfc ; //定时器初值
	TL0 = 0x66 ;
	TR0 = 1 ;
	ET0 = 1 ;
	EA = 1;
}
