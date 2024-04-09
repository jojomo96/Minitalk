CC=cc
CFLAGS=-Wall -Wextra

all: server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f server client

fclean: clean

bonus: all

re: clean all

.PHONY: all clean server client re fclean bonus
