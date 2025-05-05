//
// Created by 19108 on 25-4-26.
//

#ifndef DRIVER_KEY_H
#define DRIVER_KEY_H
#include "main.h"

#define K1  HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)

uint8_t K1_Value(void);

#endif //DRIVER_KEY_H
