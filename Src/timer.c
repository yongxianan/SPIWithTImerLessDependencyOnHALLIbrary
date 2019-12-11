/*
 * timer.c
 *
 *  Created on: Dec 3, 2019
 *      Author: User
 */

#include "timer.h"

void configAdvancedTIM(TIMx *TIM, uint64_t CR){
	TIM->CR2 &= ~(0xFFFFFFFF & (CR>>32));
	TIM->CR2 |= (0xFFFFFFFF & (CR>>32));
	TIM->CR1 &= ~(0xFFFFFFFF & CR);
	TIM->CR1 |= (0xFFFFFFFF & CR);
}


void config_DMA_ISR(TIMx *TIM, uint32_t CR){
	TIM->DIER &= ~(0xFFFFFFFF & CR);
	TIM->DIER |= (0xFFFFFFFF & CR);
}

/*
prescalerFreq=intFreq/prescaler
1/period=prescalerFreq
1/period=intFreq/prescaler
prescaler=intFreq*period
*/
void configPSC(TIMx *TIM,uint32_t intFreq,double period){
	TIM->PSC = (uint32_t)(intFreq*period)-1;
}

void configARR(TIMx *TIM,uint32_t ARR){
	TIM->ARR = ARR;
}
