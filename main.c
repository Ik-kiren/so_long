#include "so_long.h"

typedef struct s_data
{
	void *img;
    void *addr;
    int bits_per_line;
    int line_length;
    int endian;
}               t_data;

typedef struct s_vars
{
	void *mlx;
	void *mlx_win;
	void *image_addr;
	int player_x;
	int player_y;
	int image_width;
	int image_height;
}				t_vars;

typedef struct s_map
{
	char **tab_map;
	int width;
	int height;
	void *wall_up;
	void *floor;
	int floor_h;
	int floor_w;

}				t_map;

int close_window(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		printf("%d\n", keycode);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	}
	return (0);
}

void erase(t_vars *vars)
{

}

int deplacement(int keycode, t_vars *vars)
{
	//wasd = 13,0,1,2
	//U,L,D,R = 126,123,125,124

	if (keycode == 0 || keycode == 123)
	{
		vars->player_x = vars->player_x - 32;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if (keycode == 1 || keycode == 125)
	{
		vars->player_y = vars->player_y + 32;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if (keycode == 2 || keycode == 124)
	{
		vars->player_x = vars->player_x + 32;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if (keycode == 13 || keycode == 126)
	{
		vars->player_y = vars->player_y - 32;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	return (0);
}

int map_rule(char c)
{
	//
	return (0);
}

int map_verif(char **map, int *height, int *width)
{
	int i = 0;
	int j = 0;
	
	*width = ft_strlen(map[0]) - 2;	
	//printf("height=%d width =%d\n", height, width);
	while (i <= *height)
	{
		j = 0;
		while (j <= *width)
		{
			//printf("i=%d j =%d\n", i, j);
			if(i == 0 && map[i][j] != '1' && map[i][j] != '\0') return (0);
			if(j == 0 && map[i][j] != '1') return (0);
			if(i == *height && map[i][j] != '1' && map[i][j] != '\0') return (0);
			if(j == *width && map[i][j] != '1') return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char **create_map(int fd, int *height, int *width)
{
	char **map = NULL;
	int i = 0;
	int j = 0;

	while (get_next_line(fd))
	{
		i++;
	}
	*height = i - 1;
	close(fd);
	fd = open("./map.ber", O_RDONLY);
	map = malloc(sizeof(char *) * i + 1);
	while (i > 0)
	{
		map[j] = ft_strdup(get_next_line(fd));
		printf("%s\n", map[j]);
		j++;
		i--;
	}
	map[j] = NULL;
	if (map_verif(map, height, width) == 0) return (NULL);
	return(map);
}

void map_to_img(t_vars *vars, t_map *map)
{
	int i = 0;
	int j = 0;

	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (map->tab_map[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, map->floor, i * 32, j * 32);
			}
			
			j++;
		}
		i++;
	}
	
}

int main(void)
{
    t_vars vars;
    t_data img;
	t_map map;
	int fd;

	
	fd = open("./map.ber", O_RDONLY);
	map.tab_map = create_map(fd, &map.height, &map.width);
	if (map.tab_map == NULL)
	{
		printf("format error\n");
	}
	vars.player_x = 0;
	vars.player_y = 0;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, map.width * 32, map.height * 32, "hello word");
    img.img = mlx_new_image(vars.mlx, map.width * 32, map.height * 32);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_line, &img.line_length, &img.endian);
	vars.image_addr = mlx_png_file_to_image(vars.mlx, "./player_down.png", &vars.image_width, &vars.image_height);
	map.floor = mlx_png_file_to_image(vars.mlx, "./floor.png", &map.floor_w, &map.floor_h);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.image_addr, vars.player_x, vars.player_y);
	mlx_key_hook(vars.mlx_win, close, &vars);
	mlx_key_hook(vars.mlx_win, deplacement, &vars);
	//map_to_img(&vars, &map);
	mlx_loop(vars.mlx);
}