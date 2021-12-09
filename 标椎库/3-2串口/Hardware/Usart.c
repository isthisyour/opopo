/**
  ******************************************************************************
  * @author  小赵同学
  * @brief   USART1驱动
  * @version v0.1
  * @date    2021.12.4
  ******************************************************************************
  * @attention
  * 使用STM32F103ZE开发
  * 使用USART1
  */
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header
#include "Usart.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 USART1_RX_BUF[200];
unsigned char USART1_RX_STA = 0;
unsigned char USART1_RX_CNT = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/

/**
  * @brief  串口1初始化
  * @param  Baud 串口1波特率设置
  * @retval 无
  */
void Usart_Init(unsigned int Baud)
{
	/* 使能USART1时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	/* 使能USART1端口时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	/* 配置RX */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	/* 配置TX */
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	/* 串口参数初始化 */
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate  = Baud;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
	USART_Init(USART1,&USART_InitStructure);
	
	/* NVIC初始化 */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	/* 开启串口中断 */
	USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);
	
	/* 开启串口 */
	USART_Cmd(USART1,ENABLE);
}

/**
  * @brief  通过串口1发送一个数据包
  * @param  buf 发送的数组
  * @param  len 发送数据的长度
  * @retval 无
  */
void USART1_Send_Data(unsigned char *buf,unsigned short len)
{
	unsigned short 	t;
	for(t=0;t<len;t++)
	{
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
		USART_SendData(USART1,buf[t]);
	}
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
}

/**
  * @brief  串口1中断函数
  * @param  无
  * @retval 无
  */
void USART1_IRQHandler(void)
{
	unsigned char les=0;
	if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET)
	{
		les = USART_ReceiveData(USART1);
		if(USART1_RX_STA == 0)
		{
			USART1_RX_BUF[USART1_RX_CNT] = les;
			/* 收到回车后，标志收到完整数据 */
			if(USART1_RX_BUF[USART1_RX_CNT] == 0x0A)
			{
				USART1_RX_STA = 1;
			}
			USART1_RX_CNT++;
		}
	}
	
	USART_ClearFlag(USART1,USART_IT_RXNE);
}

