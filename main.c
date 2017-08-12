/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f7xx.h"
/**
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_rcc.h"
#include "stm32f7xx_hal_tim.h"
**/

static volatile uint8_t timer_flag = 0;
static TIM_HandleTypeDef htim;

static void init_gpio(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef gpio1;
	gpio1.Pin = GPIO_PIN_3;
	gpio1.Mode = GPIO_MODE_OUTPUT_PP;
	gpio1.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &gpio1);

	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef gpio2;
	gpio2.Pin = GPIO_PIN_0;
	gpio2.Mode = GPIO_MODE_OUTPUT_PP;
	gpio2.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &gpio2);
}

static void init_timer(void)
{
    __HAL_RCC_TIM2_CLK_ENABLE();
	htim.Instance = TIM2;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Prescaler = 10000;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV4;
	htim.Init.Period = 810;
	htim.Init.RepetitionCounter = 0;
	HAL_TIM_Base_MspInit(&htim);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_TIM_Base_Init(&htim);
	HAL_TIM_Base_Start_IT(&htim);
}

static void init_hw(void)
{
    init_gpio();
    init_timer();
	
}

static void fast_loop(void)
{
    //really fast stuff();
}

static void ms_loop(void)
{
    static uint8_t count;

    //1 ms stuff();

    switch (count)
    {
        case 0;
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_0);
        break;

        case 1;
            //10 ms other()
        break;
    }      

    
    if (count < 9)
    {    
        count++;
    }   
    else
    {
        count = 0;
    }
}

int main(void)
{
	init_hw();

    while(1)
	{
        fast_loop();
    
        if (timer_flag != 0)
		{
			timer_flag = 0;

            ms_loop();
		}
	}

	return 0;
}


void TIM2_IRQHandler(void)
{
	timer_flag = 1;

	HAL_TIM_IRQHandler(&htim);
}
