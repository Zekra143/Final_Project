/*
 * DIO.h
 *
 * Created: 10/30/2021 3:39:17 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level);
void DIO_WritePort(DIO_PortTypes PortId,Uint8 Data);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId);
Uint8 DIO_ReadPort(DIO_PortTypes PortId);

#endif /* DIO_H_ */