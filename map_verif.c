/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:09:02 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/09 13:11:25 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_verif(char **map, int *height, int i, int j)
{
	int	width;

	width = ft_strlen(map[0]) - 2;
	if (i == 0 && map[i][j] != '1' && map[i][j] != '\0')
		return (0);
	else if (j == 0 && map[i][j] != '1')
		return (0);
	else if (i == *height && map[i][j] != '1' && map[i][j] != '\0')
		return (0);
	else if (j == width && map[i][j] != '1')
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
	*width = ft_strlen(map[0]) - 2;
	while (i <= *height)
	{
		j = 0;
		while (j <= *width)
		{
			if (wall_verif(map, height, i, j) == 0)
				return (0);
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				pce += 1;
			j++;
		}
		i++;
	}
	printf("pce = %d\n", pce);
	if (pce != 3)
		return (0);
	return (1);
}

int	map_checks(t_map *map)
{
	t_point	start;
	t_point	end;
	t_point	col;

	if (map_verif(map->tab_map, &map->height, &map->width) == 0
		|| path_verif(map, start, end, col) == 0)
		return (0);
	return (1);
}
