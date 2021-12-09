#ifndef __KEY_H__
#define __KEY_H__

unsigned char key_assignments(unsigned char x);

#define Key0 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define Key1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)

#endif
