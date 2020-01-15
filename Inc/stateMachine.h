/*
 * stateMachine.h
 *
 *  Created on: Nov 19, 2019
 *      Author: User
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "gpio.h"
#include "spi.h"



typedef enum{
	READ_BUTTON_COMMAND=0x23,
	WAIT_BUTTON_STATE=0x24,
	SENDBACK_BUTTON_STATE=0x25,
	CONTROL_LED_COMMMAND=0x45,
	LED_CONFIG_STATE=0x46,
	DO_NOTHING=0xff
}State;


typedef struct{
	State state;
	int delay;
	bool buttonState;
	uint8_t slaveMsg;
}SMInfo;

typedef enum{
	BUTTON_COMMAND,
	GET_BUTTON_STATE,
	LED_COMMAND,
	SET_LED
}MasterState;

typedef struct{
	MasterState state;
	uint8_t buttonState;
}MasterInfo;
void stateMachineSlave(SMInfo *smInfo);

#endif /* STATEMACHINE_H_ */
