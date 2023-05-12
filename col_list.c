/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:01:22 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/12 12:27:08 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_list(t_col_point *first, int x, int y)
{
	first->x = x;
	first->y = y;
	first->next = NULL;
}

void	add_col(t_col_point *point, int x, int y)
{
	t_col_point	*new;

	new = malloc(sizeof(t_col_point));
	new->x = x;
	new->y = y;
	new->next = NULL;
	while (point->next != NULL)
	{
		point = point->next;
	}
	point->next = new;
}

int	search_c(char **tmp_map, t_col_point *list, t_map *map)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	l = 0;
	while (i < map->height + 1)
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (map->tab_map[i][j] == 'C')
			{
				if (l == 0)
					init_list(list, j, i);
				else
					add_col(list, j, i);
				l++;
			}
			j++;
		}
		i++;
	}
	map->cols = l;
	return (l);
}

int	col_path(char **tmp_map, t_map *map)
{
	t_col_point	*list;
	int			validate;
	int			col_nbr;

	list = malloc(sizeof(t_col_point));
	validate = 0;
	col_nbr = search_c(tmp_map, list, map);
	while (list != NULL)
	{
		ft_printf("p = %p\n", list);
		ft_printf("p = %p\n", list->next);
		if (tmp_map[list->y][list->x] == 'F')
		{
			validate++;
		}
		free(list);
		list = list->next;
	}
	if (col_nbr == validate)
		return (1);
	else
		return (0);
}
