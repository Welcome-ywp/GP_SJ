#ifndef _LCD_H_
#define _LCD_H_

#define LcdPort P2
#define nop {_nop_(),_nop_();}

#define showLeft {CS1 = 0;	CS2 = 1;};
#define showRight {CS1 = 1;	CS2 = 0;};

sbit EN = P0^1;
sbit RW = P0^2;
sbit RS = P0^3;
sbit CS1 = P3^7;
sbit CS2 = P3^6;

extern void lcdInit();
extern void lcdCheckBusy();
extern void lcdWriteCom(u8 com);
extern void lcdWriteData(u8 dat);
extern void lcdDisWords(u8 page,u8 lie, u8 *hzk);
extern void lcdDisNum(u8 page,u8 lie, u8 code *hzk);
extern void lcdDisDefault();
extern void lcdDisGain(u8 gain);
extern void lcdClr();

extern void lcdDisSetChalnel(u8 chalnel);
extern void lcdDisCurrentChalnel(u8 chalnel);
extern void valueFlash(bit setFlag,u8 *chalnel);


extern void delayms(u8 time);

extern void show_Pic(unsigned char page,unsigned char lineaddress, unsigned char table[8][128]);
	

extern char code shen[32]; //申
extern char code jing[32]; //静
extern char code dang[32];//档
extern char code wei[32];//位
extern char code now[32];//当
extern char code qian[32];//前
extern char code she[32];//设
extern char code zhi[32];//置
extern char code zuo[32];//作
extern char code pin[32];//品
extern char code fang[32];//放
extern char code da[32];//大
extern char code bei[32];//倍
extern char code shu[32];
extern char code num[9][16];
extern char code photo[8][128];

#endif 