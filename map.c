/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:10 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/05 14:14:41 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_verif(char **map, int *height, int *width)
{
	int	i = 0;
	int	j = 0;
	int pce = 0;
	
	*width = ft_strlen(map[0]) - 2;
	while (i <= *height)
	{
		j = 0;
		while (j <= *width)
		{
			if (i == 0 && map[i][j] != '1' && map[i][j] != '\0') return (0);
			if (j == 0 && map[i][j] != '1') return (0);
			if (i == *height && map[i][j] != '1' && map[i][j] != '\0') return (0);
			if (j == *width && map[i][j] != '1') return (0);
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E') pce += 1;
			j++;
		}
		i++;
	}
	if (pce != 3) return (0);
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
	close(fd);
	return (map);
}

void map_to_img(t_vars *vars, t_map *map, t_texture *tileset)
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
				mlx_image_to_window(vars->mlx, vars->image->floor, j * 32, i * 32);
			}
			if (map->tab_map[i][j] == '1')
			{
				if (j == 0 && i == 0) mlx_image_to_window(vars->mlx, vars->image->corner_l_u, j * 32, i * 32);
				else if (j == map->width && i == 0) mlx_image_to_window(vars->mlx, vars->image->corner_r_u, j * 32, i * 32);
				else if (j == map->width && i == map->height) mlx_image_to_window(vars->mlx, vars->image->corner_r_d, j * 32, i * 32);
				else if (j == 0 && i == map->height) mlx_image_to_window(vars->mlx, vars->image->corner_l_d, j * 32, i * 32);
				else if (j == 0) mlx_image_to_window(vars->mlx, vars->image->wall_l, j * 32, i * 32);
				else if (j == map->width) mlx_image_to_window(vars->mlx, vars->image->wall_r, j * 32, i * 32);
				else if (i == 0) mlx_image_to_window(vars->mlx, vars->image->wall_u, j * 32, i * 32);
				else if (i == map->height)mlx_image_to_window(vars->mlx, vars->image->wall_d, j * 32, i * 32);
				else mlx_image_to_window(vars->mlx, vars->image->wall_d, j * 32, i * 32);
			}
			if (map->tab_map[i][j] == 'P')
			{
				vars->player_x = j * 32;
				vars->player_y = i * 32;
			}
			if (map->tab_map[i][j] == 'C')
			{
				mlx_image_to_window(vars->mlx, vars->image->collec, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}
