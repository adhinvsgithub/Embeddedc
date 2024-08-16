#include "main.h"
#include "stm32f4xx_hal.h" // Adjust based on your STM32 series

// Function prototypes
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
    // Initialize the HAL Library
    HAL_Init();

    // Configure the system clock
    SystemClock_Config();

    // Initialize all configured peripherals
    MX_GPIO_Init();

    // Infinite loop
    while (1)
    {
        // Toggle the LED
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);

        // Insert a delay
        HAL_Delay(1000); // Delay for 1000 milliseconds (1 second)
    }
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable GPIOB clock
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // Configure GPIO pin Output Level
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

    // Configure GPIO pin : PB5
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/**
 * @brief This function is called in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    // User can add their own implementation to report the HAL error return state
    while (1)
    {
    }
}
