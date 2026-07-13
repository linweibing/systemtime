/******************************************************************************
* Copyright (c) 2026 lin
* SPDX-License-Identifier: MIT
******************************************************************************/
 
#ifndef _SYSTEMTIME_H_
#define _SYSTEMTIME_H_

/*************************************************
宏定义
*************************************************/
typedef union{
     unsigned char g_u8Data;
	 struct{
		  unsigned char b0 : 1;
		  unsigned char b1 : 1;
		  unsigned char b2 : 1;
		  unsigned char b3 : 1;
		  unsigned char b4 : 1;
		  unsigned char b5 : 1;
		  unsigned char b6 : 1;
		  unsigned char b7 : 1;
		}bit;
}LIGHT_TypeDef;

extern static LIGHT_TypeDef 	s_sLightFlag;//闪烁标志

#define def_Light100ms			s_sLightFlag.bit.b0
#define def_Light200ms			s_sLightFlag.bit.b1
#define def_Light500ms			s_sLightFlag.bit.b2
#define def_Light1s				s_sLightFlag.bit.b3
#define def_Light2s				s_sLightFlag.bit.b4
#define def_Light3s				s_sLightFlag.bit.b5
#define def_Light5s				s_sLightFlag.bit.b6
#define def_Light10s			s_sLightFlag.bit.b7

#define def_Light100msNum		16
#define def_Light200msNum		2
#define def_Light500msNum		5
#define def_Light1sNum			10
#define def_Light2sNum			20
#define def_Light3sNum			30
#define def_Light5sNum			50
#define def_Light10sNum			100

/*************************************************
外部声明
*************************************************/
extern u8 F_GetBaseTime12_5ms(void);
extern u8 F_GetBaseTime25ms(void);
extern u8 F_GetBaseTime50ms(void);
extern u8 F_GetBaseTime100ms(void);
extern u8 F_GetBaseTime200ms(void);
extern u8 F_GetBaseTime400ms(void);
extern u8 F_GetBaseTime800ms(void);
extern u8 F_GetBaseTime1600ms(void);
extern void F_BaseTimeCnt(void);

extern u8 F_GetLight100ms(void);
extern u8 F_GetLight200ms(void);
extern u8 F_GetLight500ms(void);
extern u8 F_GetLight1s(void);
extern u8 F_GetLight2s(void);
extern u8 F_GetLight3s(void);
extern u8 F_GetLight5s(void);
extern u8 F_GetLight10s(void);
extern void F_LightCnt(void);

#endif

