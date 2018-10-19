#include "include.h"     //import the needed file of the peoject


/*************************************************
Explain: The orign of the entire project.
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/

extern uint CLIP_OPEN_CLOSE ;
extern uint CLIP_UP_DOWN ;
extern uint ARM_UP_DOWN ;
extern uint ARM_LEFT_RIGHT ;

int main(void)
{
	uchar flag = 0;
	init_led();
	init_motor(500);
	init_usart1(9600);
	init_servo();
	init_infared();
	while(1)
	{
		set_servo(CLIP_OPEN_CLOSE, CLIP_UP_DOWN,
		         ARM_UP_DOWN, ARM_LEFT_RIGHT);
		
		if(flag == 0)
		{
			flag = infared_check();
		}
	}
}
 

