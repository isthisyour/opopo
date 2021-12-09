#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"

int main(void)
{
	LED_Init();
	while (1)
	{
		LED_Turn();
		Delay_ms(200);
	}
}
