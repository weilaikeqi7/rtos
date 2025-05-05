//
// Created by 19108 on 25-4-26.
//

#include "driver_key.h"

static volatile uint8_t key1_val = KEY_RELEASED;     // 按键KEY1的键值，按下为0松开为1
static volatile uint8_t key2_val = KEY_RELEASED;     // 按键KEY2的键值，按下为0松开为1
static volatile uint8_t key3_val = KEY_RELEASED;
static volatile uint8_t key4_val = KEY_RELEASED;

void KEY_GPIO_ReInit(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    KEY1_GPIO_CLK_EN();
    KEY2_GPIO_CLK_EN();
    KEY3_GPIO_CLK_EN();
    KEY4_GPIO_CLK_EN();

    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;     // 双边沿触发中断
    GPIO_InitStruct.Pull = GPIO_PULLUP;

    GPIO_InitStruct.Pin = KEY1_PIN;
    HAL_GPIO_Init(KEY1_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = KEY2_PIN;
    HAL_GPIO_Init(KEY2_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = KEY3_PIN;
    HAL_GPIO_Init(KEY3_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = KEY4_PIN;
    HAL_GPIO_Init(KEY4_PORT, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);

    HAL_NVIC_SetPriority(EXTI3_IRQn, 3, 0);
    HAL_NVIC_EnableIRQ(EXTI3_IRQn);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_PIN); // 使用HAL库的外部中断统一服务函数，参数是外部中断线
}

void EXTI3_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY4_PIN);
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY2_PIN); // 使用HAL库的外部中断统一服务函数，参数是外部中断线
    HAL_GPIO_EXTI_IRQHandler(KEY3_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(KEY1_PIN == GPIO_Pin)    // 判断进来的外部中断线连接的引脚是不是按键的引脚
    {
        key1_val = K1;  // 读取按键连接的引脚的状态
    }
    else if(KEY2_PIN == GPIO_Pin)    // 判断进来的外部中断线连接的引脚是不是按键的引脚
    {
        key2_val = K2;  // 读取按键连接的引脚的状态
    }
    else if(KEY3_PIN == GPIO_Pin)
    {
        key3_val = K3;
    }
    else if(KEY4_PIN == GPIO_Pin)
    {
        key4_val = K4;
    }
}

uint8_t KEY1_Value(void) {
    return key1_val;
}

uint8_t KEY2_Value(void) {
    return key2_val;
}

uint8_t KEY3_Value(void) {
    return key3_val;
}

uint8_t KEY4_Value(void) {
    return key4_val;
}
