#ifndef __LED_H
#define __LED_H

/* Exported types ------------------------------------------------------------*/
typedef enum {OFF=0,NO=1}LED_state;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* LED使能端口 */
#define LED_RCC_APB2Periph_GPIO \
		RCC_APB2Periph_GPIOB

/* LED端口 */
#define LED_GPIO \
		GPIOB

/* LEDPin端口 */
#define LED_GPIO_Pin \
		GPIO_Pin_5
/* Exported functions ------------------------------------------------------- */

void LED_Init(void);
void LED_Turn_(LED_state NewState);
void LED_Turn(void);

#endif



