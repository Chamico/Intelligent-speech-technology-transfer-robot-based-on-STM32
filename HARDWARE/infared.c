#include "include.h"

void init_infared(void)   //�����ʼ��
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOFʱ��

  //GPIOF9,F10��ʼ������
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0 | GPIO_Pin_1;//
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//����
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO
}

// ����ɨ�躯��������⵽���壬�Զ�����
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
