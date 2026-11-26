CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -fsanitize=undefined

test: main.c
	$(CC) $(CFLAGS) main.c -o test

run: test
	./test
clean:
	rm -f test
