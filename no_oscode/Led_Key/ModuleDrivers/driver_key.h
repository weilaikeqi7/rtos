/*  Copyright (s) 2019 深圳百问网科技有限公司
*  All rights reserved
 *
 * 文件名称：driver_key.h
 * 摘要：
 *
 * 修改历史     版本号        Author       修改内容
 *--------------------------------------------------
 * 2021.8.21      v01         百问科技      创建文件
 *--------------------------------------------------
*/

#ifndef __DRIVER_KEY_H
#define __DRIVER_KEY_H

#include "stm32f1xx_hal.h"

/*
    按键状态宏定义
*/
#define KEY_PRESSED			(0)
#define KEY_RELEASED		(1)

/*********************
 * 引脚宏定义
**********************/
#define KEY1_PIN				GPIO_PIN_0
#define KEY2_PIN				GPIO_PIN_15
#define KEY3_PIN				GPIO_PIN_13
#define KEY4_PIN				GPIO_PIN_3

#define KEY1_PORT				GPIOA
#define KEY2_PORT				GPIOG
#define KEY3_PORT				GPIOC
#define KEY4_PORT				GPIOE
/*********************
 * 函数宏定义
**********************/
#define KEY1_GPIO_CLK_EN()	__HAL_RCC_GPIOA_CLK_ENABLE()
#define KEY2_GPIO_CLK_EN()	__HAL_RCC_GPIOG_CLK_ENABLE()
#define KEY3_GPIO_CLK_EN()	__HAL_RCC_GPIOC_CLK_ENABLE()
#define KEY4_GPIO_CLK_EN()	__HAL_RCC_GPIOE_CLK_ENABLE()

#define K1							HAL_GPIO_ReadPin(KEY1_PORT, KEY1_PIN)
#define K2							HAL_GPIO_ReadPin(KEY2_PORT, KEY2_PIN)
#define K3							HAL_GPIO_ReadPin(KEY3_PORT, KEY3_PIN)
#define K4							HAL_GPIO_ReadPin(KEY4_PORT, KEY4_PIN)
/*
 *  函数名：KEY_GPIO_ReInit
 *  功能描述：按键的GPIO重新初始化为双边沿触发外部中断
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
*/
extern void KEY_GPIO_ReInit(void);

/*
 *  函数名：KEY1_Value
 *  功能描述：返回按键KEY1的键值
 *  输入参数：无
 *  输出参数：无
 *  返回值：返回按键KEY1的键值
*/
extern uint8_t KEY1_Value(void);

/*
 *  函数名：KEY2_Value
 *  功能描述：返回按键KEY2的键值
 *  输入参数：无
 *  输出参数：无
 *  返回值：返回按键KEY2的键值
*/
extern uint8_t KEY2_Value(void);

/*
 *  函数名：KEY3_Value
 *  功能描述：返回按键KEY3的键值
 *  输入参数：无
 *  输出参数：无
 *  返回值：返回按键KEY3的键值
*/
extern uint8_t KEY3_Value(void);

/*
 *  函数名：KEY4_Value
 *  功能描述：返回按键KEY4的键值
 *  输入参数：无
 *  输出参数：无
 *  返回值：返回按键KEY4的键值
*/
extern uint8_t KEY4_Value(void);
#endif /* __DRIVER_KEY_H */