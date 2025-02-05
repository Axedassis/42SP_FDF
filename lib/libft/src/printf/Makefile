CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a

SRC = ft_printf.c \
	ft_putchar.c \
	ft_strlen.c \
	ft_putstr.c \
	ft_unsig.c \
	ft_itoa.c \
	ft_putint.c \
	ft_putpnt.c \
	ft_puthex.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
