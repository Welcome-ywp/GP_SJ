#include "config.h"

/*
//����ɨ��
u8 keyScan(){
	if(keyVerify == 0) return VerifyValue;
	if(keyAdd == 0) return AddValue;
	if(keyDec == 0) return DecValue;
	
	return NullValue;
}*/

//��ȡ��ֵ
u8 read_key()
{
	static u8 keyState = keyStateInt;

	u8 keyPress,keyReturn = NullValue;

	keyPress = keyInput & keyMask;//��������ƽ
	switch(keyState){
		case keyStateInt:
			if(keyPress != keyMask){
				keyState = keyStateWobble;
			}
		break;
			
		case keyStateWobble:
			if(keyPress == (keyInput & keyMask)){
				if(keyPress == 0x60) keyReturn = VerifyValue;
				if(keyPress == 0xa0) keyReturn = DecValue;
				if(keyPress == 0xc0) keyReturn = AddValue;
				keyState = keyStatePress;
			}else{
				keyState = keyStateInt;
			}
		break;
			
		case keyStatePress:
			if(keyPress == keyMask){
				keyState = keyStateInt;
			}
		break;
		default : break;
	}

	return keyReturn;	                    //���ذ���ֵ
}
