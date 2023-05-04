CC = gcc
CFlags = -Werror -Wall -Werror 
NAME = so_long
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = main.c map.c hook.c
OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFlags) $(OBJS) gnl/get_next_line.c gnl/get_next_line_utils.c $(MLX) -o $(NAME)


clean:
	rm so_long

.PHONY : all
