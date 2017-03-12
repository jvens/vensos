
/*
#include "uart/uart.h"
#define UART_BASE 0x01C28400
uart::Uart stream(UART_BASE);

extern "C" int _write(int file, char *ptr, int len)
{
    int count = len;
    if (file == 1) { // stdout
        while (count > 0) {
            //while (0 ) {} // just wait
            //TX_REG = *ptr;
            stream.send(*ptr);
            ++ptr;
            --count;
        }
    }
    return len;
}
*/
