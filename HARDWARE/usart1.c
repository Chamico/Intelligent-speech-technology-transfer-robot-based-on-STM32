#include "include.h"

extern uint CLIP_OPEN_CLOSE ;
extern uint CLIP_UP_DOWN ;
extern uint ARM_UP_DOWN ;
extern uint ARM_LEFT_RIGHT ;

void init_usart1(uint baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); 
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(GPIOA,&GPIO_InitStructure); 

	USART_InitStructure.USART_BaudRate = baud;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure); 
	
	USART_Cmd(USART1, ENABLE);
	
	USART_ClearFlag(USART1, USART_FLAG_TC);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


// 串口中断服务执行函数
void USART1_IRQHandler(void)               
{
	u8 Res;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res =USART_ReceiveData(USART1);//(USART1->DR);	//读取接收到的数据
		
		switch(Res)
		{
			case 'a':		//robot go
			led_conversion();
			robot_go(300,300);
			break;
			
			case 'b':  	//robot back
			led_conversion();
			robot_back(300,300);
			break;
		
			case 'c':  	//robot left
			led_conversion();
			robot_left(300,300);
			break;
			
			case 'd':  	//robot right
			led_conversion();
		  robot_right(300,300);
			break;
			
			case 'e':  	//open the clip
			led_conversion();
			CLIP_OPEN_CLOSE --;
			
			if(CLIP_OPEN_CLOSE <= 7)
			{
				CLIP_OPEN_CLOSE = 7;
			}
			
			break;
			
			case 'f':  	//close the clip
			led_conversion();
			
			CLIP_OPEN_CLOSE ++;
			if(CLIP_OPEN_CLOSE >= 15)
			{
				CLIP_OPEN_CLOSE = 15;
			}
			break;
			
			case 'g':  	//lift the clip
			led_conversion();
			
			CLIP_UP_DOWN--;
			if(CLIP_UP_DOWN <= 4)
			{
				CLIP_UP_DOWN = 4;
			}
			break;
			
			case 'h':  	//put down the clip
			led_conversion();
			CLIP_UP_DOWN++;
			if(CLIP_UP_DOWN >= 22)
			{
				CLIP_UP_DOWN = 22;
			}
			break;
			
			case 'i':  	//lift arm
			led_conversion();
			ARM_UP_DOWN++ ;
			if(ARM_UP_DOWN >= 21)
			{
				ARM_UP_DOWN = 21;
			}
			break;
			
			case 'j':  	//put down arm
			led_conversion();
			ARM_UP_DOWN--;
			if(ARM_UP_DOWN <= 3)
			{
				ARM_UP_DOWN = 3;
			}
			break;
			
			case 'k':  	//arm left
			led_conversion();
			ARM_LEFT_RIGHT++;
			if(ARM_LEFT_RIGHT >= 25)
			{
				ARM_LEFT_RIGHT = 25;
			}
			break;
			
			case 'l':  	//arm right
 			led_conversion();
			ARM_LEFT_RIGHT--;
			if(ARM_LEFT_RIGHT <= 5)
			{
				ARM_LEFT_RIGHT = 5;
			}
			break;
		}
	}
}

