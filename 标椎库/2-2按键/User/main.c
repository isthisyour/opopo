#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Delay.h"
#include "Key.h"

unsigned char Key=0;

int main(void)
{
	LED0_Init();//LED0初始化
	LED1_Init();//LED1初始化
	while(1)
	{

		Key=key_assignments(Key);
		switch(Key)
		{
			case 0:LED1_off;LED0_off;Delay(500);LED0_NO;Delay(500);break;
			case 1:LED1_off;LED0_NO;Delay(500);LED0_off;LED1_NO;Delay(500);break;
			
		}
	}
}

