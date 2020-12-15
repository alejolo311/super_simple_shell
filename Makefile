CC = gcc
CFLAGS = #-Wall -Werror -Wextra -pedantic

main: main.c linked.c
	$(CC) $(CFLAGS) main.c linked.c -o program && ./program