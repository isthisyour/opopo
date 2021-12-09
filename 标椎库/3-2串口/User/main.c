#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Usart.h"
#include "LED.h"

int main(void)
{
	/* NVIC中断分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	/* 初始化串口1，设置波特率为115200 */
	Usart_Init(115200);
	while (1)
	{
		/* 返回发送到单片机的数据 */
		if(USART1_RX_STA==1)
		{
			USART1_RX_STA=0;
			USART1_Send_Data(USART1_RX_BUF,USART1_RX_CNT);
			USART1_RX_CNT = 0;
		}
	}
}
