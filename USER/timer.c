#include "config.h"

void Timer0Init(){

	TMOD &= 0xf0 ;
	TMOD |= 0x01 ; //��ʱ��0������ʽ1
	TH0 = 0xfc ; //��ʱ����ֵ
	TL0 = 0x66 ;
	TR0 = 1 ;
	ET0 = 1 ;
	EA = 1;
}
