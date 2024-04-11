CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=libft
LIBFTPRINTF=libftprintf
LIBFT_LIB=$(LIBFT)/libft.a
LIBFTPRINTF_LIB=$(LIBFTPRINTF)/libftprintf.a
LIBFT_INC=-I$(LIBFT)
LIBFTPRINTF_INC=-I$(LIBFTPRINTF)
LFLAGS=-L$(LIBFT) -lft -L$(LIBFTPRINTF) -lftprintf

# Target all now depends on server and client binaries explicitly.
all: $(LIBFT_LIB) $(LIBFTPRINTF_LIB) server client

$(LIBFT_LIB):
	make -C $(LIBFT)

$(LIBFTPRINTF_LIB):
	make -C $(LIBFTPRINTF)

server: server.c $(LIBFT_LIB) $(LIBFTPRINTF_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBFTPRINTF_INC) server.c -o $@ $(LFLAGS)

client: client.c $(LIBFT_LIB) $(LIBFTPRINTF_LIB)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBFTPRINTF_INC) client.c -o $@ $(LFLAGS)

clean:
	rm -f server client
	make -C $(LIBFT) clean
	make -C $(LIBFTPRINTF) clean

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(LIBFTPRINTF) fclean

# The bonus target could be defined here if it requires additional actions.
bonus: all

re: fclean all

.PHONY: all clean fclean re bonus libft libftprintf server client
