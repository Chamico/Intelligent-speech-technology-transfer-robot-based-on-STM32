#include "include.h"     //import the needed file of the peoject


/*************************************************
Explain: The orign of the entire project.
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/

int main(void)
{
	init_led();
	init_motor(900);
	init_usart1(9600);
	while(1)
	{
		//LED0 = 1;
		//LED1 = 0;
	}

}
