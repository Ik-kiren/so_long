/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:06 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/05 14:22:01 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collec_drop(t_vars *vars)
{
	if (vars->map->tab_map[vars->player_y / 32][vars->player_x / 32] == 'C')
	{
		vars->collectible = 1;
	}
}

void	won_game(t_vars *vars)
{
	if (vars->map->tab_map[vars->player_y / 32][vars->player_x / 32] == 'E' && vars->collectible == 1)
	{
		mlx_terminate(vars->mlx);
	}
}

void	deplacement(mlx_key_data_t keycode, t_vars *vars)
{
	//wasd = 13,0,1,2
	//U,L,D,R = 126,123,125,124
	if (((keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_LEFT) && keycode.action == MLX_RELEASE) && vars->map->tab_map[vars->player_y / 32][(vars->player_x - 32) / 32] != '1')
	{
		mlx_image_to_window(vars->mlx, vars->image->floor, vars->player_x, vars->player_y);
		vars->player_x = vars->player_x - 32;
		printf("x = %d\n", vars->player_x);
		mlx_image_to_window(vars->mlx, vars->image->player, vars->player_x, vars->player_y);
	}
	else if (((keycode.key == MLX_KEY_S || keycode.key == MLX_KEY_DOWN) && keycode.action == MLX_RELEASE) && vars->map->tab_map[(vars->player_y + 32) / 32][vars->player_x / 32] != '1')
	{
		mlx_image_to_window(vars->mlx, vars->image->floor, vars->player_x, vars->player_y);
		vars->player_y = vars->player_y + 32;
		printf("y = %d\n", vars->player_y);
		mlx_image_to_window(vars->mlx, vars->image->player, vars->player_x, vars->player_y);
	}
	else if (((keycode.key == MLX_KEY_D || keycode.key == MLX_KEY_RIGHT) && keycode.action == MLX_RELEASE) && vars->map->tab_map[vars->player_y / 32][(vars->player_x + 32) / 32] != '1')
	{
		mlx_image_to_window(vars->mlx, vars->image->floor, vars->player_x, vars->player_y);
		vars->player_x = vars->player_x + 32;
		printf("x = %d\n", vars->player_x);
		mlx_image_to_window(vars->mlx, vars->image->player, vars->player_x, vars->player_y);
	}
	else if (((keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_UP) && keycode.action == MLX_RELEASE) && vars->map->tab_map[(vars->player_y - 32) / 32][vars->player_x / 32] != '1')
	{
		mlx_image_to_window(vars->mlx, vars->image->floor, vars->player_x, vars->player_y);
		vars->player_y = vars->player_y - 32;
		printf("y = %d\n", vars->player_y);
		mlx_image_to_window(vars->mlx, vars->image->player, vars->player_x, vars->player_y);
	}
	else if (keycode.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(vars->mlx);
	}
	
	//collec_drop(vars);
	won_game(vars);
}
