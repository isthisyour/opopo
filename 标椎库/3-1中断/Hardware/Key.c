/**
  ******************************************************************************
  * @author  小赵同学
  * @brief   按键驱动
  * @version 
  * @date    
  ******************************************************************************
  * @attention
  *
  */
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define Key_RCC_APB2Periph_GPIO \
		RCC_APB2Periph_GPIOE

#define Key_GPIO \
		GPIOE

#define Key_GPIO_Pin \
		GPIO_Pin_4
/* Private macro -------------------------------------------------------------*/
#define Key_State GPIO_ReadInputDataBit(Key_GPIO,Key_GPIO_Pin)
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/

/**
  * @brief  按键初始化
  * @param  无
  * @retval 无
  */
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(Key_RCC_APB2Periph_GPIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin =  Key_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Key_GPIO, &GPIO_InitStructure);
}

/**
  * @brief  获取按键状态
  * @param  无
  * @retval 按键键值
  */
unsigned char Key_GetNum(void)
{
	int state=0;
	if(Key_State==0)
	{
		Delay_ms(20);
		if(Key_State==0)
		{
			while(Key_State==0);
			Delay_ms(20);
			state=1;
//			LED_Turn();
		}
	}
	return state;
}



