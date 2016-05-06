  //====================================================================//
  //  linux系统测试gps模块
  //  
  //====================================================================//

  
#include "gps.h"




u8 GPS_CFG_MSG1[16] =   //开UBX-NAV-TIMEGPS
{
	0XB5,0X62,0X01,0X20, 0X08, 0X00,0X01, 0X20, 
	0X00, 0X01,0X00, 0X00, 0X00, 0X00,0X31, 0X90
};

u8 GPS_CFG_MSG2[16] =   //开UBX-NAV-POSLLH
{
	0XB5,0X62,0X01,0X02, 0X08, 0X00,0X01, 0X02, 
	0X00, 0X01,0X00, 0X00, 0X00, 0X00,0X13, 0XBE
};

/*
u8 GPS_CFG_MSG2[16] =   //开RMC
{
	0XB5,0X62,0X06,0X01, 0X08, 0X00,0XF0, 0X04, 
	0X00, 0X01,0X00, 0X00, 0X00, 0X00,0X04, 0X44
};
*/

u8 GPS_CFG_MSG3[16] =   //关UBX-NAV-TIMEGPS
{
	0XB5,0X62,0X01,0X20, 0X08, 0X00,0X01, 0X20, 
	0X00, 0X00,0X00, 0X00, 0X00, 0X00,0X30, 0X8B
};


/*u8 GPS_CFG_MSG4[16] =   //关UBX-NAV-POSLLH
{
	0XB5,0X62,0X06,0X01, 0X08, 0X00,0X01, 0X02, 
	0X00, 0X00,0X00, 0X00, 0X00, 0X00,0X12, 0XB9
};
*/

u8 GPS_CFG_MSG5[16] =   //开UBX-NAV-STATUS
{
	0XB5,0X62,0X01,0X03, 0X08, 0X00,0X01, 0X03, 
	0X00, 0X01,0X00, 0X00, 0X00, 0X00,0X14, 0XC5
};

u8 GPS_CFG_MSG6[16] =   //关UBX-NAV-STATUS
{
	0XB5,0X62,0X01,0X03, 0X08, 0X00,0X01, 0X03, 
	0X00, 0X00,0X00, 0X00, 0X00, 0X00,0X13, 0XC0
};

/*
u8 GPS_CFG_MSG4[16] =   //关RMC
{
	0XB5,0X62,0X06,0X01, 0X08, 0X00,0XF0, 0X04, 
	0X00, 0X00,0X00, 0X00, 0X00, 0X00,0X03, 0X3F
};
*/
u8 GPS_CFG_PRT [28] =   
{
 0xB5,0x62,0x06,0x00,0x14,0x00,0x01,0x00,0x00,0x00,0xC0,0x08,
 0x00,0x00,0x80,0x25,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,  
 0x00,0x00,0x8A,0x79           
};
u8 GPS_CFG_POLL [9]=
{0xB5,0x62,0x06,0x00,0x01,0x00,0x01,0x08,0x22};

u8 GPS_CFG_PRT_2[28] =//关闭UBX
{0xB5,0x62,0x06,0x00,0x14,0x00,0x01,0x00,
0x00,0x00,0xD0,0x08,0x00,0x00,0x00,0xE1,
0x00,0x00,0x02,0x00,0x02,0x00,0x00,0x00,
0x00,0x00,0xD8,0x9B 
};
u8 GPS_CFG_ANT [12] =   
{
	0XB5,0X62,0X06,0X13, 0X04, 0X00,0X09, 0X00, 
	0X0F, 0X64,0X99, 0X73
};

u8 GPS_CFG_TP[28] =   //Cable Delay == 50 ns 
{	
	0XB5,0X62 ,0X06,0X07,0X14,0X00,0X40,0X42,
	0X0F, 0X00,0XA0,0X86,0X01,0X00,0X01,0X01, 
	0X00,0X00,0X32,0X00,0X00,0X00, 0X00,0X00,
	0X00,0X00,0X0D,0X6C
};

/*
u8 GPS_CFG_TP[28] =   //Cable Delay == 0 ns
{	
	0XB5,0X62 ,0X06,0X07,0X14,0X00,0X40,0X42,
	0X0F, 0X00,0XA0,0X86,0X01,0X00,0X01,0X01, 
	0X00,0X00,0X00,0X00,0X00,0X00, 0X00,0X00,
	0X00,0X00,0XDB,0XDC
};
*/
/*60s 100 平方米*/

u8 GPS_CFG_TMODE[36] =   
{
	0XB5,0X62,0X06,0X1D,0X1C,0X00,0X01,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X84,
	0XD7,0X17,0XEE,0XD8
};

u8 GPS_TIM_SVIN[8] =   
{	
	0XB5,0X62,0X0D,0X04,0X00,0X00,0X11,0X40
};
/*
u8 GPS_CFG_RST[12] =   
{	
	0XB5,0X62,0X06,0X04,0X04,0X00,0X00,0X00,0X01,0X00,0X0F,0X66
};
*/
u8 GPS_CFG_START[12] =   
{ 
 	0XB5,0X62,0X06,0X04,0X04,0X00,0X00,0X00,0X09,0X00,0X17,0X76
};
 
u8 GPS_CFG_STOP[12] =  
{ 
 	0XB5,0X62,0X06,0X04,0X04,0X00,0X00,0X00,0X08,0X00,0X16,0X74
};
u8 GPS_CFG_RESET[12] =   
{ 
 	0XB5,0X62,0X06,0X04,0X04,0X00,0X00,0X00,0X02,0X00,0X10,0X68
};
u8 GPS_CFG_SAVE[] =
{
0xB5,0x62,0x06,0x09,0x0D,0x00,0x00,0x00,0x00,0x00,0x01,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x24,0xC9,
};

u8 CheckCS(u8* Msg,u8 length)
{
	u8 CK_A = 0;
	u8 CK_B = 0;
	u8 i,N;
	
	N = length - 4;
	for(i=0;i<N;i++)
	{
		CK_A = CK_A + Msg[i+2];
		CK_B = CK_B + CK_A;
	}
	
	if((CK_A == Msg[length-2]) && (CK_B == Msg[length-1]))
	{
		return CS_OK;
	}
	else
	{
		return CS_ERROR;
	}	
}

void ChangeEndian_2u8(u16 *digit)
{
	u16 temp1;
	u16 temp2;
	
	temp1 = ((*digit)&0x00ff)<<8;
	temp2 = ((*digit)&0xff00)>>8;
	(*digit) = temp1|temp2;
}
void ChangeEndian_4u8(u32 *digit)
{
	u32 temp1;
	u32 temp2;
	u32 temp3;
	u32 temp4;
		
	temp1 = ((*digit)&0x000000ff)<<24;
	temp2 = ((*digit)&0x0000ff00)<<8;
	temp3 = ((*digit)&0x00ff0000)>>8;
	temp4 = ((*digit)&0xff000000)>>24;
	(*digit) = temp1|temp2|temp3|temp4;
}

/*GPS 延时100ms*/
 void GpsDelay(void)
 {
        usleep(100000);
  }

/*************************************************/
//  函数功能:把int 型数据按照十进制转换成字符串，支持负数显示
/*************************************************/
void ItoA_10(int num, s8* str)
{
	int cur_val;
	int div_val = 0;
	s8 p_target[16];
	s8*p_tmp = p_target;
	int tmp_len = 0;
	int i = 0;
	u8 signflag = 0;


	if(NULL == str)
	{
		return;
	}

	if(num<0)
	{
		num = ~num+1;
		signflag = 1;
	}
	cur_val = num;

	do
	{
		div_val = cur_val%10;
		cur_val = cur_val/10;
		*p_tmp++ = div_val + '0';
	}while(cur_val != 0);
	
	if(signflag == 1)
	{
		*p_tmp++ = '-';
	}
	
	*p_tmp = '\0';
	tmp_len = strlen(p_target);
	p_tmp = str;
	while(i < tmp_len)
	{
		*p_tmp++ = p_target[tmp_len-i-1];
		i++;
	}
	*p_tmp = '\0';
	return;
}

/*************************************************/
//  函数功能:把无符号int 型数据按照十六进制转换成字符串，
//  支持按位数输出(前补"0")
/*************************************************/
void ItoA_16(u32 num, s8 * str,u8 digit)
{
	u32 cur_val;
	u32 div_val = 0;
	s8  p_target[16];
	s8 *p_tmp = p_target;
	int tmp_len = 0;
	int i = 0;

	if (NULL == str)
	{
		return;
	}
	cur_val = num;	
	do
	{
		div_val = cur_val%16;
		cur_val = cur_val/16;
		if(div_val < 10)
		{
			*p_tmp++ = div_val + '0';
		}
		else
		{
			*p_tmp++ = div_val + 'A' - 10;
		}
	}while(cur_val != 0);
	
	*p_tmp = '\0';
	tmp_len = strlen(p_target);

	while(digit>tmp_len)
	{
		*p_tmp = '0';
		p_tmp++;
		*p_tmp = '\0';
		tmp_len = strlen(p_target);
	}
	
	p_tmp = str;
	while(i < tmp_len)
	{
		*p_tmp++ = p_target[tmp_len-i-1];
		i++;
	}
	*p_tmp = '\0';

	return;

}


/********************************************************************   
Function name: GpsInit   
Parameter    : void   
Description  : GPS初始化   
Return       : GPS_SUCCESS     GPS_FAIL
Argument     :    
*********************************************************************/  
u8 GPSState;
u8 GPS_State_Flag;
u8 GPSFlag;
u8 GPSPeriodMsgisON;


u8 GpsInit(void)
{
	u8 Buf[50];
	int BufLen = 0;
    u32 i=0;
	u8 nbyte;
	GPSState = 1;
	GPS_State_Flag=GPS_INIT_RUNNING ;
	GPSFlag = GPS_READY;
	GPSPeriodMsgisON = 0;
	//GPSWaitTime = 0xff;
	//GPSisOverTime = 0;
  
	u8 idex=0;
	GpsSendMsg(GPS_CFG_PRT,sizeof(GPS_CFG_PRT));		
	usleep(100000);	
	tcflush(ptty->fd,TCOFLUSH);	 
   //串口缓冲清零ptty为串口结构体在tty.h中定义
    DBG("GPS Init  Please Wait ... ...\n");
    GpsDelay();
	while(1)
	{
		
		switch(GPSFlag)
		{
			case GPS_READY:
			{
				switch(GPSState)
				{
					case GPS_START:
					{     
						GpsSendMsg(GPS_CFG_START,sizeof(GPS_CFG_START));   		
						GpsDelay();
						GPSFlag=GPS_READY;
						//GPSState = 10;
						GPSState = GPS_MSG5;
						//  GPSFlag = GPS_WAIT;        
						break;
					}	
					
					case GPS_ANT:
					{
						GpsSendMsg(GPS_CFG_ANT,sizeof(GPS_CFG_ANT));	//配置天线功能					
						GpsDelay();
						GPSFlag = GPS_WAIT;
						// GPSWaitTime = 0;
						//DBG("GPS_ANT");
						break;
					}
					case GPS_TP:
					{
						GpsSendMsg(GPS_CFG_TP,sizeof(GPS_CFG_TP));//配置PPS:1s
						GpsDelay();
						GPSFlag = GPS_WAIT;
						//GPSWaitTime = 0;
						//DBG("3");
						break;
					}
					case GPS_TMODE:
					{
						GpsSendMsg(GPS_CFG_TMODE,sizeof(GPS_CFG_TMODE));//survey in
						GpsDelay();
						GPSFlag = GPS_WAIT;

						// GPSWaitTime = 0;
						//DBG("4");
						break;
					}	
					case GPS_SVIN:
					{    
						
						GpsSendMsg(GPS_TIM_SVIN,sizeof(GPS_TIM_SVIN));//survey in 是否结束
						GPSFlag = GPS_WAIT;
						GpsDelay();
						// GPSWaitTime = 0;
						// fflush(stdout);
						//DBG("5\n");
						break;
					}					
					case GPS_MSG1:
					{  
						GpsSendMsg(GPS_CFG_MSG1,sizeof(GPS_CFG_MSG1));//获取GPS时间信息
						GpsDelay();
						GPSFlag = GPS_WAIT;
						//  DBG("6");
						break;
					}	
					case GPS_MSG2:
					{
						GpsSendMsg(GPS_CFG_MSG2,sizeof(GPS_CFG_MSG2));//获取GPS的经度纬度信息
						GpsDelay();
						GPSFlag = GPS_WAIT;
						//DBG("7");
						break;
					}
					case GPS_MSG5:
					{   
						GpsSendMsg(GPS_CFG_MSG5,sizeof(GPS_CFG_MSG5));
						GpsDelay();
						GPSFlag = GPS_WAIT;
						//DBG("10\n");
						//GPSWaitTime = 0;
						break;
					}	
					default:
					{
						break;
					}
				}
				break;
			}	
			case GPS_WAIT:
			{   	
				break;
			}	
			case GPS_SUCCESS:
			{				
				GPS_State_Flag=GPS_INIT_SUCCESS;
				GPSFlag = GPS_SUCCESS;
				return GPS_SUCCESS;
			}	
			case GPS_FAIL:
			{   
				if(idex==2)
				{
				  GpsSendMsg(GPS_CFG_STOP,sizeof(GPS_CFG_STOP));
				  GpsDelay();
				  DealCommand(Buf,&BufLen,GPS_READ_ENABLE,GPS_TIME_0,GPS_SELECT_ENABLE);
				  GPS_State_Flag=GPS_INIT_ERROR;  
				  GPSFlag = GPS_FAIL;
				  return GPS_FAIL;
				}
				idex++;
				DBG("idex=%d\n",idex);
				GPSFlag = GPS_READY;
				GPSState=1;
				continue;		      
			}			
			default:
			{
				break;
			}
		}
        BufLen=0;
		nbyte = GpsReceiveMsg(Buf,&BufLen);
		if(nbyte<=0)             
		{
			GPSFlag=GPS_FAIL;
		}
		else if (nbyte > 0)
	    { 
			if (BufLen !=0)
			{    
			   GpsReceiveDealMsg(Buf,BufLen);		
			}
        }
	}
}
/**********************************************************************
//    GPS 接受信息
**********************************************************************/
u8 GpsReceiveMsg(u8 *Msg,int *length)
{  
     u8 nbyte;    
     nbyte = DealCommand(Msg,length,GPS_READ_ENABLE,GPS_TIME_10,GPS_SELECT_ENABLE);
     return nbyte;
}
/***********************************************************************
//      GPS发送消息
***********************************************************************/
u8 GpsSendMsg(u8* Msg,int length)
{    
    u8 nbyte;
	nbyte = DealCommand(Msg,&length,GPS_WRITE_ENABLE,GPS_TIME_0,GPS_SELECT_ENABLE);	
	return nbyte;
}
/***************************************************************************
//GPS　处理返回的消息START  ANT TP TMODE MSG SVIN STATUS
***************************************************************************/
u8 GpsFix_state;
void GpsReceiveDealMsg(u8* Msg,int length)
{
	
	s8 temp_msg[128];
	int temp_sign;
	u32 temp_unsign;
	s8 temp_logmsg[128];
	u32 passed_time=0;
	u8 GpsFix = 0;
	static u8  GPSPassed_time_flag=0;
	if(CheckCS(Msg,length) == CS_ERROR)
	{		
		GPSFlag = GPS_FAIL;
		return ;
	}
	if(Msg[2] == 0x05)//CFG-ACK
	{
		if(Msg[3] == 0x01)//ACK-ACK
		{
		
/*
			if((Msg[6] == 0x06)&&(Msg[7] == 0x04))//CFG-START 
			{   DBG("start OK\n");
				GPSState = 10;
				GPSFlag = GPS_READY;
			}
*/
			if((Msg[6] == 0x06)&&(Msg[7] == 0x13))//CFG-ANT
			{
				GPSState = GPS_TP;
				GPSFlag = GPS_READY;
			}
			else if((Msg[6] == 0x06)&&(Msg[7] == 0x07))//CFG-TP
			{
				GPSState = GPS_TMODE;
				GPSFlag = GPS_READY;
			}
			else if((Msg[6] == 0x06)&&(Msg[7] == 0x1D))//CFG-TMODE
			{
				GPSState = GPS_SVIN;
				GPSFlag = GPS_READY;
			}
			else if((Msg[6] == 0x06)&&(Msg[7] == 0x01))//CFG-MSG
			{
                if (GPSState == GPS_MSG5)
				{	
					if(GPSPeriodMsgisON == 0)
					{
						GPSPeriodMsgisON = 1;
					}
					else if(GPSPeriodMsgisON == 1)
					{
						GPSPeriodMsgisON = 0;
						if(GpsFix_state == GPS_STATE_ERROR)
						{
							if(GpsFix == GPS_TP)
							{
								GPSState = GPS_MSG1;
								GPSFlag = GPS_READY;
							}
							else
							{
								GPSState = GPS_ANT;
								GPSFlag = GPS_READY;
							}
						}
						else if(GpsFix_state == GPS_STATE_OK)
						{
							if ((GpsFix == GPS_TP)||(GpsFix == GPS_SVIN||GpsFix == GPS_ANT))
							{
								GPSState = GPS_MSG1;
								GPSFlag = GPS_READY;
							}
							else
							{
								GPSState = GPS_ANT;
								GPSFlag = GPS_READY;
							}	
						}
					}
				}
			   else if(GPSState == GPS_MSG1)
				{			
					GPSState = GPS_MSG2;
					GPSFlag = GPS_READY;									
				}
			   else if(GPSState == GPS_MSG2)
				{	
					GPSFlag = GPS_SUCCESS;					
				}
			}
		}
	else if(Msg[3] == 0x00)//ACK-NAK
	{
			if((Msg[6] == 0x06)&&(Msg[7] == 0x1D))//CFG-TMODE
			{  
				GPSState = GPS_SVIN;
				GPSFlag = GPS_READY;	
			}
			else
			{   
			    DBG("GPS CFG NAK\n");	
				GPSFlag = GPS_FAIL;	
			}					
	}	
		return;
	}
	if ((Msg[2] == 0x01) && (Msg[3] == 0x03))//UBX-NAV-STATUS
	{				
		GpsFix = Msg[10];
      	// DBG("GpsFix=%d ",Msg[10]);
		memset(temp_logmsg,0,128);
		memcpy(temp_logmsg, "gpsFix:",30);
		temp_unsign = Msg[10];		
		ItoA_16(temp_unsign,temp_msg,0);
		strcat(temp_logmsg,temp_msg);
		strcat(temp_logmsg,",flags:");
		temp_unsign = Msg[11];
            
		ItoA_16(temp_unsign,temp_msg,0);
		strcat(temp_logmsg,temp_msg);
        //DBG("temp=%s\n",temp_logmsg);	
		GpsSendMsg(GPS_CFG_MSG6,sizeof(GPS_CFG_MSG6));  	
		return;
	}
	
	if ((GPSState == GPS_SVIN) && (Msg[2] == 0x0d) && (Msg[3] == 0x04) )//TIM-SVIN判断survey in 是否结束 
	{  
		memcpy(&passed_time,&Msg[6],4);//passed time
		//ChangeEndian_4u8(&passed_time);
		DBG("passed_time=%d  ",passed_time);
		
		if(passed_time>60)
		{     
			DBG("GPS SVIN Overtime!!!\n");
			GPSPassed_time_flag=0;
			GPSFlag = GPS_FAIL;	
			return;
		}
		
		if(Msg[31] == 1) //active
		{     //sleep
            DBG("Active  Please Wait .....\n");
			if(passed_time==60)
		    {      
			   GPSPassed_time_flag++;
			}
			if(GPSPassed_time_flag==3)
		    {       
	           GPSPassed_time_flag=0;
		       GPSFlag = GPS_FAIL;
		       return;
			}
		       GPSFlag = GPS_READY;
		}
		else if (Msg[31] == 0)
		{     
		    GPSPassed_time_flag=0;
			if(Msg[30] == 1) //valid
			{     
			       //GPSPassed_time_flag=0;
				GPSState = GPS_MSG1;
				GPSFlag = GPS_READY;
			}
			else if(Msg[30] == 0)
			{     
				GPSFlag = GPS_FAIL;
				DBG("GPS SVIN invalid!\n");
			}	
		}	
		return;
	}
	
	return;
}
/*******************************************************************************
//提取GPS 时间和GPS 经纬度
*******************************************************************************/
u8 GpsDealMsg(u8* Msg,u16 length,UL *GPS_Time,int *Latitude,int *Longitude)
{     
    UL iTOW = 0;
	UL week = 0;
	UL week_num=604800;
	//u8 leapS = 0;
	
	u8 towisvalid = 1;
	u8 weekisvalid = 1;
	//u8 leapisvalid = 1;	
     
	UL week_time=604800000;
	int temp;
	double Latitude_long,Longitude_long;
 
	if((Msg[2] == 0x01) && (Msg[3] == 0x20))//UBX-NAV-TIMEGPS
	{				
		towisvalid = Msg[17]&0x1;
	 	weekisvalid = (Msg[17]&0x2)>>1;
	 	//leapisvalid = (Msg[17]&0x4)>>2;	
	 	
	 	if((towisvalid == 1) && (weekisvalid == 1))
	 	{
	 		memcpy(&iTOW,&Msg[6],4);	
			memcpy(&week,&Msg[14],2);
            // DBG("iTOW=%llu,week=%llu",iTOW,week);
			week=week-1;
            *GPS_Time=week*week_time+iTOW;                                                 				 
		    return 1;
	 	}	 	
	 	else
	 	{
			if(towisvalid == 0 )
			{
				DBG("GPS TIMEGPS tow invalid\n");				
			}
			
			if(weekisvalid == 0)
			{
			    DBG("GPS TIMEGPS week invalid\n"); 				 
			}			
	 	}	
  	
	}
	
	if((Msg[2] == 0x01) && (Msg[3] == 0x02))//UBX-NAV-POSLLH
	{
		memcpy(&temp,&Msg[10],4);
		Longitude_long=temp;
		Longitude_long=Longitude_long/10000000*3600; 
		memcpy(&temp,&Msg[14],4);
        Latitude_long=temp;
		Latitude_long=Latitude_long/10000000*3600;
		*Latitude= Latitude_long;
		*Longitude= Longitude_long;
         
		return 2;
	}
	
	
}
/*****************************************************************************
                   GPS 状态检测
*****************************************************************************/
void  GpsCheckState(u8* Msg,u16 length)
{
	u8 GpsFix;
	static u8 fix5Num = 0;
	static u8 CheckCS_num=0;
	if (CheckCS(Msg,length) == CS_ERROR)
	{	
		CheckCS_num++;
		//DBG("checkCS ERROR\n");
		if(CheckCS_num==10)
		{
	        GpsFix_state = GPS_STATE_ERROR;
	        GPS_State_Flag=GPS_STATE_ERROR;
		}
		
		return ;
		
	}
 	CheckCS_num=0;
	if((Msg[2] == 0x01) && (Msg[3] == 0x03))//UBX-NAV-STATUS
	{	
             
		GpsFix = Msg[10];
		DBG("GPS Fix=%d\n",GpsFix);
		if(GpsFix == 0)
		{   
			fix5Num = 0;
			if(GpsFix_state == GPS_STATE_OK||GPS_State_Flag==GPS_INIT_SUCCESS)
			{    
				GPS_State_Flag=GPS_STATE_ERROR;
				GpsFix_state = GPS_STATE_ERROR;
				//DBG("GPS STATE ERROR\n");				
			}
		}
		else
		{
			if(GpsFix_state == GPS_STATE_ERROR)
			{
				if(GpsFix != 5)
				{     
					fix5Num = 0;
					GpsFix_state = GPS_STATE_OK;
					GPS_State_Flag = GPS_STATE_OK;
					//DBG("GPS STATE OK\n");					
				}
				else
				{   
					fix5Num++;
					if(fix5Num>=30)
					{     
					    fix5Num=40;
						GpsFix_state = GPS_STATE_OK;
						GPS_State_Flag=GPS_STATE_OK;
						//DBG("GPS STATE OK\n");                             						
					}			
				}				
			}
			
		}	

		return ;
	}
}	

/***********************************************************************
//串口定义
*************************************************************************/


TTY_INFO *ptty;//全局变量串口结构体
/*读串口信息*/

TTY_INFO *ReadyTty(int id) 
{ 
	TTY_INFO *ptty; 
	
	ptty = (TTY_INFO *)malloc(sizeof(TTY_INFO)); 
	if(ptty == NULL) 
	   return NULL; 
	memset(ptty,0,sizeof(TTY_INFO)); 
	pthread_mutex_init(&ptty->mt,NULL); 
	//sDBG(ptty->name,"/dev/ttyUSB%d",id); 
	strcpy(ptty->name,tty_buff);
	
	ptty->fd = open(ptty->name, O_RDWR | O_NOCTTY |O_NDELAY); 
	if (ptty->fd <0) 
	{ 
		free(ptty); 
		return NULL; 
	} 
	
	tcgetattr(ptty->fd,&ptty->otm); 

	return ptty; 
} 

/*释放串口*/
int CleanTty(TTY_INFO *ptty) 
{ 
	
	if(ptty->fd>0) 
	{ 
		tcsetattr(ptty->fd,TCSANOW,&ptty->otm); 
		close(ptty->fd); 
		ptty->fd = -1; 
		free(ptty); 
		ptty = NULL; 
	} 
	
	return 0; 
} 


/*设置串口的速率*/
int SetTtySpeed(TTY_INFO *ptty, int speed) 
{ 
	int i; 
	
	bzero(&ptty->ntm, sizeof(ptty->ntm)); 
	tcgetattr(ptty->fd,&ptty->ntm); 
	ptty->ntm.c_cflag = /*CS8 |*/ CLOCAL | CREAD; 
	
	switch(speed) 
	{ 
		case 300: 
			ptty->ntm.c_cflag |= B300; 
			break; 
		case 1200: 
			ptty->ntm.c_cflag |= B1200; 
			break; 
		case 2400: 
			ptty->ntm.c_cflag |= B2400; 
			break; 
		case 4800: 
			ptty->ntm.c_cflag |= B4800; 
			break; 
		case 9600: 
			ptty->ntm.c_cflag |= B9600; 
			break; 
		case 19200: 
			ptty->ntm.c_cflag |= B19200; 
			break; 
		case 38400: 
			ptty->ntm.c_cflag |= B38400; 
			break; 
		case 115200: 
			ptty->ntm.c_cflag |= B115200; 
			break; 
	} 
	ptty->ntm.c_iflag = IGNPAR; 
	ptty->ntm.c_oflag = 0; 
	
	tcflush(ptty->fd, TCIFLUSH); 
	tcsetattr(ptty->fd,TCSANOW,&ptty->ntm); 
	
	return 0; 
} 
/*设置串口的数据位 奇偶校验位 停止位*/
int SetTtyParity(TTY_INFO *ptty,int databits,char c,int stopbits) 
{ 
	
	if( tcgetattr(ptty->fd,&ptty->ntm) != 0) 
	{ 
		DBG("SetupSerial [%s]\n",ptty->name); 
		return 1; 
	} 
	
	bzero(&ptty->ntm, sizeof(ptty->ntm)); 
	ptty->ntm.c_cflag = CS8 | CLOCAL | CREAD; 
	ptty->ntm.c_iflag = IGNPAR; 
	ptty->ntm.c_oflag = 0; 
	
	ptty->ntm.c_cflag &= ~CSIZE; 
	switch (databits) 
	{ 
		case 7: 
			ptty->ntm.c_cflag |= CS7; 
			break; 
		case 8: 
			ptty->ntm.c_cflag |= CS8; 
			break; 
		default: 
			DBG("Unsupported data size\n"); 
			return 5; 
	} 
	 
	switch (c) 
	{ 
		case 'n': 
		case 'N': 
			ptty->ntm.c_cflag &= ~PARENB; /* Clear parity enable */ 
			ptty->ntm.c_iflag &= ~INPCK; /* Enable parity checking */ 
			break; 
		case 'o': 
		case 'O': 
			ptty->ntm.c_cflag |= (PARODD|PARENB); 
			ptty->ntm.c_iflag |= INPCK; /* Disnable parity checking */ 
			break; 
		case 'e': 
		case 'E': 
			ptty->ntm.c_cflag |= PARENB; /* Enable parity */ 
			ptty->ntm.c_cflag &= ~PARODD; 
			ptty->ntm.c_iflag |= INPCK; /* Disnable parity checking */ 
			break; 
		case 'S': 
		case 's': /*as no parity*/ 
			ptty->ntm.c_cflag &= ~PARENB; 
			ptty->ntm.c_cflag &= ~CSTOPB; 
			break; 
		default: 
			DBG("Unsupported parity\n"); 
			return 2; 
	} 
	// 

	switch (stopbits) 
	{ 
	case 1: 
		ptty->ntm.c_cflag &= ~CSTOPB; 
		break; 
	case 2: 
		ptty->ntm.c_cflag |= CSTOPB; 
		break; 
	default: 
		DBG("Unsupported stop bits\n"); 
		return 3; 
	} 
	// 
	// 
	ptty->ntm.c_lflag = 0; 
	ptty->ntm.c_cc[VTIME] = 0; // inter-character timer unused 
	ptty->ntm.c_cc[VMIN] = 1; // blocking read until 1 chars received 
	tcflush(ptty->fd, TCIFLUSH); 
	if (tcsetattr(ptty->fd,TCSANOW,&ptty->ntm) != 0) 
	{ 
		DBG("SetupSerial \n"); 
		return 4; 
	} 
	
	return 0; 
} 
/*接受串口数据*/
int RecvnTty(TTY_INFO *ptty,char *pbuf,int size) 
{ 
	int ret,left,bytes; 
	
	left = size; 
	fcntl(ptty->fd,F_SETFL,O_NONBLOCK);
	while (left>0) 
	{ 
		ret = 0; 
		bytes = 0; 
		
		pthread_mutex_lock(&ptty->mt); 
  
		ioctl(ptty->fd, FIONREAD, &bytes); 
		if(bytes>0) 
		{ 
			ret = read(ptty->fd,pbuf,left); 
		} 
		pthread_mutex_unlock(&ptty->mt); 
		if(ret >0) 
		{ 
			left -= ret; 
			pbuf += ret; 
		} 
		usleep(10); 
	} 
	return size - left; 
} 
/*发送串口数据*/
int SendnTty(TTY_INFO *ptty,char *pbuf,int size) 
{ 
	int ret,nleft; 
	char *ptmp; 
	
	ret = 0; 
	nleft = size; 
	ptmp = pbuf; 
	
	while (nleft>0) 
	{ 
		pthread_mutex_lock(&ptty->mt); 
		ret = write(ptty->fd,ptmp,nleft); 
		pthread_mutex_unlock(&ptty->mt); 
		
		if(ret >0) 
		{ 
			nleft -= ret; 
			ptmp += ret; 
		} 
		//usleep(100); 
	} 
	
	return size - nleft; 
} 

int LockTty(TTY_INFO *ptty) 
{ 
	if(ptty->fd < 0) 
	{ 
		return 1; 
	} 
	
	return flock(ptty->fd,LOCK_EX); 
} 
int UnLockTty(TTY_INFO *ptty) 
{ 
	if(ptty->fd < 0) 
	{ 
		return 1; 
	} 
	
	return flock(ptty->fd,LOCK_UN); 
} 
/*串口的初始化*/
TTY_INFO *TtyPortInit(void)
{ 
     TTY_INFO *ptty;
	ptty = ReadyTty(0); 
	if(ptty == NULL) 
	{ 
		DBG("ReadyTty(0) error\n"); 
		//return -1; 
	} 
	// 
	// 
	LockTty(ptty); 
	if(SetTtySpeed(ptty,9600)>0) 
	{ 
		DBG("SetTtySpeed() error\n"); 
		//return -1; 
	} 
	if(SetTtyParity(ptty,8,'N',1)>0) 
	{ 
		DBG("SetTtyParity() error\n"); 
		//return -1; 
	} 
return ptty;
	//CleanTty(ptty); 	
	
}

/********************************************************************   
Function name: 串口数据接收或者写入
Parameter    :   1.unsigned char *remsg,2.int *remsg_length,3.int flag,4.int times,5.int select_flag
Description  :      1.数据  2. 数据长度   3.读写标志0=读1=写 4. 阻塞时间 5. 是否调用select
(如果没有调用select函数函数只有读的功能此时flag与times 与select_flag为0)
Return       :      >0正常 =0无数据 <0 出错
*********************************************************************/ 
int DealCommand(unsigned char *remsg,int *remsg_length,int flag,int times,int select_flag)
{
    int nbyte=0;
    int i=0;
    int idx=0;
	unsigned char buff[256];
    fd_set rfds;
    fd_set wfds;
    struct timeval tv;
    tv.tv_sec=times;
    tv.tv_usec=0;
    FD_ZERO(&rfds);   
    FD_ZERO(&wfds);
    unsigned int longth=0;
    int ret;
   memset(buff,0,256);
   if (select_flag == 0)
    {
	 	while(1)
		  {
			 RecvnTty(ptty,buff,1); 
        
                      if (buff[0]==0xb5)
                      {        while(1)
                  	       {
                               RecvnTty(ptty,&buff[1],1);
								if (buff[1]==0x62)
								{
									RecvnTty(ptty,&buff[2],4);
									memcpy(&longth,&buff[4],2);

									longth=longth+2;
									if (longth >256)
									{ 								        
										return 0;
									}
									RecvnTty(ptty,&buff[6],longth);
									memcpy(&remsg[2],&buff[2],longth+4);
									remsg[0]=0xb5;
									remsg[1]=0x62;
									longth=longth+6;
									nbyte=longth;
									*remsg_length=longth;
									return nbyte;
								} 
								else if (buff[1]==0xb5)
									 {
									   continue;
									 }
								else
								break;				
                  	        }
				 		 continue;
                  	} 
             else 
		     continue;
         }
   	}
 else
 {
	if (flag==0)
    {
		FD_SET(ptty->fd,&rfds);
		ret=select(ptty->fd+1,&rfds,NULL,NULL,&tv);
		if (ret<0)
		{
			perror("select");
			return -1;
		}
		else if (ret==0)
		{
			return 0;
		}
   else
  	 {
		if (FD_ISSET(ptty->fd,&rfds))
		{
			while(1)
			{
				RecvnTty(ptty,buff,1); 

				if(buff[0]==0xb5)
				{  
					while(1)
				     {
						RecvnTty(ptty,&buff[1],1);
						if(buff[1]==0x62)
						{
							RecvnTty(ptty,&buff[2],4);
							memcpy(&longth,&buff[4],2);
							longth=longth+2;
							if(longth >256)
							{ 							                
								return 0;
							}					   
				            RecvnTty(ptty,&buff[6],longth);
							memcpy(&remsg[2],&buff[2],longth+4);
							remsg[0]=0xb5;
							remsg[1]=0x62;
							longth=longth+6;
							nbyte=longth;
							*remsg_length=longth;
							return nbyte;
						} 
						else if(buff[1]==0xb5)
						{
								continue;
						}
						else
						break;
			         }
				continue;
			 } 
			else 
			continue;
		  }
		}
	  }
    }
	else if (flag==1)
	{
		FD_SET(ptty->fd,&wfds);
		ret=select(ptty->fd+1,NULL,&wfds,NULL,&tv);
		if(ret<0)
		{
			perror("select");
			return -1;
		}
		else if(ret==0)
		{
			return 0;
		}
		else
		{
			if(FD_ISSET(ptty->fd,&wfds))
			{
			   nbyte=SendnTty(ptty,remsg,*remsg_length);				 
			}	
				return nbyte;
		}
	}
  }
}
/*	
int send_command(unsigned char *sdmsg,int sdmsg_length)
{       
          int nbyte;
          nbyte=SendnTty(ptty,sdmsg,sdmsg_length);
          return nbyte;

}
*/

/*****************************************************************************************
//    
          InitPipe是管道初始化函数
          管道读写函数 flag=0 读管道，flag=1 写管道
******************************************************************************************/
int InitPipe(int *fd)
{
	if( pipe(fd) < 0 )
	{
		DBG("pipe init error\n");
	    return -1;
	}
	return 0;
}
int PipeReadAndWrite(int *fd,char *Msg,int length,int times,int flag)
{
	fd_set rfds;
	fd_set wfds;
	struct timeval tv;
	tv.tv_sec=times;
	tv.tv_usec=0;
	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	FD_SET(fd[0],&rfds);
	FD_SET(fd[1],&wfds);
	int ret;
	int Msg_length=0;
	if (flag==0)
	{
	   close(fd[1]);
       ret=select(fd[0]+1,&rfds,NULL,NULL,&tv);
	   switch(ret)
	   {
		      case -1:  
			  	       perror("select") ;
				        return -1;
		      case 0:   
			   	      	return 0;
								  
		      default:
			        	if (FD_ISSET(fd[0],&rfds))
			            Msg_length=read(fd[0],Msg,length);
		                return Msg_length;		
	  }
	}

	else if(flag==1)
	{
	   close(fd[0]);	   
       ret=select(fd[1]+1,NULL,&wfds,NULL,&tv);
	   switch(ret)
	   {
	      case -1:   
		  	        perror("select") ;
			        return -1;
	      case  0:  return 0;
							  
	      default:
		  
		        if(FD_ISSET(fd[1],&wfds))
		            Msg_length=write(fd[1],Msg,length);
	                return Msg_length;		
	  }
	}
}


 int  main(void)
{     
       
	u8 BUFF[100];
	s8 Msg[512];
	int i=0;
	int BufLen=0;
	int fd_max=0;
	int select_ret=0;
	int ret=0;
	u8  Msg_length=0;
	UL Time;
	int la;
	int lg;
	u8 nbyte;
	int GPS_Latitude=0;
	int  GPS_Longitude=0;
	int pipe_gps[2],pipe_gps2[2];
	UL GPS_Time;
	ptty=TtyPortInit();     
	InitPipe(pipe_gps);
	InitPipe(pipe_gps2);   
	pid_t pid;
	u8 line[100];
	memset(line,0,100);
	if((pid=fork())<0)
    {	       
		DBG("fork error\n");
	}
	else if(pid >0)
	{ 
		fd_set rfds;
		struct timeval tv;

		close(pipe_gps[0]);
		close(pipe_gps2[1]);
		
		 if (GPS_FAIL==GpsInit())
	     {      
	     
			DBG(" GPS  Init Fail......\n");
			bzero(Msg,12);
			Msg[0]='#';
			Msg[1]=0x0A;
			Msg[2]=0;
			Msg[3]='%';
			write(pipe_gps[1],Msg,4);
		   
		 }														  
		  else   
		  {          
		        GpsSendMsg(GPS_CFG_MSG5,sizeof(GPS_CFG_MSG5));
	            GpsDelay();
		        DBG("GPS Init Success ... ...\n");		
		  }    
	         fd_max = MAX(ptty->fd,pipe_gps2[0]);		  
	         while(1)
	          {  
				memset(&Msg[0],0,12);              		
				tv.tv_sec=5;
				tv.tv_usec=0;
				FD_ZERO(&rfds);
				FD_SET(ptty->fd,&rfds);
				FD_SET(pipe_gps2[0],&rfds);
				select_ret=select(fd_max+1,&rfds,NULL,NULL,&tv);
				if ( select_ret < 0) 
			    {
					perror("select");
					continue;
				}
			    else if(select_ret==0)
			    {                 
				    continue;
			  	}
		        else
				{
			     if(FD_ISSET(pipe_gps2[0],&rfds))
				 {
	                   nbyte=read(pipe_gps2[0],Msg,512);
	                   if(nbyte>0&&Msg[0]=='#')
	              	    {      
	                          nbyte=read(pipe_gps2[0],&Msg[1],4)  ; 
							  if (Msg[4]=='%'&&Msg[1]==0x00)
							   {
							  	  if(Msg[3]==0x01||Msg[3]==0x02)
							  	  {
								      DBG("comand_type_msg[3]=%d..............................\n",Msg[3]);  
									  if (Msg[3]==0x01)
									   {
										  DBG("reset again please wait ... ...\n");
									      GpsSendMsg(GPS_CFG_RESET,sizeof(GPS_CFG_RESET));
						                  GpsDelay();
								       }
				                      if (GPS_FAIL==GpsInit())
				                       {      												 
											DBG(" GPS  Init Fail......\n");
											bzero(Msg,12);
											Msg[0]='#';
											Msg[1]=0x0A;
											Msg[2]=0;
											Msg[3]='%';
											write(pipe_gps[1],Msg,4);
					        	        }															  
						             else   
							          {          
										GpsSendMsg(GPS_CFG_MSG5,sizeof(GPS_CFG_MSG5));
										GpsDelay();                              							
										DBG("GPS Init Success ... ...\n");						
						              }	
								continue;
						  		}					
					         }				
	              	     }
	               }			

			 if (FD_ISSET(ptty->fd,&rfds))
			 {
				if ((nbyte=DealCommand(BUFF,&BufLen,0,0,GPS_SELECT_DISABLE))<=0)
				{					     
					continue;
				}
				 GpsCheckState(BUFF,BufLen);	
				 DBG("GPS_State_Flag=%d\n",GPS_State_Flag);					 
	            if (GPS_State_Flag==GPS_STATE_OK||GPS_State_Flag==GPS_INIT_SUCCESS)
				{       
					ret=GpsDealMsg(BUFF,BufLen,&GPS_Time,&GPS_Latitude,&GPS_Longitude);
					if(ret==1)
					{   
						DBG("GPS Time Ok\n");
						bzero(Msg,12);
						Msg[0]='#';
						Msg[1]=0x01;
						Msg[2]=8;
						memcpy(&Msg[3],&GPS_Time,8);							
						Msg[11]='%';
						write(pipe_gps[1],Msg,12);
					}
					else if(ret==2)
				    {
						DBG("GPS Location Ok\n");
						bzero(Msg,12);
						Msg[0]='#';
						Msg[1]=0x02;
						Msg[2]=8;
						memcpy(&Msg[3],&GPS_Latitude,4);
						memcpy(&Msg[7],&GPS_Longitude,4);							
						Msg[11]='%';
						write(pipe_gps[1],Msg,12);
					 }				
				        continue;
							  
		          }
				else {        
						DBG("GPS Error......i=%d\n",i);
						bzero(Msg,12);
						Msg[0]='#';
						Msg[1]=0x0B;
						Msg[2]=0;
						Msg[3]='%';
						// write(pipe_gps[1],Msg,4);
						continue;                                             							
			         }
		           }
	            }
	         }
	}
	else if (pid==0)
    {
		int fga=0;
		close(pipe_gps2[0]);
		close(pipe_gps[1]);
	    while(1)
		{
			 	
	        if ((nbyte=PipeReadAndWrite(pipe_gps,line,12,1,0))>0)
			{
			 if(line[1]==1)
			 {
			 	memcpy(&Time,&line[3],8);
				DBG("pid==1..........................................\n");
				DBG("i am the time=%llu............\n",Time);			
			 }
			 else if(line[1]==2)
			 {
			 	DBG("pid==2............................................\n");
			 	memcpy(&la,&line[3],4);
				memcpy(&lg,&line[7],4);
				DBG("la=%d.......lg=%d.......\n",la,lg);	
				 
			 }
			 else if(line[1]==0x0A)
			 {
				DBG("gps init again\n");
				Msg[0]='#';
				Msg[1]=0x00;
				Msg[2]=0x01;
				Msg[3]=0x01;
				Msg[4]='%';
				DBG("fga===%d\n",fga);	
				nbyte=write(pipe_gps2[1],Msg,5);
				DBG("nbyte=%d\n",nbyte);
			 }
			 else if(line[1]==0x00)
			 {
				DBG("gps reset again\n");
				Msg[0]='#';
				Msg[1]=0x00;
				Msg[2]=0x01;
				Msg[3]=0x01;
				Msg[4]='%';
				DBG("fga===%d\n",fga);	
				nbyte=write(pipe_gps2[1],Msg,5);
				DBG("nbyte=%d\n",nbyte);
			 }
			// nbyte=PipeReadAndWrite(pipe_fd,Msg,5,0,1);
			 }
			 else
	             continue;
	               }
           }
     }
       
       

