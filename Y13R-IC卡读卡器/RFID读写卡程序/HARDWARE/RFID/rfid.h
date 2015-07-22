#ifndef __RFID_H
#define __RFID_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

void LoadPassword(void);		//装载秘钥
void WriteBlock(void);			//IC卡读卡器初始化
void ReadBlock(void);	//发送写卡指令帧
void ReadCardNumber(void);	//STM32通过USART3向RFID发送读卡号指令

#endif
