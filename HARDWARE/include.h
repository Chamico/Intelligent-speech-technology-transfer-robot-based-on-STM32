/*************************************************
Explain: The header flies contains all the header
         files needed for the entire project.
				 
Hardware Required: None
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/

typedef unsigned int uint;        //define simplified data types 
typedef unsigned char uchar;

#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f4xx.h"    //Import System Header files 
#include "usart.h"
#include "delay.h"

#include "motor.h"       //import roabot hardware header files
#include "servo.h"
#include "usart2.h"

#endif

