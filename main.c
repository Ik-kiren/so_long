#include "so_long.h"

typedef struct s_map
{
	char **tab_map;
	int width;
	int height;
}				t_map;

typedef struct s_img
{
	void *floor;
	int floor_w;
	int floor_h;
	void *wall;
	int wall_w;
	int wall_h;
	void *wall_l;
	int wall_l_w;
	int wall_l_h;
	void *wall_r;
	int wall_r_w;
	int wall_r_h;
	void *collec;
	int collec_w;
	int collec_h;
}				t_img;

typedef struct s_vars
{
	void *mlx;
	void *mlx_win;
	void *image_addr;
	int player_x;
	int player_y;
	int image_width;
	int image_height;
	t_img *tileset;
	t_map *map;
}				t_vars;

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

int deplacement(int keycode, t_vars *vars)
{
	//wasd = 13,0,1,2
	//U,L,D,R = 126,123,125,124

	if ((keycode == 0 || keycode == 123) && vars->player_x > 16)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x + 16, vars->player_y + 16);
		vars->player_x = vars->player_x - 32;
		printf("x = %d\n", vars->player_x);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if ((keycode == 1 || keycode == 125) && vars->player_y < vars->map->height * 32 - 48)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x + 16, vars->player_y + 16);
		vars->player_y = vars->player_y + 32;
		printf("y = %d\n", vars->player_y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if ((keycode == 2 || keycode == 124) && vars->player_x < vars->map->width * 32 - 48)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x + 16, vars->player_y + 16);
		vars->player_x = vars->player_x + 32;
		printf("x = %d\n", vars->player_x);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if ((keycode == 13 || keycode == 126) && vars->player_y > 16)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x + 16, vars->player_y + 16);
		vars->player_y = vars->player_y - 32;
		printf("y = %d\n", vars->player_y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	return (0);
}

int map_verif(char **map, int *height, int *width)
{
	int i = 0;
	int j = 0;
	
	*width = ft_strlen(map[0]) - 2;	
	while (i <= *height)
	{
		j = 0;
		while (j <= *width)
		{
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

void map_to_img(t_vars *vars, t_map *map, t_img *tileset)
{
	int i = 0;
	int j = 0;

	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (map->tab_map[i][j] == '0' || map->tab_map[i][j] == 'P' || map->tab_map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, tileset->floor, j * 32, i * 32);
			}
			if (map->tab_map[i][j] == '1')
			{
				if (j == 0) mlx_put_image_to_window(vars->mlx, vars->mlx_win, tileset->wall_l, j * 32, i * 32);
				else if (j == map->width) mlx_put_image_to_window(vars->mlx, vars->mlx_win, tileset->wall_r, j * 32, i * 32);
				else mlx_put_image_to_window(vars->mlx, vars->mlx_win, tileset->wall, j * 32, i * 32);
			}
			if (map->tab_map[i][j] == 'P')
			{
				vars->player_x = (j - 1) * 32 + 16;
				vars->player_y = (i - 1) * 32 + 16;
			}
			if (map->tab_map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, tileset->collec, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
    t_vars vars;
	t_map map;
	t_img tileset;
	int fd;

	vars.tileset = &tileset;
	vars.map = &map;
	fd = open("./map.ber", O_RDONLY);
	map.tab_map = create_map(fd, &map.height, &map.width);
	if (map.tab_map == NULL)
	{
		printf("format error\n");
	}
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, (map.width + 1) * 32, (map.height + 1) * 32, "hello word");
	vars.image_addr = mlx_png_file_to_image(vars.mlx, "./player_down.png", &vars.image_width, &vars.image_height);
	tileset.floor = mlx_xpm_file_to_image(vars.mlx, "./floor_sprite.xpm", &tileset.floor_w, &tileset.floor_h);
	tileset.wall = mlx_xpm_file_to_image(vars.mlx, "./wall_up.xpm", &tileset.wall_w, &tileset.wall_h);
	tileset.wall_l = mlx_xpm_file_to_image(vars.mlx, "./wall_left.xpm", &tileset.wall_l_w, &tileset.wall_l_h);
	tileset.wall_r = mlx_xpm_file_to_image(vars.mlx, "./wall_right.xpm", &tileset.wall_r_w, &tileset.wall_r_h);
	tileset.collec = mlx_xpm_file_to_image(vars.mlx, "./collec.xpm", &tileset.collec_w, &tileset.collec_h);
	mlx_key_hook(vars.mlx_win, close, &vars);
	mlx_key_hook(vars.mlx_win, deplacement, &vars);
	map_to_img(&vars, &map, &tileset);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.image_addr, vars.player_x, vars.player_y);
	printf("x = %d\n", vars.player_x);
	printf("y = %d\n", vars.player_y);
	mlx_loop(vars.mlx);
}
