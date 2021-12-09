#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "PWM.h"

int main(void)
{
	/* NVIC中断分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	unsigned int ledpwm=0;
	unsigned char idr=1;
	
	PWM_Init(899,0);
	while (1)
	{
		Delay_ms(10);
		if(idr)
		{
			ledpwm++;
		}
		else
		{
			ledpwm--;
		}
		if(ledpwm > 300){idr=0;}
		if(ledpwm == 0){idr=1;}
		TIM_SetCompare2(TIM3,ledpwm);
	}
}
