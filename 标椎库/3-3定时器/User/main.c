#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Time.h"
#include "LED.h"

int main(void)
{
	/* NVIC中断分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	LED_Init();
	Time_Init(7199,4999);
	while (1)
	{
		
	}
}
