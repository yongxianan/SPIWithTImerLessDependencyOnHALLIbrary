/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rcc.h"
#include "gpio.h"
#include "spi.h"
#include "stateMachine.h"
#include "timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
volatile uint8_t slaveMsg = 0;
volatile uint8_t masterMsg = 0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST | RCC_APB2RSTR_SPI4RST | RCC_APB2RSTR_TIM1RST;
	RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST | RCC_APB2RSTR_SPI4RST | RCC_APB2RSTR_TIM1RST);
	RCC->APB2ENR |= (RCC_APB2ENR_SPI1EN | RCC_APB2ENR_SPI4EN | RCC_APB2ENR_TIM1EN);

	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST | RCC_AHB1RSTR_GPIOARST			\
			| RCC_AHB1RSTR_GPIOBRST | RCC_AHB1RSTR_GPIOGRST;
	RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOERST | RCC_AHB1RSTR_GPIOARST 		\
			| RCC_AHB1RSTR_GPIOBRST | RCC_AHB1RSTR_GPIOGRST);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIOAEN 				\
			| RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOGEN);

	/*
	 * PG13	green LED
	 * PA0	blue button
	 */
	configGPIOWithoutAF(GPIOA,0,GPIO_INPUT,0,VERY_HIGH_SPEED,PULL_DOWN);
	configGPIOWithoutAF(GPIOG,13,GPIO_OUTPUT,OUTPUT_PUSH_PULL			\
				,HIGH_SPEED,NO_PUPD);
	/*
	 * SPI1.NSS PA4
	 * SPI1.CLK PA5
	 * SPI1.MISO PB4
	 * SPI1.MOSI PB5
	 */
	configGPIO(GPIOA,4,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL			\
			,HIGH_SPEED,NO_PUPD,AF5);
	configGPIO(GPIOA,5,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL		\
			,HIGH_SPEED,NO_PUPD,AF5);
	configGPIO(GPIOB,4,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL			\
			,HIGH_SPEED,NO_PUPD,AF5);
	configGPIO(GPIOB,5,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL		\
			,HIGH_SPEED,NO_PUPD,AF5);

	/*
	 * SPI4_SCK    PE2
	 * SPI4_NSS    PE4
	 * SPI4_MISO   PE5
	 * SPI4_MOSI   PE6
	 */
	configGPIO(GPIOE,2,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL			\
				,HIGH_SPEED,NO_PUPD,AF5);
	configGPIO(GPIOE,4,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL			\
				,HIGH_SPEED,NO_PUPD,AF5);
	configGPIO(GPIOE,5,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL			\
				,HIGH_SPEED,NO_PUPD,AF5);
	configGPIO(GPIOE,6,GPIO_ALT_FUNC,OUTPUT_PUSH_PULL			\
				,HIGH_SPEED,NO_PUPD,AF5);
	/*
	 * SPI1:master
	 * SPI4:slave
	 */
	spiConfig(SPI1,F_PCLK_DIV_256 | UNIDIRECT_DATA_MODE_TWO_LINE	\
			| DATA_FRAME_8_BIT | FULL_DUPLEX | MSTR_MASTER_CONFIG	\
			| FRF_SPI_MOTOROLA | CPOL_CK0_WHEN_IDLE					\
			| CPHA_FIRST | SPI_MSB_FIRST | SSOE_1 | RXNEIE_NOT_MASK);

	spiConfig(SPI4,F_PCLK_DIV_256 | UNIDIRECT_DATA_MODE_TWO_LINE	\
			| DATA_FRAME_8_BIT | FULL_DUPLEX | MSTR_SLAVE_CONFIG	\
			| FRF_SPI_MOTOROLA | CPOL_CK0_WHEN_IDLE					\
			| CPHA_FIRST | SPI_MSB_FIRST | RXNEIE_NOT_MASK);


	//TIM1:
	//OPM,update interrupt
	//configAdvancedTIM(TIM1, TIMx_CR1_OPM);
	configPSC(TIM1,16000000,0.001);
	configARR(TIM1,2000);
	config_DMA_ISR(TIM1,TIMx_DIER_UIE);
	configAdvancedTIM(TIM1,TIMx_CR1_OPM);


	//TIM1 update interrupt
	nvicEnableInterrupt(25);

	//SPI1 interrupt
	nvicEnableInterrupt(35);

	//SPI4 interrupt
	nvicEnableInterrupt(84);
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  spiEnable(SPI1);
  spiEnable(SPI4);

  sendData(SPI1,0x23);
  configAdvancedTIM(TIM1,TIMx_CR1_COUNT_EN);

  HAL_Delay(5000);

  sendData(SPI1,0x45);
  configAdvancedTIM(TIM1,TIMx_CR1_COUNT_EN);

  //slaveMsg = receiveData(SPI4);
  //masterMsg = receiveData(SPI1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 64;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV4;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

SMInfo smInfo;

void SPI1_IRQHandler(void){
	if(SPI1->SR & RXNE_NOT_EMPTY){
		masterMsg = (SPI1->DR & 0xff);
	}
	SPI1->SR &= ~(RXNE_NOT_EMPTY);
}

void SPI4_IRQHandler(void){
	if(SPI4->SR & RXNE_NOT_EMPTY){
		slaveMsg = (SPI4->DR & 0xff);
	}
	smInfo.slaveMsg=slaveMsg;
	if(slaveMsg==0x23){
		smInfo.state=READ_BUTTON_COMMAND;
	}else if(slaveMsg==0x45){
		smInfo.state=CONTROL_LED_COMMMAND;
	}
	stateMachineSlaveV2(&smInfo);
	//SPI4->SR &= ~(RXNE_NOT_EMPTY);
}

void TIM1_UP_TIM10_IRQHandler(void){
	sendData(SPI1,0x01);
	TIM1->SR &= ~(TIMx_SR_UIF);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
