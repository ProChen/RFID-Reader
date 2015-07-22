#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "rfid.h"



int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);		//延时初始化 
	uart_init(9600);		//串口1初始化波特率为9600
	uart3_init(9600);		//串口3初始化波特率为9600
	LED_Init();				  //初始化LED端口  
	EXTIX_Init();       //初始化外部中断输入 

	
	printf("keyup:写块数据中断！\r\n");
	printf("key0:读块数据中断！\r\n");
	printf("key1:读卡号中断！\r\n");
	
	LoadPassword();			//装载密码


	//等待中断发生
	while(1)
	{

	}
		
}

