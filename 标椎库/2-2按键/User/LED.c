#include "stm32f10x.h"                  // Device header
#include "LED.h"

void LED0_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef LED0;
	LED0.GPIO_Pin=GPIO_Pin_5;
	LED0.GPIO_Mode=GPIO_Mode_Out_PP;
	LED0.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&LED0);
	LED0_off;
}

void LED1_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitTypeDef LED1;
	LED1.GPIO_Mode=GPIO_Mode_Out_PP;
	LED1.GPIO_Pin=GPIO_Pin_5;
	LED1.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOE,&LED1);
	LED1_off;
}
