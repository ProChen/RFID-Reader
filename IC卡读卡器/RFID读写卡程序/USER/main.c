#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

u8 t=0;		//命令字数组，小于5
u8 ReadCardNumber[5]={0x7F,0x03,0x00,0x10,0x13};//读卡号帧

//STM32通过USART3向RFID发送读卡号指令
void ReadCard (void)
{
	for(t=0;t<5;t++)
	{
		USART_SendData(USART3,ReadCardNumber[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//等待发送结束
	}
}



int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);		//延时初始化 
	uart_init(9600);		//串口1初始化波特率为9600
	uart3_init(9600);		//串口3初始化波特率为9600
	
	ReadCard();			//发送读卡号指令帧
	printf("请刷卡!");

	//等待接收中断
	while(1)
	{

	}
		
}

