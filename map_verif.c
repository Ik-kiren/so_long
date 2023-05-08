/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:09:02 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/08 14:18:55 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tab_verif(char **map, int *height, int i, int j)
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

void path_verif(t_map *map)
{
	int i;
	int j;

	while (map->tab_map[i][j])
	{
		while (j > 0 || j < map->width)
		{
			
		}
		
		i++;
	}
	
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
			if (tab_verif(map, height, i, j) == 0)
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
