#include "config.h"

bit SystemTime1Ms = 0; //1ms ��־λ

int setChalnel = 0; //���õ�λ
u8 curretnChalnel = 0;//��ǰ��λ

u8 timeCount = 0;//20ms����
u16 disTimeIndex = 0;//500ms����
volatile bit flash = 0;//��˸��־

u8 keyCode = 0;//������
volatile bit setFlag = 0; //���ñ�־λ

u8 setCount = 0;//���ð������¼���

u8 disSetChalnel[2] = {0};//��������ֵ
u8 disCurretnChalnel[2] = {0};//���浱ǰֵ
void main(){
	
	setGain(0);//���ÿ���Ĭ�ϵ�λ
	
	lcdInit();//Һ����ʾ��ʼ��
	lcdClr();	//Һ������
	show_Pic(0xb8,0x40,&photo);//��ʾ����LOGO
	delayms(200); // 
	delayms(200);
	delayms(200);
	lcdClr();	//����
	lcdDisDefault();//��ʾĬ��ֵ
	Timer0Init();//��ʱ����ʼ��
//	P1 = keyMask;
	for(;;){
		lcdDisCurrentChalnel(disCurretnChalnel[0]);//��ʾ��ǰ��λ
		if(SystemTime1Ms){//1ms
			if(++timeCount == 20){//20ms
				timeCount = 0;
				keyCode = read_key();//��ȡ��ֵ
				if(keyCode != NullValue){//�а�������
					if(keyCode == VerifyValue){//����Ϊ���ð���
						setFlag = ~setFlag; // ���ñ�־λȡ��
						++setCount;//���ð������´�������
						if(setCount > 1) setCount = 0;//������������
					}
					if(setCount == 1){//��һ�ΰ��� ��������ý���
						if(keyCode == AddValue){ //���Ӱ���
							setChalnel++;//��λ����
							if(setChalnel >= 3) setChalnel = 3;
						}
						if(keyCode == DecValue){//��С���� 
							setChalnel--; //��λ��С
							if(setChalnel <= 0) setChalnel = 0;
						}
						disSetChalnel[0] = setChalnel;//���浵λ
					}
					else{ //�˳����� , ��ʾ����
						
						disCurretnChalnel[0] = setChalnel;//��ʾ��ǰֵ
						setGain(setChalnel);//���õ�λ
						lcdDisGain(setChalnel);//��ʾ�Ŵ���
					}
				}
			}
			
			valueFlash(setFlag,&disSetChalnel); //��˸
		}
	}
}
//�жϴ���
void Timer0Isr() interrupt 1 { 
	TH0 = 0xfc ; //��ʱ���¸���ֵ
	TL0 = 0x66 ;
	
	SystemTime1Ms = 1;//1msʱ�䵽
}