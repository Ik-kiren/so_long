/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:10 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/08 13:32:52 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(int fd, int *height, int *width)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (get_next_line(fd))
		i++;
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
	if (map_verif(map, height, width) == 0)
		return (NULL);
	close(fd);
	return (map);
}

void	walls_img(t_vars *vars, t_map *map, int i, int j)
{
	if (j == 0 && i == 0)
		mlx_image_to_window(vars->mlx, vars->img->corner_l_u, j * 32, i * 32);
	else if (j == map->width && i == 0)
		mlx_image_to_window(vars->mlx, vars->img->corner_r_u, j * 32, i * 32);
	else if (j == map->width && i == map->height)
		mlx_image_to_window(vars->mlx, vars->img->corner_r_d, j * 32, i * 32);
	else if (j == 0 && i == map->height)
		mlx_image_to_window(vars->mlx, vars->img->corner_l_d, j * 32, i * 32);
	else if (j == 0)
		mlx_image_to_window(vars->mlx, vars->img->wall_l, j * 32, i * 32);
	else if (j == map->width)
		mlx_image_to_window(vars->mlx, vars->img->wall_r, j * 32, i * 32);
	else if (i == 0)
		mlx_image_to_window(vars->mlx, vars->img->wall_u, j * 32, i * 32);
	else if (i == map->height)
		mlx_image_to_window(vars->mlx, vars->img->wall_d, j * 32, i * 32);
	else
		mlx_image_to_window(vars->mlx, vars->img->wall_d, j * 32, i * 32);
}

void	parse_map(t_vars *vars, t_map *map, int i, int j)
{
	if (map->tab_map[i][j] == '0' || map->tab_map[i][j] == 'P'
		|| map->tab_map[i][j] == 'C' || map->tab_map[i][j] == 'E')
		mlx_image_to_window(vars->mlx, vars->img->floor, j * 32, i * 32);
	if (map->tab_map[i][j] == '1')
		walls_img(vars, map, i, j);
	if (map->tab_map[i][j] == 'P')
	{
		vars->p_x = j * 32;
		vars->p_y = i * 32;
	}
	if (map->tab_map[i][j] == 'C')
		mlx_image_to_window(vars->mlx, vars->img->collec, j * 32, i * 32);
	if (map->tab_map[i][j] == 'E')
		mlx_image_to_window(vars->mlx, vars->img->exit, j * 32, i * 32);
}

void	map_to_img(t_vars *vars, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			parse_map(vars, map, i, j);
			j++;
		}
		i++;
	}
}
