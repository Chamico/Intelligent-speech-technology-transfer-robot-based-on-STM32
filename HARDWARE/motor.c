#include "include.h"

void init_motor(uint arr)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  	//TIM4时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//使能PORTB时钟	
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM2);     //GPIOB复用为定时器14
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM2);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3;           //GPIOB
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PB
	  
	TIM_TimeBaseStructure.TIM_Prescaler=0;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);//初始化定时器4
	
	//初始化TIM14 Channel1 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1

	TIM_CtrlPWMOutputs(TIM2,ENABLE);   //打开PWM
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
 
  TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIM2, ENABLE);  //使能TIM14
}

//机器人停止函数
void robot_stop()
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare3(TIM2,0);
	TIM_SetCompare4(TIM2,0);
	delay_MS(50);
}

// 机器人前进函数
void robot_go(uint left, uint right)
{
	TIM_SetCompare1(TIM2,right);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare3(TIM2,left);
	TIM_SetCompare4(TIM2,0);
	delay_MS(400);
	robot_stop();
}

// 机器人后退函数
void robot_back(uint left, uint right)
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,right);
	TIM_SetCompare3(TIM2,0);
	TIM_SetCompare4(TIM2,left);
	delay_MS(400);
	robot_stop();
}

//机器人左转函数
void robot_left(uint left, uint right)
{
	TIM_SetCompare1(TIM2,right);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare3(TIM2,0);
	TIM_SetCompare4(TIM2,left);
	delay_MS(200);
	robot_stop();
}


// 机器人右转
void robot_right(uint left, uint right)
{
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,right);
	TIM_SetCompare3(TIM2,left);
	TIM_SetCompare4(TIM2,0);
	delay_MS(200);
	robot_stop();
}


// 自定义延时函数
void delay_MS(uint time)
{
	uint i = 0,j = 0, k = 0;
	for(i = 0;i < 5999; i++)
	{
		for(k = 0;k <9; k++)
		{
			for(j = 0;j < time ;j++)
			{
				
			}
		}
		
	}
}


