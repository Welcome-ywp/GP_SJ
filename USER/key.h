#ifndef _KEY_H_
#define _KEY_H_

sbit keyAdd = P1^5;
sbit keyDec = P1^6;
sbit keyVerify = P1^7;

#define AddValue 0xc0   //P15   1100 1111
#define DecValue 0xa0   //P16   1010 1111
#define VerifyValue 0x60  //P17 0110 1111
#define NullValue 0xff   //无按键

#define keyMask 0xe0
#define keyInput P1

#define keyStateInt    0  //初始状态
#define keyStateWobble 1  //抖动状态
#define keyStatePress  2  //按下状态
#define keyStateRelase 3  //释放状态

//#define keyDown 0x01

extern u8 keyScan();
extern u8 read_key();

#endif