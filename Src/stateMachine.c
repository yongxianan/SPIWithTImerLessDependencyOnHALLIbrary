/*
 * stateMachine.c
 *
 *  Created on: Nov 19, 2019
 *      Author: User
 */

#include "stateMachine.h"


//this state machine put in the interrupt
void stateMachineSlave(SMInfo *smInfo){
	switch(smInfo->state){
	//initialize smInfo->state = READ_BUTTON_COMMAND.
	//initialize smInfo->numberOfSendBack for rubbish feedback.
	//for read button state.
		case READ_BUTTON_COMMAND:
			if(smInfo->delay==0){
				smInfo->state=SENDBACK_BUTTON_STATE;
			}
			else{
				smInfo->state=WAIT_BUTTON_STATE;
			}

			smInfo->buttonState = readGPIO(GPIOA,0);
			break;

		//feedback rubbish, don't write on DR
		case WAIT_BUTTON_STATE:
			if(smInfo->delay==0){
				smInfo->state=SENDBACK_BUTTON_STATE;
			}
			break;

		case SENDBACK_BUTTON_STATE:
			sendData(SPI4,(uint8_t)((smInfo->buttonState)<<5));
			smInfo->state=DO_NOTHING;
			break;



	//initialize smInfo->state=CONTROL_LED_COMMMAND for LED control
		case CONTROL_LED_COMMMAND:
			smInfo->state=LED_CONFIG_STATE;
			break;
		case LED_CONFIG_STATE:
			setResetGPIO(GPIOG,13,(bool)(smInfo->slaveMsg & 0b00100000));
			smInfo->state=DO_NOTHING;
			break;

		//DO_NOTHING will do nothing in state machine
		default:
			smInfo->state=DO_NOTHING;
			break;
	}

	if(smInfo->delay>0){
		(smInfo->delay)--;
	}
}

//this state machine put in the interrupt
void stateMachineSlaveV2(SMInfo *smInfo){
	switch(smInfo->state){
	//initialize smInfo->state = READ_BUTTON_COMMAND.
	//initialize smInfo->numberOfSendBack for rubbish feedback.
	//for read button state.
		case READ_BUTTON_COMMAND:
			smInfo->state=DO_NOTHING;
			smInfo->buttonState = readGPIO(GPIOA,0);
			if(smInfo->buttonState==true){
				sendData(SPI4,0b00100000);
			}else{
				sendData(SPI4,0b00000000);
			}
			//sendData(SPI4,(uint8_t)((smInfo->buttonState)<<5));
			break;



	//initialize smInfo->state=CONTROL_LED_COMMMAND for LED control
		case CONTROL_LED_COMMMAND:
			smInfo->state=LED_CONFIG_STATE;
			break;
		case LED_CONFIG_STATE:
			setResetGPIO(GPIOG,13,(bool)(smInfo->slaveMsg & 0b00000001));
			smInfo->state=DO_NOTHING;
			break;

		//DO_NOTHING will do nothing in state machine
		default:
			smInfo->state=DO_NOTHING;
			break;
	}

	if(smInfo->delay>0){
		(smInfo->delay)--;
	}
}
