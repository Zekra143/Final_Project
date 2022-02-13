/*
* DIO.c
*
* Created: 10/30/2021 3:40:10 PM
*  Author: user
*/

#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level){
	DIO_PortTypes Portx	= channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch (Portx)
	{
		case DIO_PortA:
		if (level == STD_High)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (level == STD_High)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (level == STD_High)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (level == STD_High)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}


STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId){
	DIO_PortTypes Portx	= channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(Portx){
		case DIO_PortA:
		BitValue = GetBit(PINA_Reg,BitNo);
		break;
		case DIO_PortB:
		BitValue = GetBit(PINB_Reg,BitNo);
		break;
		case DIO_PortC:
		BitValue = GetBit(PINC_Reg,BitNo);
		break;
		case DIO_PortD:
		BitValue = GetBit(PIND_Reg,BitNo);
		break;
	}
	return BitValue;
}

void DIO_WritePort(DIO_PortTypes PortId,Uint8 Data){
	switch (PortId)
	{
		case DIO_PortA:
		PORTA_Reg = Data;
		break;
		case DIO_PortB:
		PORTB_Reg = Data;
		break;
		case DIO_PortC:
		PORTC_Reg = Data;
		break;
		case DIO_PortD:
		PORTD_Reg = Data;
		break;
	}
}

Uint8 DIO_ReadPort(DIO_PortTypes PortId){
	Uint8 Data = 0;
	switch (PortId)
	{
		case DIO_PortA:
		Data = PORTA_Reg;
		break;
		case DIO_PortB:
		Data = PORTB_Reg;
		break;
		case DIO_PortC:
		Data = PORTC_Reg;
		break;
		case DIO_PortD:
		Data = PORTD_Reg;
		break;
	}
	return Data;	
}
