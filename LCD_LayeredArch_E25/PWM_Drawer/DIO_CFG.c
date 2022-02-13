/*
* DIO_CFG.c
*
* Created: 10/30/2021 4:28:18 PM
*  Author: user
*/

#include "DIO_CFG.h"

DIO_PinCfg PinDirInit[] = {
	//PORTA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_High},//pin6
	{Output,STD_High}
	
};

void DIO_Init(){
	Uint8 count = DIO_ChannelA0;
	DIO_PortTypes Portx;
	DIO_ChannelTypes BitNo;
	for (count=DIO_ChannelA0;count<PINCOUNT;count++)
	{
		Portx = count/8;
		BitNo = count%8;
		switch(Portx){
			case DIO_PortA:
			if(PinDirInit[count].PinDir == Output){
				SetBit(DDRA_Reg,BitNo);
			}
			else{
				ClearBit(DDRA_Reg,BitNo);
			}
			break;
			case DIO_PortB:
			if(PinDirInit[count].PinDir == Output){
				SetBit(DDRB_Reg,BitNo);
			}
			else{
				ClearBit(DDRB_Reg,BitNo);
			}
			break;
			case DIO_PortC:
			if(PinDirInit[count].PinDir == Output){
				SetBit(DDRC_Reg,BitNo);
			}
			else{
				ClearBit(DDRC_Reg,BitNo);
			}
			break;
			case DIO_PortD:
			if(PinDirInit[count].PinDir == Output){
				SetBit(DDRD_Reg,BitNo);
			}
			else{
				ClearBit(DDRD_Reg,BitNo);
			}
			break;
		}
	}
}