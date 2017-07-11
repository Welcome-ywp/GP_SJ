#include "config.h"

void setGain(u16 ch){
	
	switch(ch){
		case 0 : {//选中通道1 (放大一倍)
			Gain1A  = 0;// 1倍
			Gain1B  = 0;
	
			Gain2A  = 0; //1倍
			Gain2B  = 0;
		}break;
			
		case 1 : { //选中通道2 (放大10倍)
			Gain1A  = 1; //10倍
			Gain1B  = 0;
	
			Gain2A  = 0;//1倍
			Gain2B  = 0;
		}break;
		case 2 : { //选中通道3 (放大100倍)
			Gain1A  = 1;//10倍
			Gain1B  = 0;
	
			Gain2A  = 1;//10倍
			Gain2B  = 0;
		}break;
		case 3 : {//选中通道4 (放大500倍)
		   Gain1A  = 0;//25倍
			Gain1B  = 1;
	
			Gain2A  = 0; //20倍
			Gain2B  = 1;
		}break;
		default :
			break;
	}
}