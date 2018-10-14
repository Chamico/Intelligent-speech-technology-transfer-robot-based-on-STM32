/*************************************************
Explain: The header flies contains all the contrnol
         methods of the motor on the intrlligent 
				 robot. The actual implementation is in
				 the motor.c file.
				 
Hardware Required: None
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/
//uint a = 0;
#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "include.h"


void init_motor(uint psc);

void robot_go(uint left_pwm, uint right_pwm);

#endif

