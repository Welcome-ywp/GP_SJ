#include "config.h"

bit SystemTime1Ms = 0; //1ms 标志位

int setChalnel = 0; //设置档位
u8 curretnChalnel = 0;//当前档位

u8 timeCount = 0;//20ms计数
u16 disTimeIndex = 0;//500ms计数
volatile bit flash = 0;//闪烁标志

u8 keyCode = 0;//按键码
volatile bit setFlag = 0; //设置标志位

u8 setCount = 0;//设置按键按下计数

u8 disSetChalnel[2] = {0};//缓存设置值
u8 disCurretnChalnel[2] = {0};//缓存当前值
void main(){
	
	setGain(0);//设置开机默认档位
	
	lcdInit();//液晶显示初始化
	lcdClr();	//液晶清屏
	show_Pic(0xb8,0x40,&photo);//显示开机LOGO
	delayms(200); // 
	delayms(200);
	delayms(200);
	lcdClr();	//清屏
	lcdDisDefault();//显示默认值
	Timer0Init();//定时器初始化
//	P1 = keyMask;
	for(;;){
		lcdDisCurrentChalnel(disCurretnChalnel[0]);//显示当前档位
		if(SystemTime1Ms){//1ms
			if(++timeCount == 20){//20ms
				timeCount = 0;
				keyCode = read_key();//获取键值
				if(keyCode != NullValue){//有按键按下
					if(keyCode == VerifyValue){//按键为设置按键
						setFlag = ~setFlag; // 设置标志位取反
						++setCount;//设置按键按下次数计数
						if(setCount > 1) setCount = 0;//按键次数清零
					}
					if(setCount == 1){//第一次按下 则进入设置界面
						if(keyCode == AddValue){ //增加按键
							setChalnel++;//档位增加
							if(setChalnel >= 3) setChalnel = 3;
						}
						if(keyCode == DecValue){//减小按键 
							setChalnel--; //档位减小
							if(setChalnel <= 0) setChalnel = 0;
						}
						disSetChalnel[0] = setChalnel;//缓存档位
					}
					else{ //退出设置 , 显示数据
						
						disCurretnChalnel[0] = setChalnel;//显示当前值
						setGain(setChalnel);//设置档位
						lcdDisGain(setChalnel);//显示放大倍数
					}
				}
			}
			
			valueFlash(setFlag,&disSetChalnel); //闪烁
		}
	}
}
//中断处理
void Timer0Isr() interrupt 1 { 
	TH0 = 0xfc ; //定时重新赋初值
	TL0 = 0x66 ;
	
	SystemTime1Ms = 1;//1ms时间到
}