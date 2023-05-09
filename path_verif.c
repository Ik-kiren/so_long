/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:08:42 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/09 15:04:21 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_point size, t_point cur, char to_fill)
{
	to_fill = '0';
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (map[cur.y][cur.x] != to_fill && map[cur.y][cur.x] != 'C'
		&& map[cur.y][cur.x] != 'E' && map[cur.y][cur.x] != 'P'))
		return ;
	map[cur.y][cur.x] = 'F';
	fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

t_point	find_in_map(t_map *map, char c)
{
	int		i;
	int		j;
	t_point	point;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->tab_map[i][j])
		{
			if (map->tab_map[i][j] == c)
			{
				point.x = j;
				point.y = i;
			}
			j++;
		}
		i++;
	}
	return (point);
}

void	flood_fill(char **map, t_point size, t_point begin)
{
	fill(map, size, begin, map[begin.y][begin.x]);
}

int	path_verif(t_map *map, t_point start, t_point end, t_point col)
{
	char	**tmp_map;
	int		i;
	int		valid;

	i = -1;
	tmp_map = malloc(sizeof(char *) * (map->height + 1));
	if (!tmp_map)
		return (0);
	while (++i <= map->height)
		tmp_map[i] = ft_strdup(map->tab_map[i]);
	start = find_in_map(map, 'P');
	end = find_in_map(map, 'E');
	col = find_in_map(map, 'C');
	flood_fill(tmp_map, (t_point){map->width, map->height}, start);
	valid = (tmp_map[end.y][end.x] == 'F' && tmp_map[col.y][col.x] == 'F');
	i = -1;
	while (++i <= map->height)
		free(tmp_map[i]);
	free(tmp_map);
	return (valid);
}
