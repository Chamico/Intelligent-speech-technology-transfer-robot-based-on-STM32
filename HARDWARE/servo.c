#include "include.h"

uint CLIP_OPEN_CLOSE = 11;
uint CLIP_UP_DOWN = 17;
uint ARM_UP_DOWN = 15;
uint ARM_LEFT_RIGHT = 15;


void init_servo(void)
{
	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM4时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 	//使能PORTB时钟	
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource12,GPIO_AF_TIM4);     //GPIOB复用为定时器14
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource14,GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource15,GPIO_AF_TIM4);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;           //GPIOB
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOD,&GPIO_InitStructure);              //初始化PB
	  
	TIM_TimeBaseStructure.TIM_Prescaler=8399;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=199;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);//初始化定时器4
	
	//初始化TIM14 Channel1 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1

	TIM_CtrlPWMOutputs(TIM4,ENABLE);   //打开PWMw1	
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
 
  TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIM4, ENABLE);  //使能TIM14
}

//设置机械臂舵机角度
void set_servo(uint servo1, uint servo2, 
	   uint servo3, uint servo4)
{
	TIM_SetCompare1(TIM4,servo1);
	TIM_SetCompare2(TIM4,servo2);
	TIM_SetCompare3(TIM4,servo3);
	TIM_SetCompare4(TIM4,servo4);
}

// 拾取物体的机械臂动作帧
void arm_pickup(void)
{
	delay_MS(100);
	set_servo(9, 6, 3, 15);
	delay_MS(500);
	set_servo(14, 6, 3, 15);
	delay_MS(500);
	set_servo(14, 6, 7, 15);
	delay_MS(500);
	set_servo(14, 9, 11, 15);
	delay_MS(500);
	CLIP_OPEN_CLOSE = 14;
  CLIP_UP_DOWN =9;
	ARM_UP_DOWN = 11;
	ARM_LEFT_RIGHT = 15;

}

