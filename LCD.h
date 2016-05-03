#ifndef __LCD_H_
#define __LCD_H_

#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint  unsigned int

#define LCD_data  P0             //���ݿ�
sbit LCD_RS  =  P3^5;            //�Ĵ���ѡ������ 
sbit LCD_RW  =  P3^6;            //Һ����/д����
sbit LCD_EN  =  P3^4;            //Һ��ʹ�ܿ���
sbit LCD_PSB =  P3^7;            //��/����ʽ����
sbit wela    =  P2^6;
sbit dula    =  P2^7;

#define DelayNOP(); {_nop_();_nop_();_nop_();_nop_();};

void delay(uint z);
void Lcd_WriteCmd(uchar cmd);
void Lcd_WriteDat(uchar dat);
void Lcd_Init(void);
void Lcd_SetPos(uchar X,uchar Y);
void Lcd_DispLine(uchar line, uchar pos, uchar *str);

#endif //__LCD_H_