#include "include.h"

void init_motor(uint psc)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE); 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1 | GPIO_PinSource2 | GPIO_PinSource3 |GPIO_PinSource4,GPIO_AF_TIM2);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(GPIOA,&GPIO_InitStructure); 
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc - 1; 
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period=0; 
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC1Init(TIM2, &TIM_OCInitStructure); 
	
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable); 
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable); 
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable); 
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable); 
	
	TIM_ARRPreloadConfig(TIM2,ENABLE);
	TIM_Cmd(TIM2, ENABLE);
}

void robot_go(uint left, uint right)
{
	TIM_SetCompare1(TIM2,left);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare3(TIM2,left);
	TIM_SetCompare4(TIM2,0);
}
