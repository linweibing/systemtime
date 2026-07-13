/******************************************************************************
* Copyright (c) 2026 lin
* SPDX-License-Identifier: MIT
******************************************************************************/

#include "systemtime.h"

/*************************************************
变量定义
*************************************************/
static u8 s_u8BaseTimeCnt = 0;

static u8 s_u8Light100msCnt = 0;
static u8 s_u8Light200msCnt = 0;
static u8 s_u8Light500msCnt = 0;
static u8 s_u8Light1sCnt = 0;
static u8 s_u8Light2sCnt = 0;
static u8 s_u8Light3sCnt = 0;
static u8 s_u8Light5sCnt = 0;
static u8 s_u8Light10sCnt = 0;

static LIGHT_TypeDef s_sLightFlag = {0};

/******************************************************************
函数名称：						F_GetBaseTimexms
功能描述：						获取定时xms标志
调用本函数的时钟周期：			 无
输入参数：						无
输出参数：						返回值：定时标志
其他说明：						无
*******************************************************************/																												
u8 F_GetBaseTime12_5ms(void){
	return ((s_u8BaseTimeCnt&0x01)==1)?1:0;
}

u8 F_GetBaseTime25ms(void){
	return (((s_u8BaseTimeCnt&0x07)==2)||((s_u8BaseTimeCnt&0x07)==6))?1:0;
}

u8 F_GetBaseTime50ms(void){
	return (((s_u8BaseTimeCnt&0x0f)==4)||((s_u8BaseTimeCnt&0x0f)==12))?1:0;
}

u8 F_GetBaseTime100ms(void){
	return (((s_u8BaseTimeCnt&0x1f)==8)||((s_u8BaseTimeCnt&0x1f)==24))?1:0;
}

u8 F_GetBaseTime200ms(void){
	return (((s_u8BaseTimeCnt&0x3f)==16)||((s_u8BaseTimeCnt&0x3f)==48))?1:0;
}

u8 F_GetBaseTime400ms(void){
	return (((s_u8BaseTimeCnt&0x7f)==32)||((s_u8BaseTimeCnt&0x7f)==96))?1:0;
}

u8 F_GetBaseTime800ms(void){
	return (((s_u8BaseTimeCnt&0xff)==64)||((s_u8BaseTimeCnt&0xff)==192))?1:0;
}

u8 F_GetBaseTime1600ms(void){
	return ((s_u8BaseTimeCnt&0xff)==128)?1:0;
}

/******************************************************************
函数名称：						F_BaseTimeCnt
功能描述：						时基计时
调用本函数的时钟周期：			 6.25ms
输入参数：						无
输出参数：						无
其他说明：						无
*******************************************************************/
void F_BaseTimeCnt(void)
{
	s_u8BaseTimeCnt++;
}

/******************************************************************
函数名称：						F_GetLightxms
功能描述：						获取闪烁xms标志
调用本函数的时钟周期：			 无
输入参数：						无
输出参数：						返回值：闪烁标志
其他说明：						无
*******************************************************************/																												
u8 F_GetLight100ms(void){
	return def_Light100ms;
}

u8 F_GetLight200ms(void){
	return def_Light200ms;
}

u8 F_GetLight500ms(void){
	return def_Light500ms;
}

u8 F_GetLight1s(void){
	return def_Light1s;
}

u8 F_GetLight2s(void){
	return def_Light2s;
}

u8 F_GetLight3s(void){
	return def_Light3s;
}

u8 F_GetLight5s(void){
	return def_Light3s;
}

u8 F_GetLight10s(void){
	return def_Light10s;
}

/******************************************************************
函数名称：						F_LightCnt
功能描述：						闪烁计时
调用本函数的时钟周期：			 6.25ms
输入参数：						无
输出参数：						无
其他说明：						无
*******************************************************************/
void F_LightCnt(void)
{
	if(++s_u8Light100msCnt >= def_Light100msNum){
			s_u8Light100msCnt = 0;
			def_Light100ms = ~def_Light100ms;
			if(++s_u8Light200msCnt >= def_Light200msNum){
					s_u8Light200msCnt = 0;
					def_Light200ms = ~def_Light200ms;
			}
			if(++s_u8Light500msCnt >= def_Light500msNum){
					s_u8Light500msCnt = 0;
					def_Light500ms = ~def_Light500ms;
			}
			if(++s_u8Light1sCnt >= def_Light1sNum){
					s_u8Light1sCnt = 0;
					def_Light1s = ~def_Light1s;
			}
			if(++s_u8Light2sCnt >= def_Light2sNum){
					s_u8Light2sCnt = 0;
					def_Light2s = ~def_Light2s;
			}			
			if(++s_u8Light3sCnt >= def_Light3sNum){
					s_u8Light3sCnt = 0;
					def_Light3s = ~def_Light3s;
			}	
			if(++s_u8Light5sCnt >= def_Light5sNum){
					s_u8Light5sCnt = 0;
					def_Light5s = ~def_Light5s;
			}	
			if(++s_u8Light10sCnt >= def_Light10sNum){
					s_u8Light10sCnt = 0;
					def_Light10s = ~def_Light10s;
			}				
	}
}



