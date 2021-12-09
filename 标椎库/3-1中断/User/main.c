#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Exit.h"

int main(void)
{
	/* NVIC中断分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	/* LED初始化 */
	LED_Init();
	/* 按键初始化 */
	Key_Init();
	/* 外部中断初始化 */
	Exti_Init();
	while (1)
	{
		
	}
}
