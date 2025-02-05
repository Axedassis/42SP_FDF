# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 01:34:42 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/04 15:59:28 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJ_DIR = ./build/
AR = ar rcs
TIMESTAMP_FILE = .last_build

SRC = boolean/ft_bzero.c \
		boolean/ft_isalnum.c \
		boolean/ft_isalpha.c \
		boolean/ft_isascii.c \
		boolean/ft_isdigit.c \
		boolean/ft_isprint.c \
		conversion/ft_atoi_hexa.c \
		conversion/ft_tolower.c \
		conversion/ft_toupper.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		memory/ft_calloc.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memset.c \
		printf/ft_itoa.c \
		printf/ft_printf.c \
		printf/ft_putchar.c \
		printf/ft_putint.c \
		printf/ft_puthex.c \
		printf/ft_putpnt.c \
		printf/ft_putstr.c \
		printf/ft_strlen.c \
		printf/ft_unsig.c \
		string/ft_atoi.c \
		string/ft_itoa.c \
		string/ft_split.c \
		string/ft_srtcmp.c \
		string/ft_strchr.c \
		string/ft_strdup.c \
		string/ft_striteri.c \
		string/ft_strjoin.c \
		string/ft_strlcat.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_strmapi.c \
		string/ft_strncmp.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_strtrim.c \
		string/ft_substr.c \

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@${AR} ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re