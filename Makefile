CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=libft
LIBFTPRINTF=libftprintf
LIBFT_LIB=$(LIBFT)/libft.a
LIBFTPRINTF_LIB=$(LIBFTPRINTF)/libftprintf.a
LIBFT_INC=-I$(LIBFT)
LIBFTPRINTF_INC=-I$(LIBFTPRINTF)
LFLAGS=-L$(LIBFT) -lft -L$(LIBFTPRINTF) -lftprintf

all: libft libftprintf server client

libft: $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT)

libftprintf: $(LIBFTPRINTF_LIB)

$(LIBFTPRINTF_LIB):
	make -C $(LIBFTPRINTF)

server: server.c
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBFTPRINTF_INC) server.c -o server $(LFLAGS)

client: client.c
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBFTPRINTF_INC) client.c -o client $(LFLAGS)

clean:
	rm -f server client
	make -C $(LIBFT) clean
	make -C $(LIBFTPRINTF) clean

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(LIBFTPRINTF) fclean

bonus: all

re: fclean all

.PHONY: all clean server client re fclean bonus libft libftprintf
