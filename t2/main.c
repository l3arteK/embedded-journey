#include <stdio.h>
#include <string.h>

typedef struct {
    const char *name;
    void (*handler)(void);
} command_t;

void led_on(void)  { puts("LED ON"); }
void led_off(void) { puts("LED OFF"); }
void status(void)  { puts("STATUS: OK"); }

const command_t commands[] = {
    {"led_on",  led_on},
    {"led_off", led_off},
    {"status",  status},
};

void dispatch(const char *name) {
    // TODO:
    // 1. przejdź pętlą po tablicy commands
    // 2. porównaj name z commands[i].name (strcmp zwraca 0, gdy napisy są równe)
    // 3. jeśli pasuje: wywołaj handler tej komendy i wyjdź z funkcji
    // 4. jeśli nic nie pasuje: wypisz "nieznana komenda"

    for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++) {
        if(strcmp(name, commands[i].name) == 0) {
            commands[i].handler();
            return;
        }
    }
    puts("nieznana komenda");
}

int main(void) {
    dispatch("led_on");
    dispatch("status");
    dispatch("abc");
    return 0;
}