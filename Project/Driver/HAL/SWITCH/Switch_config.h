/*
 * Switch_config.h
 *
 *  Created on: Feb 6, 2023
 *      Author: 00214
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SW_NUM     3

//port pin   float/pull_up

typedef struct{
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_Status;
}SW_t;





#endif /* SWITCH_CONFIG_H_ */
