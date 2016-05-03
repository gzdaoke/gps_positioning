//======================================================================
//【版权】(C) COPYRIGHT 2009 天祥电子 WWW.TXMCU.COM  ALL RIGHTS RESERVED
//【声明】此程序仅用于学习与参考，引用请注明版权和作者信息！
//======================================================================
//=============================================================
//维护记录：2009-8-23 v1.0		by xgc
//          2010-1-30 v1.1    by xgc
//          增加函数：GPS_DispSatellite
//
//代码作者：  相广超  xgc94418297.blog.163.com
//=============================================================
#include "display.h"

GPS_INFO   GPS;  //GPS信息结构体

/****************************************
常量定义区
注意，不要定义在头文件中
*****************************************/
uchar code beiwei[]     = "北纬";
uchar code nanwei[]     = "南纬";
uchar code dongjing[]   = "东经";
uchar code xijing[]     = "西经";
uchar code sudu[]       = "速度: ";
uchar code hangxiang[]  = "航向: ";
uchar code gaodu[]      = "高度: ";
uchar code jiaodu[]     = "角度: ";
uchar code haiba[]      = "海拔: ";
uchar code du[]         = "度";
uchar code meter[]      = "米";
uchar code kmperhour[]  = "km/h";
uchar code date[]       = "    年  月  日  ";

void Show_Float(float fla, uchar x, uchar y);

/****************************************
显示时间	
/****************************************/
void GPS_DispTime(void)
{
	uchar i = 0;
	uchar ch;
	char time[5];

	Lcd_DispLine(0, 0, date);  //年月日

	Int_To_Str(GPS.D.year,time);  //将年转换成字符串，存在time中
	Lcd_SetPos(0, 0);             //设置显示地址
	i = 0;
	while(time[i] != '\0')
	{
		ch = time[i++];
		Lcd_WriteDat(ch);	      //显示年
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
显示第一页(日期，时间，经度，纬度)	
/****************************************/
void GPS_DisplayOne(void)
{
	uchar ch, i;
	char info[10];

	Lcd_WriteCmd(0x01);    //清屏

	GPS_DispTime();

	if (GPS.NS == 'N')              //判断是北纬还是南纬
		Lcd_DispLine(2, 0, beiwei);
	else if (GPS.NS == 'S')
		Lcd_DispLine(2, 0, nanwei);

	if (GPS.EW == 'E')              //判断是东经还是西经
		Lcd_DispLine(3, 0, dongjing);
	else if (GPS.EW == 'W')
		Lcd_DispLine(3, 0, xijing);

	Int_To_Str(GPS.latitude_Degree,info);  //纬度
	Lcd_SetPos(2, 3);
	i = 0;
	while(info[i] != '\0')
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE3);

	Int_To_Str(GPS.latitude_Cent,info);  //纬分
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE4);

	Int_To_Str(GPS.latitude_Second,info);  //纬秒
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}

	Int_To_Str(GPS.longitude_Degree,info);  //经度
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

	Int_To_Str(GPS.longitude_Cent,info);  //经分
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat(0xA1);
	Lcd_WriteDat(0xE4);

	Int_To_Str(GPS.longitude_Second,info);  //经秒
	i = 0;
	while(info[i] != '\0') 
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}
}

/****************************************
显示第二页(速度，航向，地面高度，海拔高度)	
/****************************************/
void GPS_DisplayTwo(void)
{
	Lcd_WriteCmd(0x01);    //清屏

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
显示可视卫星数量	
/****************************************/
void GPS_DispSatellite(void)
{
	uchar ch, i;
	char info[10];

	Int_To_Str(GPS.satellite,info);  //纬度
	Lcd_SetPos(3, 7);
	i = 0;
	while(info[i] != '\0')
	{
		ch = info[i++];
		Lcd_WriteDat(ch);
	}	
}

//========================================================
//	语法格式：	void Show_Float(float fla, uchar x, uchar y)
//	实现功能：	在LCD上显示浮点数
//	参数：		fla - 要显示的浮点数
//				x - LCD的x坐标
//				y - LCD的y坐标 
//	返回值：	无
//========================================================
void Show_Float(float fla, uchar x, uchar y)
{
	int integar;
	char Info[10],ch;
	uchar i;
	
	Lcd_SetPos(x, y);		
	integar = (int)fla;             							// 显示整数部分
	Int_To_Str(fla,Info);  //显示整数部分
	i = 0;
	while(Info[i] !='\0')
	{
		ch=Info[i++];
		Lcd_WriteDat(ch);
	}
	Lcd_WriteDat('.');   //显示小数点

	fla = fla - integar; //显示小数部分
	
	fla =  fla * 10;     //0.1                   						// 显示 0.1
	integar = (int) fla;
	fla = fla - integar;				 						// 改变fla的值,使fla总是小于1
	ch = integar + 0x30; 	
	Lcd_WriteDat(ch);
	
	fla =  fla*10;	    //0.01					 						// 显示 0.01
	integar = (int) fla;
	fla = fla - integar;					 					// 改变fla的值,使fla总是小于1
	ch = integar + 0x30 ; 
	Lcd_WriteDat(ch);
}
