/*************************************************
Explain: The header flies contains all the contrnol
         methods of the infared on the intrlligent 
				 robot. The actual implementation is in
				 the infared.c file.
				 
Developmet board resoueces: 
    PC0, PC1
				 
Author: Chamico
Date: 2018/10/13
Modify: None
*************************************************/



#ifndef _INFARED_H_
#define _INFARED_H_


#define INFARED_LEFT PCin(1)		// 0 tested
#define INFARED_RIGHT PCin(0)

void init_infared(void);
int infared_check(void);

#endif

