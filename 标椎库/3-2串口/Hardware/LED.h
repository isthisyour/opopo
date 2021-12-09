#ifndef __LED_H
#define __LED_H

/* Exported types ------------------------------------------------------------*/
typedef enum {OFF=0,NO=1}LED_state;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void LED_Init(void);
void LED_Turn_(LED_state NewState);
void LED_Turn(void);

#endif



