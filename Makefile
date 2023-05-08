CC = gcc
CFlags = -Werror -Wall -Wextra
NAME = so_long
MLX = mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/cdupuis/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
SRCS = main.c map.c hook.c map_verif.c
OBJS = $(SRCS:c=o)

all: $(NAME)

linux:
	$(CC) $(CFlags) $(SRCS) gnl/get_next_line.c gnl/get_next_line_utils.c mlx/build/libmlx42.a  -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFlags) $(OBJS) gnl/get_next_line.c gnl/get_next_line_utils.c $(MLX) -o $(NAME)

clean:
	rm so_long

.PHONY : all linux
