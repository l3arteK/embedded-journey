#include <stdint.h>

extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;
int main(void);

void Reset_Handler(void) {
    uint32_t *src = &_sidata;
    for (uint32_t *dst = &_sdata; dst < &_edata; ) *dst++ = *src++;   // kopiuj .data
    for (uint32_t *dst = &_sbss;  dst < &_ebss;  ) *dst++ = 0;        // zeruj .bss
    main();
    while (1) { }
}

__attribute__((section(".isr_vector"), used))
void (* const vector_table[])(void) = {
    (void (*)(void))(&_estack),   // początkowy wskaźnik stosu
    Reset_Handler,                // co uruchomić po resecie
};