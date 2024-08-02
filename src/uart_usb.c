/**
 * input : UART
 * output: USB
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart0
#define UART_BAUDRATE 115200

#define UART_TX_PIN 16
#define UART_RX_PIN 17

int main(void) {
    stdio_init_all();
    uart_init(UART_ID, UART_BAUDRATE);

    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    while (1) {
        char c = uart_getc(UART_ID);
        printf("%c", c);
    }
}
