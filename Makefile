CC = gcc
CFLAGS = #-Wall -Werror -Wextra -pedantic

main: main.c linked.c helpers.c
	$(CC) $(CFLAGS) main.c linked.c helpers.c -o hsh