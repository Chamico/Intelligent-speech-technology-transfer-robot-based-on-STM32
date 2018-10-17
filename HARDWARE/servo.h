/*************************************************
Explain: The header flies contains all the contrnol
         methods of the mechanical arm of the int-
				 elligent robot.The actual implementation 
				 is in the servo.c file.
				 
Developmet board resoueces: 
    TIM3
		PC6,PC7,PC8,PC9
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/

#ifndef _SERVO_H_
#define _SERVO_H_

#include "include.h"


void init_servo(void);
void set_servo(uint servo1, uint servo2, uint servo3, uint servo4);
void test(void);




#endif
