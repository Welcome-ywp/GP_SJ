#include "config.h"

void setGain(u16 ch){
	
	switch(ch){
		case 0 : {//ѡ��ͨ��1 (�Ŵ�һ��)
			Gain1A  = 0;// 1��
			Gain1B  = 0;
	
			Gain2A  = 0; //1��
			Gain2B  = 0;
		}break;
			
		case 1 : { //ѡ��ͨ��2 (�Ŵ�10��)
			Gain1A  = 1; //10��
			Gain1B  = 0;
	
			Gain2A  = 0;//1��
			Gain2B  = 0;
		}break;
		case 2 : { //ѡ��ͨ��3 (�Ŵ�100��)
			Gain1A  = 1;//10��
			Gain1B  = 0;
	
			Gain2A  = 1;//10��
			Gain2B  = 0;
		}break;
		case 3 : {//ѡ��ͨ��4 (�Ŵ�500��)
		   Gain1A  = 0;//25��
			Gain1B  = 1;
	
			Gain2A  = 0; //20��
			Gain2B  = 1;
		}break;
		default :
			break;
	}
}