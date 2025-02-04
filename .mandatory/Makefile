# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 18:35:55 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/03 18:35:14 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC		= cc
CFLAGS	= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
INCLUDE		= -I . -lm -lXext -lX11 -lXrandr

LIBMLX_DIR	= ./minilibx-linux
LIBMLX_LIB = $(LIBMLX_DIR)/libmlx_Linux.a

LIBFT_DIR	= ./libft
LIBFT_LIB = $(LIBFT_DIR)/lib/libft.a

SRC		= bresenham.c \
			color_functions.c \
			common_functions.c \
			init_functions.c \
			map_functions.c \
			mlx_functions.c \
			pts_functions.c \
			render_functions.c \
			model_render.c \
			main.c 

OBJ		= $(SRC:.c=.o)

all: libmlx libft $(NAME)

$(NAME): libft libmlx $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(LIBMLX_LIB) $(INCLUDE) -o $(NAME)
libft:
	make all -C $(LIBFT_DIR)

libmlx:
	make -C $(LIBMLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS)  -I . -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(LIBMLX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all
	
.PHONY: all clean fclean re bonus libft libmlx