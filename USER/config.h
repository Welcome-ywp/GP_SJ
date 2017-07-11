#ifndef _CONFIG_H_
#define _CONFIG_H_

typedef unsigned char u8;
typedef unsigned int u16;

#include <stc15.h>
#include "gain.h"
#include "intrins.h"
#include "lcd.h"
#include "key.h"
#include "timer.h"


extern int setChalnel;
extern u8 curretnChalnel;

extern u8 timeCount;
extern u16 disTimeIndex;
extern bit flash;

extern u8 disSetChalnel[2];
extern u8 disCurretnChalnel[2];

#endif