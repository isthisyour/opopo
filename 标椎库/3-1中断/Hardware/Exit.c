/**
  ******************************************************************************
  * @author  
  * @brief   
  * @version 
  * @date    
  ******************************************************************************
  * @attention
  *
  */
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header
#include "Exit.h"
#include "LED.h"
#include "Key.h"
#include "Delay.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/


/**
  * @brief  初始化中断
  * @param  无
  * @retval 无
  */
void Exti_Init(void)
{
	/* 使能复位时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	/* 绑定中断线 */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	/* 中断配置 */
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;               //中断线4
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;      //中断请求
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  //下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                //使能中断
	EXTI_Init(&EXTI_InitStructure);
	
	/* NVIC配置 */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;         //配置中断线4
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;       //子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;          //使能
	NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  中断服务函数
  * @param  无
  * @retval 无
  */
void EXTI4_IRQHandler(void)
{
	Delay_ms(20);
	if(EXTI_GetITStatus(EXTI_Line4)!=RESET)
	{
		/* 检查松手 */
		while(Key_GetNum() == 1);
		LED_Turn();
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}


