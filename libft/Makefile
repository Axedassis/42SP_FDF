# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 01:34:42 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/04 01:36:38 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = ./build/
AR = ar rcs

SRC = $(wildcard ./src/**/*.c)

OBJ := $(SRC:./src/%.c=$(OBJ_DIR)%.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p lib
	$(AR) ./lib/$@ $(OBJ)

$(OBJ_DIR)%.o: ./src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf ./lib

re: fclean all

.PHONY: all clean fclean re