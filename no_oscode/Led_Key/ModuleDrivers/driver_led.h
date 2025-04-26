//
// Created by 19108 on 25-4-26.
//

#ifndef DRIVER_LED_H
#define DRIVER_LED_H

#define BLUE_ON()   HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET)
#define BLUE_OFF()  HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET)

void BuleOn(void);
void BuleOff(void);
void BlueShine(void);
void BlueShine2(void);
#endif //DRIVER_LED_H
