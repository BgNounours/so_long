NAME = so_long

BOLD_GREEN		= \033[32;01m
YELLOW			= \033[0;33m
RESET			= \033[0m

SRCS = src/
INCLUDE = include/
MLX_PATH = minilibx-linux/
MLX_LIB = libmlx_Linux.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext

FILES = set.c map.c end.c utils.c check_map.c render.c render_move.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c
OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

%.o: %.c
	@echo "$(YELLOW)Creating $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

mlx:
	make -sC $(MLX_PATH)
	
$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Compiling $@$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)
	@echo "$(BOLD_GREEN)Done!$(RESET)"

clean:
	@echo Removing objects
	@rm -rf $(OBJECTS)

fclean: clean
	@echo Removing $(NAME)
	@rm -rf $(NAME)

re: fclean all