#include "sys.h"
#include "usart.h"	
#include "led.h"
#include "delay.h"

//说明：装载秘钥
//参数：
//返回值：
void LoadPassword(void)
{
	u8 t=0;
	for(t=0;t<23;t++)					//写入块的数据，16字节
	{
		u8 loadPasswordCmd[23]={0x7F,0x15,0x00,0x2B,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0x00,0x03,0x08,0x05,0x02,0x07,0x35};
		USART_SendData(USART3,loadPasswordCmd[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//等待发送结束
	}
	printf("装载密码成功!\r\n");
	
}

//说明：写块指令,第5个字节0x01表示数据写入的块，取值为0-63.第6-21字节为写入的数据，一共16字节。最后一个字节为校验码，是除0x7F外所有数据的异或值
//参数：
//返回值：
void WriteBlock(void)			
{
	u8 t=0;			
	for(t=0;t<22;t++)
	{
		u8 WriteBlockCmd[22]={0x7F,0x14,0x00,0x12,0x01,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,0x07};
		USART_SendData(USART3,WriteBlockCmd[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//等待发送结束
	}
	printf("写块指令成功！\r\n");
}

//说明：读块指令
//参数：
//返回值：
void ReadBlock(void)
{
	u8 t=0;		//命令字数组，小于5
	u8 ReadBlockCmd[15]={0x7F,0x0D,0x00,0x2E,0x02,0x0C,0x01,0x00,0x00,0x00,0x01,0x23,0x12,0x54,0x48};//读卡号帧
	for(t=0;t<15;t++)
	{
		USART_SendData(USART3,ReadBlockCmd[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//等待发送结束
	}
	printf("读块指令成功！\r\n");
}


//说明：读卡号指令
//参数：
//返回值：
void ReadCardNumber(void)
{
	u8 t=0;		//命令字数组，小于5
	u8 ReadCardNumber[15]={0x7F,0x0D,0x00,0x2E,0x00,0x0A,0x01,0x00,0x00,0x00,0x01,0x23,0x12,0x54,0x4C};//读卡号帧
	for(t=0;t<15;t++)
	{
		USART_SendData(USART3,ReadCardNumber[t]);            
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//等待发送结束
	}
		printf("读卡号成功！\r\n");
}
