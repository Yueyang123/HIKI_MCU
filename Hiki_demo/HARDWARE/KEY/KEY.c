#include "KEY.h"
#include "delay.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	//PB12
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	//PB13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	//PB14
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	//PB15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

}

u8 KEY_Scan(u8 mode)
{ 
	static u8 key_up=1;
	if(mode)key_up=1;
	if(key_up&&(FUNC==0||FUNC1==0||FUNC2==1|EMER==1))
	{
	delay_ms(10);
	key_up=0;
	if(FUNC==0)return FUNC_PRESS;
	else if(FUNC1==0)return FUNC1_PRESS;
	else if(FUNC2==0)return FUNC2_PRESS;
	else if(EMER==0)return EMER_PRESS;		
	}else if(FUNC==1&&FUNC1==1&&FUNC2==1&&EMER==1)key_up=1;
	return 0;
}