/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:06 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/04 14:06:57 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void collec_drop(t_vars *vars)
{
	if (vars->map->tab_map[vars->player_y / 32][vars->player_x / 32] == 'C')
	{
		vars->collectible = 1;
	}
}

void won_game(t_vars *vars)
{
	if (vars->map->tab_map[vars->player_y / 32][vars->player_x / 32] == 'E' && vars->collectible == 1)
	{
		free(vars->map->tab_map);
		mlx_terminate(vars->mlx);
	}
}

/*int deplacement(int keycode, t_vars *vars)
{
	//wasd = 13,0,1,2
	//U,L,D,R = 126,123,125,124
	if (keycode == 53) close_window(keycode, vars);
	if ((keycode == 0 || keycode == 123) && vars->player_x > 32)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x, vars->player_y);
		vars->player_x = vars->player_x - 32;
		printf("x = %d\n", vars->player_x);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if ((keycode == 1 || keycode == 125) && vars->player_y < vars->map->height * 32 - 48)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x, vars->player_y);
		vars->player_y = vars->player_y + 32;
		printf("y = %d\n", vars->player_y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if ((keycode == 2 || keycode == 124) && vars->player_x < vars->map->width * 32 - 48)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x, vars->player_y);
		vars->player_x = vars->player_x + 32;
		printf("x = %d\n", vars->player_x);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	else if ((keycode == 13 || keycode == 126) && vars->player_y > 32)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->tileset->floor, vars->player_x, vars->player_y);
		vars->player_y = vars->player_y - 32;
		printf("y = %d\n", vars->player_y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image_addr, vars->player_x, vars->player_y);
	}
	collec_drop(vars);
	won_game(vars);
	return (0);
}*/

void close_window(mlx_key_data_t keycode, t_vars *vars)
{
	free(vars->map->tab_map);
	mlx_terminate(vars->mlx);
}
