#ifndef __KEY_H
#define __KEY_H
#include "sys.h"
#define FUNC  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)
#define FUNC1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)
#define FUNC2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)
#define EMER  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)


#define FUNC_PRESS	0
#define FUNC1_PRESS	1
#define FUNC2_PRESS	2

#define EMER_PRESS	3
void KEY_Init(void);
u8 KEY_Scan(u8 mode);

#endif