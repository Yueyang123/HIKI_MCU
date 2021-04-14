#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "KEY.h"
#include "adc.h"
 int main(void)
 {	
	delay_init();	    	 //��ʱ������ʼ��	  
	uart1_init(115200); 
  uart2_init(115200); 
	uart3_init(115200); 
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
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
