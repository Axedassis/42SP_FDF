# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 18:35:55 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/05 15:11:49 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MANDATORY	= mandatory/bin/fdf
NAME_BONUS		= bonus/bin/fdf_bonus
CC				= cc
CFLAGS			= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
LDFLAGS			= -lm -lXext -lX11 -lXrandr

LIBMLX_DIR		= lib/minilibx-linux
LIBMLX_LIB		= $(LIBMLX_DIR)/libmlx_Linux.a

LIBFT_DIR		= lib/libft
LIBFT_LIB		= $(LIBFT_DIR)/libft.a

SRC				= mandatory/src/bresenham.c \
				  mandatory/src/color_functions.c \
				  mandatory/src/common_functions.c \
				  mandatory/src/init_functions.c \
				  mandatory/src/map_functions.c \
				  mandatory/src/mlx_functions.c \
				  mandatory/src/pts_functions.c \
				  mandatory/src/render_functions.c \
				  mandatory/src/model_render.c \
				  mandatory/src/file_format.c \
				  mandatory/src/main.c 

SRC_BONUS		= bonus/src/bresenham_bonus.c \
				  bonus/src/color_functions_bonus.c \
				  bonus/src/common_functions_bonus.c \
				  bonus/src/init_functions_bonus.c \
				  bonus/src/map_functions_bonus.c \
				  bonus/src/mlx_functions_bonus.c \
				  bonus/src/pts_functions_bonus.c \
				  bonus/src/render_functions_bonus.c \
				  bonus/src/model_render_bonus.c \
				  bonus/src/key_handler_bonus.c \
				  bonus/src/file_format_bonus.c \
				  bonus/src/rotate_bonus.c \
				  bonus/src/info_screen_bonus.c \
				  bonus/src/main_bonus.c 

OBJ				= $(patsubst mandatory/src/%.c, mandatory/build/%.o, $(SRC))
OBJ_BONUS		= $(patsubst bonus/src/%.c, bonus/build/%.o, $(SRC_BONUS))

all: libmlx libft $(NAME_MANDATORY)

bonus: libmlx libft $(NAME_BONUS)

$(NAME_MANDATORY): $(OBJ) $(LIBFT_LIB) $(LIBMLX_LIB)
	@mkdir -p mandatory/bin
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(LIBMLX_LIB) $(LDFLAGS) -o $@

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_LIB) $(LIBMLX_LIB)
	@mkdir -p bonus/bin
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_LIB) $(LIBMLX_LIB) $(LDFLAGS) -o $@

libft:
	@make all -C $(LIBFT_DIR)

libmlx:
	@make -C $(LIBMLX_DIR)

mandatory/build/%.o: mandatory/src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I mandatory/includes -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -c $< -o $@

bonus/build/%.o: bonus/src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I bonus/includes -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)

fclean: clean
	@rm -f $(NAME_MANDATORY) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus libft libmlx