#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "KEY.h"
#include "LCD.h"
#include "W25X16.h"

const u8 TEXT_Buffer[]={"WarShipSTM32 SPI TEST"};

 int main(void)
 {	
	int t;
	u8 key;
	u8 datatemp[sizeof(TEXT_Buffer)];
	int FLASH_SIZE=2*1024*1024;
	delay_init();	    	 //延时函数初始化	  
	uart_init(115200); 
	LED_Init();		  		//初始化与LED连接的硬件接口
	KEY_Init();
	LCD_Init();
	SPI_Flash_Init();
	 
	while(1)
	{
		
		key=KEY_Scan(0);
		if(key==WKUP_PRES)
		{
			LCD_Clear(BLUE);
			LCD_ShowString(0,0,16,(u8*)"WRITE",1);
			SPI_Flash_Write((u8*)TEXT_Buffer,FLASH_SIZE-100, sizeof(TEXT_Buffer) );
		}
		if(key==KEY0_PRES)
		{
			LCD_Clear(BLUE);
			LCD_ShowString(0,0,16,(u8*)"READ",1);
			delay_ms(3000);
			SPI_Flash_Read(datatemp,FLASH_SIZE-100,sizeof(TEXT_Buffer));
				LCD_Clear(BLUE);
			LCD_ShowString(0,0,16,(u8*)datatemp,1);
			delay_ms(3000);
		}

	}

}
