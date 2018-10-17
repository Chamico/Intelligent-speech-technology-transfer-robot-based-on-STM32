/*************************************************
Explain: The header flies contains all the contrnol
         methods of the motor on the intrlligent 
				 robot. The actual implementation is in
				 the motor.c file.
				 
Developmet board resoueces: 
    TIM2
    PA1,PA2,PA3,PA3
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/
//uint a = 0;
#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "include.h"

void init_motor(uint psc);	// psc : baud

void robot_stop(void);
void robot_go(uint left_pwm, uint right_pwm);         //robot operation contronl  
void robot_back(uint left_pwm, uint right_pwm);       
void robot_left(uint left_pwm, uint right_pwm); 
void robot_right(uint left_pwm, uint right_pwm); 

#endif

