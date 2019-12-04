/*
 * timer.h
 *
 *  Created on: Dec 3, 2019
 *      Author: User
 */

#ifndef TIMER_H_
#define TIMER_H_

typedef	struct	TIMx TIMx;
struct TIMx{
	volatile	uint32_t	CR1;			//0x00
	volatile	uint32_t	CR2;		//0x04
	volatile	uint32_t	SMCR;		//0x08
	volatile	uint32_t	DIER;		//0x0C
	volatile	uint32_t	SR;			//0x10
	volatile	uint32_t	EGR;		//0x14
	volatile	uint32_t	CCMR1;		//0x18
	volatile	uint32_t	CCMR2;		//0x1C
	volatile	uint32_t	CCER;		//0x20
	volatile	uint32_t	CNT;		//0x24
	volatile	uint32_t	PSC;		//0x28
	volatile	uint32_t	ARR;		//0x2C
	volatile	uint32_t	RCR;		//0x30
	volatile	uint32_t	CCR1;		//0x34
	volatile	uint32_t	CCR2;		//0x38
	volatile	uint32_t	CCR3;		//0x3C
	volatile	uint32_t	CCR4;		//0x40
	volatile	uint32_t	BDTR;		//0x44
	volatile	uint32_t	DCR;		//0x48
	volatile	uint32_t	DMAR;		//0x4C
};

#define TIM1	((SPIx *)(0x40010000))
#define TIM8	((SPIx *)(0x40010400))

#endif /* TIMER_H_ */
