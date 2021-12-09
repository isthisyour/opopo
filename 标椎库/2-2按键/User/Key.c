#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef Key_gpio;
	Key_gpio.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_3;
	Key_gpio.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&Key_gpio);
}

unsigned char key_assignments(unsigned char x)
{
	Key_Init();
	if(Key0==0|Key1==0)
	{
		Delay_ms(20);
		
		if(Key0==0)
		{
			while(Key0==0);
			Delay_ms(20);
			return 0;
		}
		if(Key1==0)
		{
			while(Key1==0);
			Delay_ms(20);
			return 1;
		}
	}
	else
	{
		return x;
	}
}
