#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	/* NVIC中断分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	while (1)
	{
		
	}
}
