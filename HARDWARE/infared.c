#include "include.h"

void init_infared(void)   //红外初始化
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIOF时钟

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0 | GPIO_Pin_1;//
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//浮空
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}

// 红外扫描函数，当检测到物体，自动夹起
int infared_check()
{
	if((INFARED_LEFT == 0) || (INFARED_RIGHT == 0))   // 0 tested
	{
		arm_pickup();
		return 1;
	}
	else
	{		return 0;
	}
}
