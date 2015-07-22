#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "rfid.h"



int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);		//��ʱ��ʼ�� 
	uart_init(9600);		//����1��ʼ��������Ϊ9600
	uart3_init(9600);		//����3��ʼ��������Ϊ9600
	LED_Init();				  //��ʼ��LED�˿�  
	EXTIX_Init();       //��ʼ���ⲿ�ж����� 

	
	printf("keyup:д�������жϣ�\r\n");
	printf("key0:���������жϣ�\r\n");
	printf("key1:�������жϣ�\r\n");
	
	LoadPassword();			//װ������


	//�ȴ��жϷ���
	while(1)
	{

	}
		
}

