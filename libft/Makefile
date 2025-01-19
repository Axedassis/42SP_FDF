CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = ./build/
AR = ar rcs

SRC = $(wildcard ./src/**/*.c)

OBJ := $(SRC:./src/%.c=$(OBJ_DIR)%.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p lib
	$(AR) ./lib/$@ $(OBJ)

$(OBJ_DIR)%.o: ./src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./lib/$(NAME) ./lib ./build

re: fclean all

.PHONY: all clean fclean re bonus
