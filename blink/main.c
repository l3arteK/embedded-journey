#include <stdint.h>

#define RCC_AHB1ENR  (*(volatile uint32_t *)0x40023830u)
#define GPIOA_MODER  (*(volatile uint32_t *)0x40020000u)
#define GPIOA_ODR    (*(volatile uint32_t *)0x40020014u)

int main(void) {
    // 1. Włącz zegar portu A: ustaw bit 0 w RCC_AHB1ENR
    // 2. Ustaw PA5 jako wyjście: pole bitów 10–11 w GPIOA_MODER = 0b01
    // 3. W pętli: przełącz bit 5 w GPIOA_ODR i odczekaj chwilę

    RCC_AHB1ENR |= (1u << 0);
    GPIOA_MODER = (GPIOA_MODER & ~(3u << 10)) | (1u<<10);


    while (1) {
        GPIOA_ODR ^= (1u << 5);
            for (volatile uint32_t i = 0; i < 100000; i++) {
       
     }
         
    }
}