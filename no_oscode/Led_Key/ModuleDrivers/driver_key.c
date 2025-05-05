//
// Created by 19108 on 25-4-26.
//

#include "driver_key.h"


uint8_t K1_Value(void) {
    if (K1 == 0) {
        HAL_Delay(20);
        if (K1 == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    return 1;
}


