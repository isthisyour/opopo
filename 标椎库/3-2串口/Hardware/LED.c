/**
  ******************************************************************************
  * @author  小赵同学
  * @brief   LED驱动
  * @version V0.1
  * @date    2021/22/24
  ******************************************************************************
  * @attention
  * 使用STM32F103ZE开发
  * 默认使用PC13端口
  */
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header
#include "LED.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* LED使能端口 */
#define LED_RCC_APB2Periph_GPIO \
		RCC_APB2Periph_GPIOB

/* LED端口 */
#define LED_GPIO \
		GPIOB

/* LEDPin端口 */
#define LED_GPIO_Pin \
		GPIO_Pin_5
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/**
  * @brief  LED初始化
  * @param  无
  * @retval 无
  */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(LED_RCC_APB2Periph_GPIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =  LED_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(LED_GPIO,LED_GPIO_Pin);
}

/**
  * @brief  手动翻转LED状态
  * @param  NewState 有以下的值：OFF,NO
  * @retval 无
  */
void LED_Turn_(const LED_state NewState)
{
	if(NewState==NO)
	{
		GPIO_ResetBits(LED_GPIO, LED_GPIO_Pin);
	}
	else 
	{
		GPIO_SetBits(LED_GPIO, LED_GPIO_Pin);
	}
}

/**
  * @brief  翻转LED
  * @param  无
  * @retval 无
  */
void LED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(LED_GPIO, LED_GPIO_Pin) == 0)
	{
		GPIO_SetBits(LED_GPIO, LED_GPIO_Pin);
	}
	else
	{
		GPIO_ResetBits(LED_GPIO, LED_GPIO_Pin);
	}
}

