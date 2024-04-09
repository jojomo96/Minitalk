CC=cc
CFLAGS=-Wall -Wextra

all: server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f server client

re: clean all

.PHONY: all clean server client re
