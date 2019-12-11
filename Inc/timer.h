/*
 * timer.h
 *
 *  Created on: Dec 3, 2019
 *      Author: User
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

typedef	struct	TIMx TIMx;
struct TIMx{
	volatile	uint32_t	CR1;		//0x00
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

#define TIM1	((TIMx *)(0x40010000))
#define TIM8	((TIMx *)(0x40010400))

//TIMx_CR1_
#define TIMx_CR1_CKD_INT			(0<<8)
#define TIMx_CR1_CKD_2*INT			(1<<8)
#define TIMx_CR1_CKD_4*INT			(2<<8)

#define TIMx_CR1_ARPE				(1<<7)

#define TIMx_CR1_CMS_EDGE_MODE		(0<<5)
#define TIMx_CR1_CMS_CENTER_MODE1	(1<<5)
#define TIMx_CR1_CMS_EDGE_MODE2		(2<<5)
#define TIMx_CR1_CMS_EDGE_MODE3		(3<<5)

#define TIMx_CR1_DIR_DOWNCOUNT		(1<<4)
#define TIMx_CR1_OPM				(1ULL<<3)
#define TIMx_CR1_URS				(1<<2)
#define TIMx_CR1_UDIS				(1<<1)
#define TIMx_CR1_COUNT_EN			(1ULL<<0)



//TIMx_CR2_
#define TIMx_CR2_OIS4				(1<<(32+14))
#define TIMx_CR2_OIS3N				(1<<(32+13))
#define TIMx_CR2_OIS3				(1<<(32+12))
#define TIMx_CR2_OIS2N				(1<<(32+11))
#define TIMx_CR2_OIS2				(1<<(32+10))
#define TIMx_CR2_OIS1N				(1<<(32+9))
#define TIMx_CR2_OIS1				(1<<(32+8))
#define TIMx_CR2_TI1S				(1<<(32+7))

#define TIMx_CR2_MMS_RESET			(0<<(32+4))
#define TIMx_CR2_MMS_ENABLE			(1<<(32+4))
#define TIMx_CR2_MMS_UPDATE			(2<<(32+4))
#define TIMx_CR2_MMS_COMPARE_PULSE	(3<<(32+4))
#define TIMx_CR2_MMS_OC1REF_TRGO	(4<<(32+4))
#define TIMx_CR2_MMS_OC2REF_TRGO	(5<<(32+4))
#define TIMx_CR2_MMS_OC3REF_TRGO	(6<<(32+4))
#define TIMx_CR2_MMS_OC4REF_TRGO	(7<<(32+4))

#define TIMx_CR2_CCDS				(1<<(32+3))
#define TIMx_CR2_CCUS				(1<<(32+2))
#define TIMx_CR2_CCPC				(1<<(32+0))

//TIMx_SMCR_
#define TIMx_SMCR_ETP				(1<<15)
#define TIMx_SMCR_ECE				(1<<14)

#define TIMx_SMCR_ETPS_OFF			(0<<12)
#define TIMx_SMCR_ETPS_DIV2			(1<<12)
#define TIMx_SMCR_ETPS_DIV4			(2<<12)
#define TIMx_SMCR_ETPS_DIV8			(3<<12)

#define TIMx_SMCR_ETF_NO_FILTER		(0<<8)
#define TIMx_SMCR_ETF_INT_N2		(1<<8)
#define TIMx_SMCR_ETF_INT_N4		(2<<8)
#define TIMx_SMCR_ETF_INT_N8		(3<<8)
#define TIMx_SMCR_ETF_DTS_DIV2_N6		(4<<8)
#define TIMx_SMCR_ETF_DTS_DIV2_N8		(5<<8)
#define TIMx_SMCR_ETF_DTS_DIV4_N6		(6<<8)
#define TIMx_SMCR_ETF_DTS_DIV4_N8		(7<<8)
#define TIMx_SMCR_ETF_DTS_DIV8_N6		(8<<8)
#define TIMx_SMCR_ETF_DTS_DIV8_N8		(9<<8)
#define TIMx_SMCR_ETF_DTS_DIV16_N5		(10<<8)
#define TIMx_SMCR_ETF_DTS_DIV16_N6		(11<<8)
#define TIMx_SMCR_ETF_DTS_DIV16_N8		(12<<8)
#define TIMx_SMCR_ETF_DTS_DIV32_N5		(13<<8)
#define TIMx_SMCR_ETF_DTS_DIV32_N6		(14<<8)
#define TIMx_SMCR_ETF_DTS_DIV32_N8		(15<<8)

#define TIMx_SMCR_MSM				(1<<7)

#define TIMx_SMCR_TS_ITR0			(0<<4)
#define TIMx_SMCR_TS_ITR1			(1<<4)
#define TIMx_SMCR_TS_ITR2			(2<<4)
#define TIMx_SMCR_TS_ITR3			(3<<4)
#define TIMx_SMCR_TS_TI1F_ED		(4<<4)
#define TIMx_SMCR_TS_TI1FP1			(5<<4)
#define TIMx_SMCR_TS_TI2FP2			(6<<4)
#define TIMx_SMCR_TS_ETRF			(7<<4)

#define TIMx_SMCR_SMS_DISABLE				(0<<0)
#define TIMx_SMCR_SMS_ENCODER_MODE1			(1<<0)
#define TIMx_SMCR_SMS_ENCODER_MODE2			(2<<0)
#define TIMx_SMCR_SMS_ENCODER_MODE3			(3<<0)
#define TIMx_SMCR_SMS_RESET_MODE			(4<<0)
#define TIMx_SMCR_SMS_GATE_MODE				(5<<0)
#define TIMx_SMCR_SMS_TRIGGER_MODE			(6<<0)
#define TIMx_SMCR_SMS_EXT_CLK_MODE1			(7<<0)

//TIMx_DIER_
#define TIMx_DIER_TDE			(1<<14)
#define TIMx_DIER_COMDE			(1<<13)
#define TIMx_DIER_CC4DE			(1<<12)
#define TIMx_DIER_CC3DE			(1<<11)
#define TIMx_DIER_CC2DE			(1<<10)
#define TIMx_DIER_CC1DE			(1<<9)
#define TIMx_DIER_UDE			(1<<8)
#define TIMx_DIER_BIE			(1<<7)
#define TIMx_DIER_TIE			(1<<6)
#define TIMx_DIER_COMIE			(1<<5)
#define TIMx_DIER_CC4IE			(1<<4)
#define TIMx_DIER_CC3IE			(1<<3)
#define TIMx_DIER_CC2IE			(1<<2)
#define TIMx_DIER_CC1IE			(1<<1)
#define TIMx_DIER_UIE			(1<<0)

//TIMx_SR_
#define TIMx_SR_CC4OF		(1<<12)
#define TIMx_SR_CC3OF		(1<<11)
#define TIMx_SR_CC2OF		(1<<10)
#define TIMx_SR_CC1OF		(1<<9)

#define TIMx_SR_BIF			(1<<7)
#define TIMx_SR_TIF			(1<<6)
#define TIMx_SR_COMIF		(1<<5)
#define TIMx_SR_CC4IF		(1<<4)
#define TIMx_SR_CC3IF		(1<<3)
#define TIMx_SR_CC2IF		(1<<2)
#define TIMx_SR_CC1IF		(1<<1)
#define TIMx_SR_UIF			(1<<0)

//#define TIMx_EGR_
#define TIMx_EGR_BG			(1<<7)
#define TIMx_EGR_TG			(1<<6)
#define TIMx_EGR_COMG		(1<<5)
#define TIMx_EGR_CC4G		(1<<4)
#define TIMx_EGR_CC3G		(1<<3)
#define TIMx_EGR_CC2G		(1<<2)
#define TIMx_EGR_CC1G		(1<<1)
#define TIMx_EGR_UG			(1<<0)

//#define TIMx_CCMR1_
#define TIMx_CCMR1_CC1S_OUTPUT										(0<<0)
#define TIMx_CCMR1_CC1S_INPUT_TI1									(1<<0)
#define TIMx_CCMR1_CC1S_INPUT_TI2									(2<<0)
#define TIMx_CCMR1_CC1S_INPUT_TRC									(3<<0)

//Output compare mode
#define TIMx_CCMR1_OC1FE											(1<<2)
#define TIMx_CCMR1_OC1PE											(1<<3)
#define TIMx_CCMR1_OC1M_FROZEN										(0<<4)
#define TIMx_CCMR1_OC1M_CH1_ACTIVE_OC1REF_FORCE_HIGH				(1<<4)
#define TIMx_CCMR1_OC1M__CH1_INACTIVE_OC1REF_FORCE_LOW				(2<<4)
#define TIMx_CCMR1_OC1M_TOGGLE										(3<<4)
#define TIMx_CCMR1_OC1M_OC1REF_LOW									(4<<4)
#define TIMx_CCMR1_OC1M_OC1REF_HIGH									(5<<4)
#define TIMx_CCMR1_OC1M_PWM_MODE1									(6<<4)
#define TIMx_CCMR1_OC1M_PWM_MODE2									(7<<4)
#define TIMx_CCMR1_OC1CE 											(1<<7)

//Input capture mode
#define TIMx_CCMR1_IC1PSC_EDGE										(0<<2)
#define TIMx_CCMR1_IC1PSC_2_EVENT									(1<<2)
#define TIMx_CCMR1_IC1PSC_4_EVENT									(2<<2)
#define TIMx_CCMR1_IC1PSC_8_EVENT									(3<<2)
#define TIMx_CCMR1_IC1F_DTS											(0<<4)
#define TIMx_CCMR1_IC1F_INT_N2										(1<<4)
#define TIMx_CCMR1_IC1F_INT_N4										(2<<4)
#define TIMx_CCMR1_IC1F_INT_N8										(3<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV2_N6									(4<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV2_N8									(5<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV4_N6									(6<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV4_N8									(7<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV8_N6									(8<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV8_N8									(9<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV16_N5								(10<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV16_N6								(11<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV16_N8								(12<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV32_N5								(13<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV32_N6								(14<<4)
#define TIMx_CCMR1_IC1F_DTS_DIV32_N8								(15<<4)


#define TIMx_CCMR1_CC2S_OUTPUT										(0<<8)
#define TIMx_CCMR1_CC2S_INPUT_TI1									(1<<8)
#define TIMx_CCMR1_CC2S_INPUT_TI2									(2<<8)
#define TIMx_CCMR1_CC2S_INPUT_TRC									(3<<8)

//output compare mode
#define TIMx_CCMR1_OC2FE											(1<<10)
#define TIMx_CCMR1_OC2PE											(1<<11)
#define TIMx_CCMR1_OC2M_FROZEN										(0<<12)
#define TIMx_CCMR1_OC2M_CH1_ACTIVE_OC2REF_FORCE_HIGH				(1<<12)
#define TIMx_CCMR1_OC2M__CH1_INACTIVE_OC2REF_FORCE_LOW				(2<<12)
#define TIMx_CCMR1_OC2M_TOGGLE										(3<<12)
#define TIMx_CCMR1_OC2M_OC2REF_LOW									(4<<12)
#define TIMx_CCMR1_OC2M_OC2REF_HIGH									(5<<12)
#define TIMx_CCMR1_OC2M_PWM_MODE1									(6<<12)
#define TIMx_CCMR1_OC2M_PWM_MODE2									(7<<12)
#define TIMx_CCMR1_OC2CE											(1<<15)

//Input capture mode
#define TIMx_CCMR1_IC2PSC_EDGE										(0<<10)
#define TIMx_CCMR1_IC2PSC_2_EVENT									(1<<10)
#define TIMx_CCMR1_IC2PSC_4_EVENT									(2<<10)
#define TIMx_CCMR1_IC2PSC_8_EVENT									(3<<10)
#define TIMx_CCMR1_IC2F_DTS											(0<<12)
#define TIMx_CCMR1_IC2F_INT_N2										(1<<12)
#define TIMx_CCMR1_IC2F_INT_N4										(2<<12)
#define TIMx_CCMR1_IC2F_INT_N8										(3<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV2_N6									(4<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV2_N8									(5<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV4_N6									(6<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV4_N8									(7<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV8_N6									(8<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV8_N8									(9<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV16_N5								(10<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV16_N6								(11<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV16_N8								(12<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV32_N5								(13<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV32_N6								(14<<12)
#define TIMx_CCMR1_IC2F_DTS_DIV32_N8								(15<<12)


//#define TIMx_CCMR2_
#define TIMx_CCMR2_CC3S_OUTPUT										(0<<0)
#define TIMx_CCMR2_CC3S_INPUT_TI1									(1<<0)
#define TIMx_CCMR2_CC3S_INPUT_TI2									(2<<0)
#define TIMx_CCMR2_CC3S_INPUT_TRC									(3<<0)

//Output compare mode
#define TIMx_CCMR2_OC3FE											(1<<2)
#define TIMx_CCMR2_OC3PE											(1<<3)
#define TIMx_CCMR2_OC3M_FROZEN										(0<<4)
#define TIMx_CCMR2_OC3M_CH1_ACTIVE_OC3REF_FORCE_HIGH				(1<<4)
#define TIMx_CCMR2_OC3M__CH1_INACTIVE_OC3REF_FORCE_LOW				(2<<4)
#define TIMx_CCMR2_OC3M_TOGGLE										(3<<4)
#define TIMx_CCMR2_OC3M_OC3REF_LOW									(4<<4)
#define TIMx_CCMR2_OC3M_OC3REF_HIGH									(5<<4)
#define TIMx_CCMR2_OC3M_PWM_MODE1									(6<<4)
#define TIMx_CCMR2_OC3M_PWM_MODE2									(7<<4)
#define TIMx_CCMR2_OC3CE 											(1<<7)

//Input capture mode
#define TIMx_CCMR2_IC3PSC_EDGE										(0<<2)
#define TIMx_CCMR2_IC3PSC_2_EVENT									(1<<2)
#define TIMx_CCMR2_IC3PSC_4_EVENT									(2<<2)
#define TIMx_CCMR2_IC3PSC_8_EVENT									(3<<2)
#define TIMx_CCMR2_IC3F_DTS											(0<<4)
#define TIMx_CCMR2_IC3F_INT_N2										(1<<4)
#define TIMx_CCMR2_IC3F_INT_N4										(2<<4)
#define TIMx_CCMR2_IC3F_INT_N8										(3<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV2_N6									(4<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV2_N8									(5<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV4_N6									(6<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV4_N8									(7<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV8_N6									(8<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV8_N8									(9<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV16_N5								(10<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV16_N6								(11<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV16_N8								(12<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV32_N5								(13<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV32_N6								(14<<4)
#define TIMx_CCMR2_IC3F_DTS_DIV32_N8								(15<<4)


#define TIMx_CCMR2_CC4S_OUTPUT										(0<<8)
#define TIMx_CCMR2_CC4S_INPUT_TI1									(1<<8)
#define TIMx_CCMR2_CC4S_INPUT_TI2									(2<<8)
#define TIMx_CCMR2_CC4S_INPUT_TRC									(3<<8)

//output compare mode
#define TIMx_CCMR2_OC4FE											(1<<10)
#define TIMx_CCMR2_OC4PE											(1<<11)
#define TIMx_CCMR2_OC4M_FROZEN										(0<<12)
#define TIMx_CCMR2_OC4M_CH1_ACTIVE_OC2REF_FORCE_HIGH				(1<<12)
#define TIMx_CCMR2_OC4M__CH1_INACTIVE_OC2REF_FORCE_LOW				(2<<12)
#define TIMx_CCMR2_OC4M_TOGGLE										(3<<12)
#define TIMx_CCMR2_OC4M_OC2REF_LOW									(4<<12)
#define TIMx_CCMR2_OC4M_OC2REF_HIGH									(5<<12)
#define TIMx_CCMR2_OC4M_PWM_MODE1									(6<<12)
#define TIMx_CCMR2_OC4M_PWM_MODE2									(7<<12)
#define TIMx_CCMR2_OC4CE											(1<<15)

//Input capture mode
#define TIMx_CCMR2_IC4PSC_EDGE										(0<<10)
#define TIMx_CCMR2_IC4PSC_2_EVENT									(1<<10)
#define TIMx_CCMR2_IC4PSC_4_EVENT									(2<<10)
#define TIMx_CCMR2_IC4PSC_8_EVENT									(3<<10)
#define TIMx_CCMR2_IC4F_DTS											(0<<12)
#define TIMx_CCMR2_IC4F_INT_N2										(1<<12)
#define TIMx_CCMR2_IC4F_INT_N4										(2<<12)
#define TIMx_CCMR2_IC4F_INT_N8										(3<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV2_N6									(4<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV2_N8									(5<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV4_N6									(6<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV4_N8									(7<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV8_N6									(8<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV8_N8									(9<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV16_N5								(10<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV16_N6								(11<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV16_N8								(12<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV32_N5								(13<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV32_N6								(14<<12)
#define TIMx_CCMR2_IC4F_DTS_DIV32_N8								(15<<12)


//#define TIMx_CCER_
#define TIMx_CCER_CC4P		(1<<13)
#define TIMx_CCER_CC4E		(1<<12)
#define TIMx_CCER_CC3NP		(1<<11)
#define TIMx_CCER_CC3NE		(1<<10)
#define TIMx_CCER_CC3P		(1<<9)
#define TIMx_CCER_CC3E		(1<<8)
#define TIMx_CCER_CC2NP		(1<<7)
#define TIMx_CCER_CC2NE		(1<<6)
#define TIMx_CCER_CC2P		(1<<5)
#define TIMx_CCER_CC2E		(1<<4)
#define TIMx_CCER_CC1NP		(1<<3)
#define TIMx_CCER_CC1NE		(1<<2)
#define TIMx_CCER_CC1P		(1<<1)
#define TIMx_CCER_CC1E		(1<<0)

//#define TIMx_BDTR_
#define TIMx_BDTR_MOE				(<<15)
#define TIMx_BDTR_AOE				(<<14)
#define TIMx_BDTR_BKP				(<<13)
#define TIMx_BDTR_BKE				(<<12)
#define TIMx_BDTR_OSSR				(<<11)
#define TIMx_BDTR_OSSI				(<<10)

#define TIMx_BDTR_LOCK_OFF			(0<<8)
#define TIMx_BDTR_LOCK_LEVEL_1		(1<<8)
#define TIMx_BDTR_LOCK_LEVEL_2		(2<<8)
#define TIMx_BDTR_LOCK_LEVEL_3		(3<<8)



#endif /* TIMER_H_ */
