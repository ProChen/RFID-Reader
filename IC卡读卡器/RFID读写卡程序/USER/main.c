#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

u8 t=0;		//���������飬С��5
u8 ReadCardNumber[5]={0x7F,0x03,0x00,0x10,0x13};//������֡

//STM32ͨ��USART3��RFID���Ͷ�����ָ��
void ReadCard (void)
{
	for(t=0;t<5;t++)
	{
		USART_SendData(USART3,ReadCardNumber[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//�ȴ����ͽ���
	}
}



int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);		//��ʱ��ʼ�� 
	uart_init(9600);		//����1��ʼ��������Ϊ9600
	uart3_init(9600);		//����3��ʼ��������Ϊ9600
	
	ReadCard();			//���Ͷ�����ָ��֡
	printf("��ˢ��!");

	//�ȴ������ж�
	while(1)
	{

	}
		
}

