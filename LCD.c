//=========================================================================
//����Ȩ��(C) COPYRIGHT 2009 ������� WWW.TXMCU.COM  ALL RIGHTS RESERVED
//���������˳��������ѧϰ��ο���������ע����Ȩ��������Ϣ��
//=========================================================================
//=============================================================
//ά����¼��2009-8-23 v1.0		by xgc
//          2010-1-30 v1.1    by xgc  �޸���LCD��ʾBUG
//
//�������ߣ�  ��㳬  xgc94418297.blog.163.com
//=============================================================
#include "LCD.h"

//====================================================================//
// �﷨��ʽ: void delay(uint z)
// ʵ�ֹ��ܣ����뼶��ʱ����
// ��    ����z -- ms
// �� �� ֵ����
//====================================================================//
void delay(uint z)
{
	uint x, y;
	for (x = z; x > 0; x--)
		for(y = 110; y > 0; y--);
}


//====================================================================//
// �﷨��ʽ: static bit Lcd_Busy(void)
// ʵ�ֹ��ܣ����LCDæ״̬��Ϊ1ʱ��æ���ȴ���Ϊ0ʱ���У���дָ�������ݡ�
// ��    ������
// �� �� ֵ��æ״̬
//====================================================================//
static bit Lcd_Busy(void)
{                          
	bit result;

	LCD_RS = 0;
	LCD_RW = 1;
	LCD_EN = 1;
	DelayNOP();

	result = (bit)(P0&0x80);
	LCD_EN = 0;

	return(result); 
}


//====================================================================//
// �﷨��ʽ��void Lcd_WriteCmd(uchar cmd)
// ʵ�ֹ��ܣ�дָ�����ݵ�LCD
// ��    ����Ҫд���ָ��
// �� �� ֵ����
//====================================================================//
void Lcd_WriteCmd(uchar cmd)
{
	while(Lcd_Busy());                          
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_EN = 0;

	_nop_();
	_nop_(); 

	P0 = cmd;

	DelayNOP();
	LCD_EN = 1;

	DelayNOP();
	LCD_EN = 0;  
}

//====================================================================//
// �﷨��ʽ��void Lcd_WriteDat(uchar dat)
// ʵ�ֹ��ܣ�д��ʾ���ݵ�LCD
// ��    ����Ҫ��ʾ������
// �� �� ֵ����
//====================================================================//
void Lcd_WriteDat(uchar dat)
{
	while(Lcd_Busy());                           
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_EN = 0;

	P0 = dat;

	DelayNOP();
	LCD_EN = 1;

	DelayNOP();
	LCD_EN = 0; 
}
//====================================================================//
// �﷨��ʽ��void Lcd_Init(void)
// ʵ�ֹ��ܣ�LCD��ʼ��
// ��    ������
// �� �� ֵ����
//====================================================================//
void Lcd_Init(void)
{ 

	LCD_PSB = 1;         //���ڷ�ʽ
	
	Lcd_WriteCmd(0x34);      //����ָ�����
	delay(5);
	Lcd_WriteCmd(0x30);      //����ָ�����
	delay(5);
	Lcd_WriteCmd(0x0C);      //��ʾ�����ع��
	delay(5);
	Lcd_WriteCmd(0x01);      //���LCD����ʾ����
	delay(5);
}


//====================================================================//
// �﷨��ʽ��void Lcd_SetPos(uchar X,uchar Y)
// ʵ�ֹ��ܣ��趨��ʾλ��
// ��    ����X - �У�Y - ��
// �� �� ֵ����
//====================================================================//
void Lcd_SetPos(uchar X,uchar Y)
{                          
   uchar  pos;
   if (X==0)
     {X=0x80;}
   else if (X==1)
     {X=0x90;}
   else if (X==2)
     {X=0x88;}
   else if (X==3)
     {X=0x98;}
   pos = X+Y ;  
   Lcd_WriteCmd(pos);     //��ʾ��ַ
}

//====================================================================//
// �﷨��ʽ��void Lcd_DispLine(uchar line, uchar pos, uchar *str)
// ʵ�ֹ��ܣ���ʾһ���ַ�
// ��    ����line - ָ���У�pos - ָ��λ�ã��У� str - �ַ���
// �� �� ֵ����
//====================================================================//
void Lcd_DispLine(uchar line, uchar pos, uchar *str)
{
	int i = 0;
	Lcd_SetPos(line, pos);
	while (str[i] != '\0')
	{
		Lcd_WriteDat(str[i]);
		i++;
	}
}