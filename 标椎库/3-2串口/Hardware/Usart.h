/**
  ******************************************************************************
  * @author  小赵同学
  * @brief   USART1驱动头文件
  * @version v0.1
  * @date    2021.12.4
  ******************************************************************************
  * @attention
  * 使用STM32F103ZE开发
  * 使用USART1
  */

#ifndef __USART_H
#define __USART_H

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
#define USART_REC_LEN 200
/* Exported macro ------------------------------------------------------------*/
/* 接收缓存区 */
extern unsigned char USART1_RX_BUF[USART_REC_LEN];
extern unsigned char USART1_RX_STA;
extern unsigned char USART1_RX_CNT;
/* Exported functions ------------------------------------------------------- */

void Usart_Init(unsigned int Baud);
void USART1_Send_Data(unsigned char *buf,unsigned short len);

#endif

