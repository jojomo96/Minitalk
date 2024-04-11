CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=libft
LIBFTPRINTF=libftprintf
LIBFT_LIB=$(LIBFT)/libft.a
LIBFTPRINTF_LIB=$(LIBFTPRINTF)/libftprintf.a
LIBFT_INC=-I$(LIBFT)
LIBFTPRINTF_INC=-I$(LIBFTPRINTF)
LFLAGS=-L$(LIBFT) -lft -L$(LIBFTPRINTF) -lftprintf

all: server client

server: server.c $(LIBFT_LIB) $(LIBFTPRINTF_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBFTPRINTF_INC) $< -o $@ $(LFLAGS)

client: client.c $(LIBFT_LIB) $(LIBFTPRINTF_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBFTPRINTF_INC) $< -o $@ $(LFLAGS)

$(LIBFT_LIB):
	make -C $(LIBFT)

$(LIBFTPRINTF_LIB):
	make -C $(LIBFTPRINTF)

clean:
	rm -f server client
	make -C $(LIBFT) clean
	make -C $(LIBFTPRINTF) clean

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(LIBFTPRINTF) fclean

re: fclean all

.PHONY: all clean fclean re server client
