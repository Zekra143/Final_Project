/*
 * LCD.h
 *
 * Created: 11/5/2021 2:12:52 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCD_RS DIO_ChannelB1  
#define LCD_RW DIO_ChannelB2 
#define LCD_E DIO_ChannelB3   

#define LCD_DataPort DIO_PortA

void LCD_Init(void);
void LCD_Cmd(Uint8 cmd);
void LCD_Char(int8 data);
void LCD_String(int8 * string);
void LCD_SetPos(Uint8 line,Uint8 pos);
void LCD_Custome_Char(Uint8 loc,int8 * msg);

#endif /* LCD_H_ */