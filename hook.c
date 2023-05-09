/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:06 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/09 12:52:16 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collec_drop(t_vars *vars)
{
	if (vars->map->tab_map[vars->p_y / 32][vars->p_x / 32] == 'C')
	{
		vars->collectible = 1;
	}
}

void	won_game(t_vars *vars)
{
	if (vars->map->tab_map[vars->p_y / 32][vars->p_x / 32] == 'E'
		&& vars->collectible == 1)
	{
		free(vars->map->tab_map);
		mlx_close_window(vars->mlx);
	}
}

void	img_deplacement(t_vars *vars)
{
	mlx_image_to_window(vars->mlx, vars->img->floor, vars->p_x, vars->p_y);
	if (vars->map->tab_map[vars->p_y / 32][vars->p_x / 32] == 'E')
		mlx_image_to_window(vars->mlx, vars->img->exit, vars->p_x, vars->p_y);
}

void	hooks(int keycode, t_vars *vars)
{
	if (keycode == 0)
	{
		img_deplacement(vars);
		vars->p_x = vars->p_x - 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->p_x, vars->p_y);
	}
	else if (keycode == 1)
	{
		img_deplacement(vars);
		vars->p_y = vars->p_y + 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->p_x, vars->p_y);
	}
	else if (keycode == 2)
	{
		img_deplacement(vars);
		vars->p_x = vars->p_x + 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->p_x, vars->p_y);
	}
	else if (keycode == 3)
	{
		img_deplacement(vars);
		vars->p_y = vars->p_y - 32;
		mlx_image_to_window(vars->mlx, vars->img->player, vars->p_x, vars->p_y);
	}
}

void	deplacement(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	vars = param;
	if (((keycode.key == 65 || keycode.key == 263) && keycode.action == 0)
		&& vars->map->tab_map[vars->p_y / 32][(vars->p_x - 32) / 32] != '1')
		hooks(0, vars);
	else if (((keycode.key == 83 || keycode.key == 264) && keycode.action == 0)
		&& vars->map->tab_map[(vars->p_y + 32) / 32][vars->p_x / 32] != '1')
		hooks(1, vars);
	else if (((keycode.key == 68 || keycode.key == 262) && keycode.action == 0)
		&& vars->map->tab_map[vars->p_y / 32][(vars->p_x + 32) / 32] != '1')
		hooks(2, vars);
	else if (((keycode.key == 87 || keycode.key == 265) && keycode.action == 0)
		&& vars->map->tab_map[(vars->p_y - 32) / 32][vars->p_x / 32] != '1')
		hooks(3, vars);
	else if (keycode.key == MLX_KEY_ESCAPE)
		mlx_close_window(vars->mlx);
	collec_drop(vars);
	won_game(vars);
}
