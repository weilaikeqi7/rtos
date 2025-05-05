/*  Copyright (s) 2019 深圳百问网科技有限公司
*  All rights reserved
 *
 * 文件名称：driver_usart.c
 * 摘要：
 *
 * 修改历史     版本号        Author       修改内容
 *--------------------------------------------------
 * 2021.8.21      v01         百问科技      创建文件
 *--------------------------------------------------
*/

#include "driver_usart.h"
#include "usart.h"
#include <string.h>
#include "ring_buffer.h"
/*
 *  函数名：DebugPrint
 *  功能描述：输出一串字符
 *  输入参数：str --> 指向要输出数据的首地址
 *  输出参数：无
 *  返回值：无
*/
static volatile uint8_t txcplt_flag = 0;    // 发送完成标志，1完成0未完成
static volatile uint8_t rxcplt_flag = 0;    // 接收完成标志，1完成0未完成

static volatile uint8_t rx_data = 0;
extern ring_buffer test_buffer;

void DebugPrint(const char *str)
{
    uint16_t len = strlen(str);

    HAL_UART_Transmit(&huart1, (uint8_t*)str, len, 3000);
}

/*
 *  函数名：DebugGet
 *  功能描述：接收指定长度的数据
 *  输入参数：str --> 指向将接收到的数据保存到内存中的首地址
 *            len --> 要接收数据的个数
 *  输出参数：无
 *  返回值：无
*/
void DebugGet(char *str, uint16_t len)
{
    while(HAL_UART_Receive(&huart1, (uint8_t*)str, len, 3000) != HAL_OK );
}

/**
  * 函数功能: 重定向 c库函数 printf到 DEBUG_USARTx
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
int __io_putchar(int ch)
{
    txcplt_flag = 0;
    HAL_UART_Transmit_IT(&huart1, (uint8_t *)&ch, 1);
    while (txcplt_flag == 0);
    return ch;
}

/**
  * 函数功能: 重定向 c库函数 getchar,scanf到 DEBUG_USARTx
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
int __io_getchar(void)
{
    uint8_t ch = 0;
    while(ring_buffer_read((unsigned char *)&ch, &test_buffer) != 0);
    return ch;
}

void EnableDebugIRQ(void) {
    HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

    __HAL_UART_ENABLE_IT(&huart1, UART_IT_TC | UART_IT_RXNE);
}

void DisableDebugIRQ(void) {
    __HAL_UART_DISABLE_IT(&huart1, UART_IT_TC | UART_IT_RXNE);

    HAL_NVIC_DisableIRQ(USART1_IRQn);
}

void USART1_IRQHandler(void)
{
    unsigned char c = 0;
    if ((USART1->SR & (1 << 5)) != 0) {
        c = USART1->DR;
        ring_buffer_write(c, &test_buffer);
    }
    HAL_UART_IRQHandler(&huart1);   // HAL库中的UART统一中断服务函数，通过形参判断是要处理谁的中断
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)   // 判断进来的是否是USART1这个UART设备
    {
        rxcplt_flag = 1;        // 进入此回调函数表明接收指定长度的数据已经完成，将标志置一
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        txcplt_flag = 1;    // 进入此回调函数表明发送指定长度的数据已经完成，将标志置一
    }
}
