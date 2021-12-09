#ifndef __LED_H__
#define __LED_H__

void LED0_Init(void);
void LED1_Init(void);


#define LED0_NO  GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define	LED0_off GPIO_SetBits(GPIOB,GPIO_Pin_5)

#define LED1_NO  GPIO_ResetBits(GPIOE,GPIO_Pin_5)
#define	LED1_off GPIO_SetBits(GPIOE,GPIO_Pin_5)

#endif

//开发板LED 引脚:LED0-PB5  LED1-PE5
