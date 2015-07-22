#include "sys.h"
#include "usart.h"	
#include "led.h"
#include "delay.h"

//˵����װ����Կ
//������
//����ֵ��
void LoadPassword(void)
{
	u8 t=0;
	for(t=0;t<23;t++)					//д�������ݣ�16�ֽ�
	{
		u8 loadPasswordCmd[23]={0x7F,0x15,0x00,0x2B,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0x00,0x03,0x08,0x05,0x02,0x07,0x35};
		USART_SendData(USART3,loadPasswordCmd[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//�ȴ����ͽ���
	}
	printf("װ������ɹ�!\r\n");
	
}

//˵����д��ָ��,��5���ֽ�0x01��ʾ����д��Ŀ飬ȡֵΪ0-63.��6-21�ֽ�Ϊд������ݣ�һ��16�ֽڡ����һ���ֽ�ΪУ���룬�ǳ�0x7F���������ݵ����ֵ
//������
//����ֵ��
void WriteBlock(void)			
{
	u8 t=0;			
	for(t=0;t<22;t++)
	{
		u8 WriteBlockCmd[22]={0x7F,0x14,0x00,0x12,0x01,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,0x07};
		USART_SendData(USART3,WriteBlockCmd[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//�ȴ����ͽ���
	}
	printf("д��ָ��ɹ���\r\n");
}

//˵��������ָ��
//������
//����ֵ��
void ReadBlock(void)
{
	u8 t=0;		//���������飬С��5
	u8 ReadBlockCmd[15]={0x7F,0x0D,0x00,0x2E,0x02,0x0C,0x01,0x00,0x00,0x00,0x01,0x23,0x12,0x54,0x48};//������֡
	for(t=0;t<15;t++)
	{
		USART_SendData(USART3,ReadBlockCmd[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//�ȴ����ͽ���
	}
	printf("����ָ��ɹ���\r\n");
}


//˵����������ָ��
//������
//����ֵ��
void ReadCardNumber(void)
{
	u8 t=0;		//���������飬С��5
	u8 ReadCardNumber[15]={0x7F,0x0D,0x00,0x2E,0x00,0x0A,0x01,0x00,0x00,0x00,0x01,0x23,0x12,0x54,0x4C};//������֡
	for(t=0;t<15;t++)
	{
		USART_SendData(USART3,ReadCardNumber[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//�ȴ����ͽ���
	}
		printf("�����ųɹ���\r\n");
}
