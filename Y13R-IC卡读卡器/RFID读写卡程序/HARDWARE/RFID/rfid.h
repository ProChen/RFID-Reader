#ifndef __RFID_H
#define __RFID_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

void LoadPassword(void);		//װ����Կ
void WriteBlock(void);			//IC����������ʼ��
void ReadBlock(void);	//����д��ָ��֡
void ReadCardNumber(void);	//STM32ͨ��USART3��RFID���Ͷ�����ָ��

#endif
