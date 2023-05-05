/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:06 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/05 14:50:28 by cdupuis          ###   ########.fr       */
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
		free(vars->map->tab_map);
		mlx_close_window(vars->mlx);
	}
}

void	hooks(int keycode, t_vars *vars)
{
	if (keycode == 0)
	{
		mlx_image_to_window(vars->mlx, vars->img->floor, vars->player_x, vars->player_y);
		vars->player_x = vars->player_x - 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->player_x, vars->player_y);
	}
	else if (keycode == 1)
	{
		mlx_image_to_window(vars->mlx, vars->img->floor, vars->player_x, vars->player_y);
		vars->player_y = vars->player_y + 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->player_x, vars->player_y);
	}
	else if (keycode == 2)
	{
		mlx_image_to_window(vars->mlx, vars->img->floor, vars->player_x, vars->player_y);
		vars->player_x = vars->player_x + 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->player_x, vars->player_y);
	}
	else if (keycode == 3)
	{
		mlx_image_to_window(vars->mlx, vars->img->floor, vars->player_x, vars->player_y);
		vars->player_y = vars->player_y - 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->player_x, vars->player_y);
	}
}

void	deplacement(mlx_key_data_t keycode, void *param)
{
	t_vars *vars;
	vars = param;
	if (((keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_LEFT) && keycode.action == MLX_RELEASE) && vars->map->tab_map[vars->player_y / 32][(vars->player_x - 32) / 32] != '1')
	{
		hooks(0, vars);
	}
	else if (((keycode.key == MLX_KEY_S || keycode.key == MLX_KEY_DOWN) && keycode.action == MLX_RELEASE) && vars->map->tab_map[(vars->player_y + 32) / 32][vars->player_x / 32] != '1')
	{
		hooks(1, vars);
	}
	else if (((keycode.key == MLX_KEY_D || keycode.key == MLX_KEY_RIGHT) && keycode.action == MLX_RELEASE) && vars->map->tab_map[vars->player_y / 32][(vars->player_x + 32) / 32] != '1')
	{
		hooks(2, vars);
	}
	else if (((keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_UP) && keycode.action == MLX_RELEASE) && vars->map->tab_map[(vars->player_y - 32) / 32][vars->player_x / 32] != '1')
	{
		hooks(3, vars);
	}
	else if (keycode.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(vars->mlx);
	}
	collec_drop(vars);
	won_game(vars);
}
