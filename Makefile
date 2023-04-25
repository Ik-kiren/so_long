CC = gcc
CFlags = -Werror -Wall -Werror
NAME = so_long
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): main.c
	$(CC) $(CFlags) main.c gnl/get_next_line.c gnl/get_next_line_utils.c  $(MLX) -o $(NAME)

clean:
	rm so_long

.PHONY : all
