#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

int main(void) {
    stdio_init_all();
    char c = 'a';
    while (1) {
        if (c == 'z') {
            c = 'A';
        } else if (c == 'Z') {
            c = '0';
        } else if (c == '9') {
            c = 'a';
        } else {
            c += 1;
        }
        sleep_ms(500u);
        printf("%c\n", c);
    }
}
