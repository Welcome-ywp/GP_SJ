#ifndef _GAIN_H_
#define _GAIN_H_

sbit Gain1A = P1^0;
sbit Gain1B = P1^1;
sbit Gain2A = P1^2;
sbit Gain2B = P1^3;

extern void setGain(u16 ch);

#endif