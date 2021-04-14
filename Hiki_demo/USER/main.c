#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "KEY.h"
#include "adc.h"
 int main(void)
 {	
	delay_init();	    	 //延时函数初始化	  
	uart1_init(115200); 
  uart2_init(115200); 
	uart3_init(115200); 
	LED_Init();		  		//初始化与LED连接的硬件接口
//	KEY_Init();

	while(1)
	{
		UART1_SendByte('1');
		UART2_SendByte('2');
		UART3_SendByte('3');
		printf("Hello\n");
		delay_ms(1000);
	}

}
