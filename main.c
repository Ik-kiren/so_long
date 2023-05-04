/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:47:51 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/01 14:59:57 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_struct(t_vars *vars, t_img *tileset)
{
	vars->image_addr = mlx_xpm_file_to_image(vars->mlx, "./player_down.xpm", &vars->image_width, &vars->image_height);
	tileset->floor = mlx_xpm_file_to_image(vars->mlx, "./floor_sprite.xpm", &tileset->floor_w, &tileset->floor_h);
	tileset->wall = mlx_xpm_file_to_image(vars->mlx, "./wall_up.xpm", &tileset->wall_w, &tileset->wall_h);
	tileset->wall_l = mlx_xpm_file_to_image(vars->mlx, "./wall_left.xpm", &tileset->wall_l_w, &tileset->wall_l_h);
	tileset->wall_r = mlx_xpm_file_to_image(vars->mlx, "./wall_right.xpm", &tileset->wall_r_w, &tileset->wall_r_h);
	tileset->collec = mlx_xpm_file_to_image(vars->mlx, "./collec.xpm", &tileset->collec_w, &tileset->collec_h);
	tileset->corner_l_d = mlx_xpm_file_to_image(vars->mlx, "./corner_left_down.xpm", &tileset->corner_l_d_w, &tileset->corner_l_d_h);
	tileset->corner_l_u = mlx_xpm_file_to_image(vars->mlx, "./corner_left_up.xpm", &tileset->corner_l_u_w, &tileset->corner_l_u_h);
	tileset->corner_r_d = mlx_xpm_file_to_image(vars->mlx, "./corner_right_down.xpm", &tileset->corner_r_d_w, &tileset->corner_r_d_h);
	tileset->corner_r_u = mlx_xpm_file_to_image(vars->mlx, "./corner_right_up.xpm", &tileset->corner_r_u_w, &tileset->corner_r_u_h);
}

int	main(void)
{
	t_vars	vars;
	t_map	map;
	t_img	tileset;
	int		fd;

	vars.tileset = &tileset;
	vars.map = &map;
	fd = open("./map.ber", O_RDONLY);
	map.tab_map = create_map(fd, &map.height, &map.width);
	if (map.tab_map == NULL)
	{
		printf("format error\n");
	}
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, ((map.width + 1) * 32) -1, ((map.height + 1) * 32) - 1 , "hello word");
	set_struct(&vars, &tileset);
	mlx_key_hook(vars.mlx_win, close_window, &vars);
	mlx_key_hook(vars.mlx_win, deplacement, &vars);
	map_to_img(&vars, &map, &tileset);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.image_addr, vars.player_x, vars.player_y);
	mlx_loop(vars.mlx);
}
