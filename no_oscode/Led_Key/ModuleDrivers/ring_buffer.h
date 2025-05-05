//
// Created by 19108 on 25-5-5.
//

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "stm32f1xx_hal.h"

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char buffer[BUFFER_SIZE]; /* 缓冲区地址 */
    volatile unsigned int pW;
    volatile unsigned int pR;
} ring_buffer;

extern void ring_buffer_init(ring_buffer *dst_buf);
extern void ring_buffer_write(unsigned char c, ring_buffer *dst_buf);
extern int ring_buffer_read(unsigned char *c, ring_buffer *dst_buf);

#endif //RING_BUFFER_H
