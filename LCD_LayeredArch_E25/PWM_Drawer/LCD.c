/*
* LCD.c
*
* Created: 11/5/2021 2:12:40 PM
*  Author: user
*/

#include "LCD.h"

void LCD_Init(void){
	DIO_WriteChannel(LCD_RW,STD_Low);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(100);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);//Set Function 4-Bit & 2Line & 5*8 Dots
	LCD_Cmd(0x06);//Entry Mode move to right and no shift
	LCD_Cmd(0x0C);//Display on & Cursor off and no blinking
	LCD_Cmd(0x01);//Clear LCD
}
void LCD_Cmd(Uint8 cmd){
	Uint8 PortValue = 0;
	DIO_WriteChannel(LCD_RS,STD_Low);
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (cmd & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	
	_delay_ms(5);
	
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (cmd << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(2);
}
void LCD_Char(int8 data){
	Uint8 PortValue = 0;
	DIO_WriteChannel(LCD_RS,STD_High);
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (data & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	
	_delay_ms(5);
	
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (data << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(2);	
}

void LCD_String(int8 * string){
	Uint8 i = 0;
	while(string[i] != '\0'){
		LCD_Char(string[i]);
		i++;
	}
}

void LCD_SetPos(Uint8 line,Uint8 pos){
	switch(line){
		case 1:
		LCD_Cmd(0x80 | (pos & 0x0F));
		break;
		case 2:
		LCD_Cmd(0xC0 | (pos & 0x0F));
		break;
	}
}

void LCD_Custome_Char(Uint8 loc,int8 * msg){
	Uint8 i = 0;
	if(loc < 8){
		LCD_Cmd(0x40 + (loc*8));
		for(i=0;i<8;i++){
			LCD_Char(msg[i]);
		}
	}
}