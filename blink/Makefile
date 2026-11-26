CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -O0 -g -Wall -Wextra -std=c11 -ffreestanding
LDFLAGS = -nostdlib -T linker.ld

blink.elf: main.c startup.c linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) main.c startup.c -o blink.elf

flash: blink.elf
	sudo openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program blink.elf verify reset exit"

clean:
	rm -f blink.elf