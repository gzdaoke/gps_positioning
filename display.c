//======================================================================
//����Ȩ��(C) COPYRIGHT 2009 ������� WWW.TXMCU.COM  ALL RIGHTS RESERVED
//���������˳��������ѧϰ��ο���������ע����Ȩ��������Ϣ��
//======================================================================
//=============================================================
//ά����¼��2009-8-23 v1.0		by xgc
//          2010-1-30 v1.1    by xgc
//          ���Ӻ�����GPS_DispSatellite
//
//�������ߣ�  ��㳬  xgc94418297.blog.163.com
//=============================================================
#include "display.h"

GPS_INFO   GPS;  //GPS��Ϣ�ṹ��

/****************************************
����������
ע�⣬��Ҫ������ͷ�ļ���
*****************************************/
uchar code beiwei[]     = "��γ";
uchar code nanwei[]     = "��γ";
uchar code dongjing[]   = "����";
uchar code xijing[]     = "����";
uchar code sudu[]       = "�ٶ�: ";
uchar code hangxiang[]  = "����: ";
uchar code gaodu[]      = "�߶�: ";
uchar code jiaodu[]     = "�Ƕ�: ";
uchar code haiba[]      = "����: ";
uchar code du[]         = "��";
uchar code meter[]      = "��";
uchar code kmperhour[]  = "km/h";
uchar code date[]       = "    ��  ��  ��  ";

void Show_Float(float fla, uchar x, uchar y);

/****************************************
��ʾʱ��	
/****************************************/
void GPS_DispTime(void)
{
	uchar i = 0;
	uchar ch;
	char time[5];

	Lcd_DispLine(0, 0, date);  //������

	Int_To_Str(GPS.D.year,time);  //����ת�����ַ���������time��
	Lcd_SetPos(0, 0);             //������ʾ��ַ
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	      //��ʾ��
	}

	Int_To_Str(GPS.D.month,time);
	Lcd_SetPos(0, 3);
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	
	}

	Int_To_Str(GPS.D.day,time);
	Lcd_SetPos(0, 5);
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	
	}

	Int_To_Str(GPS.D.hour,time);
	Lcd_SetPos(1, 1);
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	
	}
	Lcd_WriteDat(' ');
	Lcd_WriteDat(':');

	Int_To_Str(GPS.D.minute,time);
	Lcd_SetPos(1, 3);
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	
	}
	Lcd_WriteDat(' ');
	Lcd_WriteDat(':');

	Int_To_Str(GPS.D.second,time);
	Lcd_SetPos(1, 5);
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	
	}
}

/****************************************
��ʾ��һҳ(���ڣ�ʱ�䣬���ȣ�γ��)	
/****************************************/
void GPS_DisplayOne(void)
{
	uchar ch, i;
	char info[10];

	Lcd_WriteCmd(0x01);    //����

	GPS_DispTime();

	if (GPS.NS == 'N')              //�ж��Ǳ�γ������γ
		Lcd_DispLine(2, 0, beiwei);
	else if (GPS.NS == 'S')
		Lcd_DispLine(2, 0, nanwei);

	if (GPS.EW == 'E')              //�ж��Ƕ�����������
		Lcd_DispLine(3, 0, dongjing);
	else if (GPS.EW == 'W')
		Lcd_DispLine(3, 0, xijing);

	Int_To_Str(GPS.latitude_Degree,info);  //γ��
	Lcd_SetPos(2, 3);
	i = 0;
	while(info[i] != '\0')
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE3);

	Int_To_Str(GPS.latitude_Cent,info);  //γ��
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE4);

	Int_To_Str(GPS.latitude_Second,info);  //γ��
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}

	Int_To_Str(GPS.longitude_Degree,info);  //����
	Lcd_SetPos(3, 2);
	Lcd_WriteDat(' ');
	i = 0;
	while(info[i] != '\0')
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE3);

	Int_To_Str(GPS.longitude_Cent,info);  //����
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE4);

	Int_To_Str(GPS.longitude_Second,info);  //����
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
}

/****************************************
��ʾ�ڶ�ҳ(�ٶȣ����򣬵���߶ȣ����θ߶�)	
/****************************************/
void GPS_DisplayTwo(void)
{
	Lcd_WriteCmd(0x01);    //����

	Lcd_DispLine(0, 0, sudu);
	Lcd_DispLine(1, 0, hangxiang);
	Lcd_DispLine(2, 0, gaodu);
	Lcd_DispLine(3, 0, haiba);

	Show_Float(GPS.speed, 0, 3);
	Lcd_DispLine(0, 6, kmperhour);

	Show_Float(GPS.direction, 1, 3);
	Lcd_DispLine(1, 6, du);
	
	Show_Float(GPS.height_ground, 2, 3);
	Lcd_DispLine(2, 6, meter);

	Show_Float(GPS.height_sea, 3, 3);
	Lcd_DispLine(3, 6, meter);	
}

/****************************************
��ʾ������������	
/****************************************/
void GPS_DispSatellite(void)
{
	uchar ch, i;
	char info[10];

	Int_To_Str(GPS.satellite,info);  //γ��
	Lcd_SetPos(3, 7);
	i = 0;
	while(info[i] != '\0')
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}	
}

//========================================================
//	�﷨��ʽ��	void Show_Float(float fla, uchar x, uchar y)
//	ʵ�ֹ��ܣ�	��LCD����ʾ������
//	������		fla - Ҫ��ʾ�ĸ�����
//				x - LCD��x����
//				y - LCD��y���� 
//	����ֵ��	��
//========================================================
void Show_Float(float fla, uchar x, uchar y)
{
	int integar;
	char Info[10],ch;
	uchar i;
	
	Lcd_SetPos(x, y);		
	integar = (int)fla;             							// ��ʾ��������
	Int_To_Str(fla,Info);  //��ʾ��������
	i = 0;
	while(Info[i] !='\0')
	{
		ch=Info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat('.');   //��ʾС����

	fla = fla - integar; //��ʾС������
	
	fla =  fla * 10;     //0.1                   						// ��ʾ 0.1
	integar = (int) fla;
	fla = fla - integar;				 						// �ı�fla��ֵ,ʹfla����С��1
	ch = integar + 0x30; 	
	Lcd_WriteDat(ch);
	
	fla =  fla*10;	    //0.01					 						// ��ʾ 0.01
	integar = (int) fla;
	fla = fla - integar;					 					// �ı�fla��ֵ,ʹfla����С��1
	ch = integar + 0x30 ; 
	Lcd_WriteDat(ch);
}
