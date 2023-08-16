/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:09:02 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/16 11:56:31 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_verif(char **map, int *h, int i, int j)
{
	int	width;
	int	tmp_width;
	int	tmp_height;

	tmp_height = ft_strlen_gnl(map[*h]);
	tmp_width = ft_strlen_gnl(map[i]) - 2;
	width = ft_strlen_gnl(map[0]) - 2;
	if (width != tmp_width && i != *h)
		return (0);
	if (i == *h && tmp_height != width + 2 && map[*h][width + 1] == '\n')
		return (0);
	if (i == *h && tmp_height != width + 1
		&& map[*h][width] == '1' && map[*h][width + 1] != '\n')
		return (0);
	if (i == 0 && map[i][j] != '1' && map[i][j] != '\0')
		return (0);
	else if (j == 0 && map[i][j] != '1')
		return (0);
	else if (i == *h && map[i][j] != '1' && map[i][j] != '\0')
		return (0);
	else if (j == width && map[i][j] != '1')
		return (0);
	else
		return (1);
}

int	map_verif(char **map, int *height, int *width)
{
	int	i;
	int	j;
	int	pce;

	i = 0;
	pce = 0;
	*width = ft_strlen_gnl(map[0]) - 2;
	while (i <= *height)
	{
		j = 0;
		while (j <= *width)
		{
			if (wall_verif(map, height, i, j) == 0)
				return (0);
			if (map[i][j] == 'P' || map[i][j] == 'E')
				pce += 1;
			j++;
		}
		i++;
	}
	if (pce != 2)
		return (0);
	return (1);
}

int	map_checks(t_map *map)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.x = 0;
	end.y = 0;
	if (map_verif(map->tab_map, &map->height, &map->width) == 0
		|| path_verif(map, start, end) == 0)
		return (0);
	return (1);
}
