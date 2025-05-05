//
// Created by 19108 on 25-4-26.
//

#include "driver_led.h"
#include "main.h"

void BuleOn(void) {
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
}

void BuleOff(void) {
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
}

void BlueShine(void) {
    BuleOn();
    HAL_Delay(500);
    BuleOff();
    HAL_Delay(500);
}

void BlueShine2(void) {
    HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
}