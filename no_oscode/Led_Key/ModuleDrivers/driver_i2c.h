//
// Created by 19108 on 25-5-5.
//

#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include "stm32f1xx_hal.h"

#define SCL_PIN GPIO_PIN_10
#define SDA_PIN GPIO_PIN_11

#define SCL_PORT GPIOF
#define SDA_PORT GPIOF

#define SCL_H   HAL_GPIO_WritePin(SCL_PORT, SCL_PIN, GPIO_PIN_SET)
#define SCL_L   HAL_GPIO_WritePin(SCL_PORT, SCL_PIN, GPIO_PIN_RESET)

#define SDA_H   HAL_GPIO_WritePin(SDA_PORT, SDA_PIN, GPIO_PIN_SET)
#define SDA_L   HAL_GPIO_WritePin(SDA_PORT, SDA_PIN, GPIO_PIN_RESET)
#define SDA_IN  HAL_GPIO_ReadPin(SDA_PORT, SDA_PIN)

extern void I2C_GPIO_ReInit(void);
extern void I2C_Start(void);
extern void I2C_Stop(void);
extern int I2C_GetAck(void);
extern void I2C_ACK(void);
extern void I2C_NACK(void);
extern void I2C_WriteByte(uint8_t data);
extern uint8_t I2C_ReadByte(uint8_t ack);

#endif //DRIVER_I2C_H
