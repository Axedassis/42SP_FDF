# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 18:35:55 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/04 15:54:23 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC		= cc
CFLAGS	= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
INCLUDE	= -I . -lm -lXext -lX11 -lXrandr

LIBMLX_DIR	= ./minilibx-linux
LIBMLX_LIB	= $(LIBMLX_DIR)/libmlx_Linux.a

LIBFT_DIR	= ./libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRC	= bresenham.c \
	  color_functions.c \
	  common_functions.c \
	  init_functions.c \
	  map_functions.c \
	  mlx_functions.c \
	  pts_functions.c \
	  render_functions.c \
	  model_render.c \
	  main.c 

SRC_BONUS	= bresenham_bonus.c \
		  color_functions_bonus.c \
		  common_functions_bonus.c \
		  init_functions_bonus.c \
		  map_functions_bonus.c \
		  mlx_functions_bonus.c \
		  pts_functions_bonus.c \
		  render_functions_bonus.c \
		  model_render_bonus.c \
		  key_handler_bonus.c \
		  rotate_bonus.c \
		  info_screen_bonus.c \
		  main_bonus.c 

OBJ		= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

all: libmlx libft $(NAME)

bonus: libmlx libft $(NAME)_bonus

$(NAME)_bonus: $(OBJ_BONUS) $(LIBFT_LIB) $(LIBMLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_LIB) $(LIBMLX_LIB) $(INCLUDE) -o $(NAME)_bonus

$(NAME): $(OBJ) $(LIBFT_LIB) $(LIBMLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(LIBMLX_LIB) $(INCLUDE) -o $(NAME)

libft:
	make all -C $(LIBFT_DIR)

libmlx:
	make -C $(LIBMLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I . -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME) $(NAME)_bonus
	make clean -C $(LIBMLX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus libft libmlx