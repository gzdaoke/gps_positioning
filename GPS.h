#ifndef __GPS_H_
#define __GPS_H_

#include "types.h"

#define uchar unsigned char
#define uint  unsigned int
#define CS_OK  1
#define CS_ERROR  0
#define GPS_READY 0
#define GPS_WAIT  1
#define GPS_SUCCESS 2
#define GPS_FAIL 3
#define GPS_INIT_RUNNING 0
#define GPS_INIT_SUCCESS 1
#define GPS_INIT_ERROR   2
#define  GPS_STATE_ERROR 0
#define  GPS_STATE_OK    1

#define GPS_SELECT_DISABLE 0
#define GPS_SELECT_ENABLE  1

#define GPS_READ_ENABLE 0
#define GPS_WRITE_ENABLE 1

#define GPS_START  1
#define GPS_ANT    2
#define GPS_TP     3
#define GPS_TMODE  4
#define GPS_SVIN   5
#define GPS_MSG1   6
#define GPS_MSG2   7
#define GPS_MSG5   10

#define GPS_TIME_0   0
#define GPS_TIME_10  10


typedef struct{
	int year;  
	int month; 
	int  day;
	int hour;
	int minute;
	int second;
}DATE_TIME;

typedef  struct{
	double  latitude;  //����
	double  longitude; //γ��
	int     latitude_Degree;	//��
	int		latitude_Cent;		//��
	int   	latitude_Second;    //��
	int     longitude_Degree;	//��
	int		longitude_Cent;		//��
	int   	longitude_Second;   //��
	float 	speed;      //�ٶ�
	float 	direction;  //����
	float 	height_ground;    //ˮƽ��߶�
	float 	height_sea;       //���θ߶�
	int     satellite;
	uchar 	NS;
	uchar 	EW;
	DATE_TIME D;
}GPS_INFO;

//void GPS_Init(void);
int GPS_RMC_Parse(char *line,GPS_INFO *GPS);
int GPS_GGA_Parse(char *line,GPS_INFO *GPS);
int GPS_GSV_Parse(char *line,GPS_INFO *GPS);

void Int_To_Str(int x,char *Str);

#endif  //__GPS_H_