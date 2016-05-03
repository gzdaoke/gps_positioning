//======================================================================
//����Ȩ��(C) COPYRIGHT 2009 ������� WWW.TXMCU.COM  ALL RIGHTS RESERVED
//���������˳��������ѧϰ��ο���������ע����Ȩ��������Ϣ��
//======================================================================
//======================================================================
//  �������ƣ�	 GPSģ����Գ���
//  �ļ����ƣ�  main.c
//  ����������  GPSģ����ն�λ��Ϣ����LCD����ʾ
//  ����ļ���	 main.c LCD.c GPS.c display.c  
//    ͷ�ļ���  LCD.h GPS.h display.h
//  ���������	 GPSģ��ͨ��������Ƭ�����͹̶���ʽ������
//				    ��Ƭ���Ĵ��ڽ��յ����ݺ󣬽��н�������LCD����ʾ
//				    ��λ��Ϣ����������ʱ�䣬��γ�ȣ��ٶȣ��Ƕȣ��߶�
//  Ӳ�����ӣ�	 ��GPSģ�����51STARʵ�����MP3ģ������ϣ���ʹ��TTL��ƽ
//              �ӿں�51��Ƭ������	
//  ά����¼��	 2009-8-23 v1.0	  by xgc
//              2010-1-30 v1.1    by xgc  �����˿�����������
//
//  �������ߣ�  ��㳬  xgc94418297.blog.163.com
//======================================================================

#include <reg52.h>
#include <stdio.h>
#include <string.h>
#include "GPS.h"
#include "LCD.h"
#include "display.h"

sbit led1 = P1^0;  //��������ָʾ��
sbit led2 = P1^1;  //GPRMC������Чָʾ��
sbit led3 = P1^2;  //GPGGA������Чָʾ��

uchar code init1[] = {"GPS ģ����Գ���"};
uchar code init2[] = {"  WWW.TXMCU.COM "};
uchar code init3[] = {"GPS ��ʼ��......"};
uchar code init4[] = {"������λ����...."};

#define   REV_YES    led1 = 0
#define   REV_NO     led1 = 1
#define   RMC_YES    led2 = 0
#define   RMC_NO     led2 = 1
#define   GGA_YES    led3 = 0
#define   GGA_NO     led3 = 1

char xdata rev_buf[80];        //���ջ���
uchar xdata rev_start = 0;     //���տ�ʼ��־
uchar xdata rev_stop  = 0;     //����ֹͣ��־
uchar xdata gps_flag = 0;      //GPS�����־
uchar xdata change_page = 0;   //��ҳ��ʾ��־
uchar xdata num = 0;           //

extern GPS_INFO   GPS;  //��display.c�ж��壬ʹ��ʱҪ��extern

//====================================================================//
//	�﷨��ʽ��	void GPS_Init(void)
//	ʵ�ֹ��ܣ�	GPS��ʼ������LCD����ʾ��ʼ����Ϣ
//	������		��
//	����ֵ��	��
//====================================================================//
void GPS_Init(void)
{
	Lcd_DispLine(0, 0, init1);
	Lcd_DispLine(1, 0, init2);
	Lcd_DispLine(2, 0, init3);
	Lcd_DispLine(3, 0, init4);
	if (GPS_GSV_Parse(rev_buf, &GPS))
	{
		GPS_DispSatellite(); //��ʾ������������
	}
}

/****************************************
���ڳ�ʼ��	
/****************************************/
void Uart_Init(void)
{
	TMOD = 0x21;
	TH0=0x3c;
	TL0=0xb0;
	TH1=0xfd;
	TL1=0xfd;

	TR1=1;     //������ʱ��1
	REN=1;     //�����������    
	SM0=0;
	SM1=1;

	TI=0;
	RI=0;

	EA=1;    //�����ж�
	ES=1;    //����1�ж�����
	ET0 = 1; //��ʱ��1�ж�����
}

/****************************************
������	
/****************************************/
void main(void)
{
	uchar error_num = 0;
	dula = 0;
	wela = 0;
	Uart_Init();  //��ʼ������
	Lcd_Init();	  //��ʼ��LCD
	GPS_Init();   //��ʼ��GPS
	while(1)
	{
		if (rev_stop)   //���������һ��
		{
			TR0 = 1;   //������ʱ��
			REV_YES;
			if (change_page % 2 == 1)  //��ҳ
			{
				if (GPS_GGA_Parse(rev_buf, &GPS))  //����GPGGA
				{
					GGA_YES;
					GPS_DisplayTwo();  //��ʾ�ڶ�ҳ��Ϣ
					error_num = 0;
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;
				}
				else
				{
					error_num++;
					if (error_num >= 20) //���������Ч����20��
					{
						GGA_NO;
						error_num = 20;
						GPS_Init();     //���س�ʼ��
					}
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;
				}

			}
			else
			{
				if (GPS_RMC_Parse(rev_buf, &GPS)) //����GPRMC
				{
					RMC_YES;
					GPS_DisplayOne();	  //��ʾGPS��һҳ��Ϣ
					error_num = 0;
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;	
				}
				else
				{
					error_num++;
					if (error_num >= 20) //���������Ч����20��
					{
						RMC_NO;
						error_num = 20;
						GPS_Init();     //���س�ʼ��
					}
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;
				}
			}
		}
	}
}

/****************************************
��ʱ���ж�	
/****************************************/
void timer0(void) interrupt 1
{
	static uchar count = 0;
	TH0 = 0x3c;
	TL0 = 0xb0;
	count++;
	if (count == 100)  //5����
	{
		count = 0;
		change_page++;  //��ҳ
		if (change_page == 10)
			change_page = 0;
	}	
}

/****************************************
���ڽ����ж�	
/****************************************/
void Uart_Receive(void) interrupt 4
{
	uchar ch;
	ES = 0;
	if (RI)
	{
		ch = SBUF;
		if ((ch == '$') && (gps_flag == 0))  //����յ��ַ�'$'���㿪ʼ����
		{
			rev_start = 1;
			rev_stop  = 0;
		}
	
		if (rev_start == 1)  //��־λΪ1����ʼ����
		{
			rev_buf[num++] = ch;  //�ַ��浽������
			if (ch == '\n')     //������յ�����
			{
				rev_buf[num] = '\0';
				rev_start = 0;
				rev_stop  = 1;
				gps_flag = 1;
				num = 0;
			}
		}
	}
	RI = 0;	 //RI��0�����½���
	ES = 1;	
}
