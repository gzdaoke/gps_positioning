//======================================================================
//【版权】(C) COPYRIGHT 2009 天祥电子 WWW.TXMCU.COM  ALL RIGHTS RESERVED
//【声明】此程序仅用于学习与参考，引用请注明版权和作者信息！
//======================================================================
//======================================================================
//  工程名称：	 GPS模块测试程序
//  文件名称：  main.c
//  功能描述：  GPS模块接收定位信息，在LCD上显示
//  组成文件：	 main.c LCD.c GPS.c display.c  
//    头文件：  LCD.h GPS.h display.h
//  程序分析：	 GPS模块通过串口向单片机发送固定格式的数据
//				    单片机的串口接收到数据后，进行解析，在LCD上显示
//				    定位信息包括：日期时间，经纬度，速度，角度，高度
//  硬件连接：	 将GPS模块插在51STAR实验箱的MP3模块插座上，或使用TTL电平
//              接口和51单片机连接	
//  维护记录：	 2009-8-23 v1.0	  by xgc
//              2010-1-30 v1.1    by xgc  加入了可视卫星数量
//
//  代码作者：  相广超  xgc94418297.blog.163.com
//======================================================================

#include <reg52.h>
#include <stdio.h>
#include <string.h>
#include "GPS.h"
#include "LCD.h"
#include "display.h"

sbit led1 = P1^0;  //接收数据指示灯
sbit led2 = P1^1;  //GPRMC数据有效指示灯
sbit led3 = P1^2;  //GPGGA数据有效指示灯

uchar code init1[] = {"GPS 模块测试程序"};
uchar code init2[] = {"  WWW.TXMCU.COM "};
uchar code init3[] = {"GPS 初始化......"};
uchar code init4[] = {"搜索定位卫星...."};

#define   REV_YES    led1 = 0
#define   REV_NO     led1 = 1
#define   RMC_YES    led2 = 0
#define   RMC_NO     led2 = 1
#define   GGA_YES    led3 = 0
#define   GGA_NO     led3 = 1

char xdata rev_buf[80];        //接收缓存
uchar xdata rev_start = 0;     //接收开始标志
uchar xdata rev_stop  = 0;     //接收停止标志
uchar xdata gps_flag = 0;      //GPS处理标志
uchar xdata change_page = 0;   //换页显示标志
uchar xdata num = 0;           //

extern GPS_INFO   GPS;  //在display.c中定义，使用时要加extern

//====================================================================//
//	语法格式：	void GPS_Init(void)
//	实现功能：	GPS初始化，在LCD上显示初始化信息
//	参数：		无
//	返回值：	无
//====================================================================//
void GPS_Init(void)
{
	Lcd_DispLine(0, 0, init1);
	Lcd_DispLine(1, 0, init2);
	Lcd_DispLine(2, 0, init3);
	Lcd_DispLine(3, 0, init4);
	if (GPS_GSV_Parse(rev_buf, &GPS))
	{
		GPS_DispSatellite(); //显示可视卫星数量
	}
}

/****************************************
串口初始化	
/****************************************/
void Uart_Init(void)
{
	TMOD = 0x21;
	TH0=0x3c;
	TL0=0xb0;
	TH1=0xfd;
	TL1=0xfd;

	TR1=1;     //开启定时器1
	REN=1;     //允许接收数据    
	SM0=0;
	SM1=1;

	TI=0;
	RI=0;

	EA=1;    //开总中断
	ES=1;    //串口1中断允许
	ET0 = 1; //定时器1中断允许
}

/****************************************
主函数	
/****************************************/
void main(void)
{
	uchar error_num = 0;
	dula = 0;
	wela = 0;
	Uart_Init();  //初始化串口
	Lcd_Init();	  //初始化LCD
	GPS_Init();   //初始化GPS
	while(1)
	{
		if (rev_stop)   //如果接收完一行
		{
			TR0 = 1;   //开启定时器
			REV_YES;
			if (change_page % 2 == 1)  //换页
			{
				if (GPS_GGA_Parse(rev_buf, &GPS))  //解析GPGGA
				{
					GGA_YES;
					GPS_DisplayTwo();  //显示第二页信息
					error_num = 0;
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;
				}
				else
				{
					error_num++;
					if (error_num >= 20) //如果数据无效超过20次
					{
						GGA_NO;
						error_num = 20;
						GPS_Init();     //返回初始化
					}
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;
				}

			}
			else
			{
				if (GPS_RMC_Parse(rev_buf, &GPS)) //解析GPRMC
				{
					RMC_YES;
					GPS_DisplayOne();	  //显示GPS第一页信息
					error_num = 0;
					gps_flag = 0;
					rev_stop  = 0;
					REV_NO;	
				}
				else
				{
					error_num++;
					if (error_num >= 20) //如果数据无效超过20次
					{
						RMC_NO;
						error_num = 20;
						GPS_Init();     //返回初始化
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
定时器中断	
/****************************************/
void timer0(void) interrupt 1
{
	static uchar count = 0;
	TH0 = 0x3c;
	TL0 = 0xb0;
	count++;
	if (count == 100)  //5秒钟
	{
		count = 0;
		change_page++;  //换页
		if (change_page == 10)
			change_page = 0;
	}	
}

/****************************************
串口接收中断	
/****************************************/
void Uart_Receive(void) interrupt 4
{
	uchar ch;
	ES = 0;
	if (RI)
	{
		ch = SBUF;
		if ((ch == '$') && (gps_flag == 0))  //如果收到字符'$'，便开始接收
		{
			rev_start = 1;
			rev_stop  = 0;
		}
	
		if (rev_start == 1)  //标志位为1，开始接收
		{
			rev_buf[num++] = ch;  //字符存到数组中
			if (ch == '\n')     //如果接收到换行
			{
				rev_buf[num] = '\0';
				rev_start = 0;
				rev_stop  = 1;
				gps_flag = 1;
				num = 0;
			}
		}
	}
	RI = 0;	 //RI清0，重新接收
	ES = 1;	
}
