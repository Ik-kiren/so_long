CC = gcc
CFlags = -Werror -Wall -Wextra
NAME = so_long
MLX = mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/cdupuis/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
SRCS = main.c map.c hook.c map_verif.c path_verif.c structs.c col_list.c
SRCSGNL = gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRCS:c=o)
OBJSGNL = $(SRCSGNL:c=o)

all: $(NAME)

linux: $(OBJS) $(OBJSGNL)
	make -C ft_printf
	$(CC) $(CFlags) $(OBJS) $(OBJSGNL) mlx/build/libmlx42.a ft_printf/libftprintf.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(NAME): $(OBJS)
	cmake ./mlx -B ./mlx/build
	cmake --build ./mlx/build -j4
	make -C ft_printf
	$(CC) $(CFlags) -fsanitize=address $(OBJS) gnl/get_next_line.c gnl/get_next_line_utils.c $(MLX) ft_printf/libftprintf.a -o $(NAME)

clean:
	rm -f so_long

fclean: clean
	make fclean -C ft_printf
	rm -f *.o

re: fclean all

.PHONY : all linux clean fclean re
