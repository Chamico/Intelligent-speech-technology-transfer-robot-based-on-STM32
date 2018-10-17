#ifndef _LED_H_
#define _LED_H_

#include "include.h"

#define LED0 PAout(6)
#define LED1 PAout(7)

void init_led(void);

void led_conversion(void);

#endif
