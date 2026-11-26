#include <stdint.h>

uint32_t counter = 5;
uint32_t buffer[256];
const char msg[] = "Hello embedded";

int main(void) {
    int calls;
    uint8_t tmp[16] = {0};
    calls++;
    return tmp[0] + buffer[0] + counter + msg[0] + calls;
}