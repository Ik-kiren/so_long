/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:47:51 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/04 15:40:31 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_texture(t_vars *vars, t_texture *tileset)
{
	tileset->t_player = mlx_load_png("./player.png");
	tileset->t_floor = mlx_load_png("./floor.png");
	tileset->t_wall = mlx_load_png("./wall_up.png");
	tileset->t_wall_l = mlx_load_png("./wall_left.png");
	tileset->t_wall_r = mlx_load_png("./wall_right.png");
	tileset->t_corner_l_u = mlx_load_png("./corner_l_u.png");
	tileset->t_corner_l_d = mlx_load_png("./corner_l_d.png");
	tileset->t_corner_r_d = mlx_load_png("./corner_r_d.png");
	tileset->t_corner_r_u = mlx_load_png("./corner_r_u.png");
	tileset->t_collec = mlx_load_png("./collec.png");
}

void set_image(t_vars *vars, t_img *image, t_texture *tileset)
{
	image->player = mlx_texture_to_image(vars->mlx, tileset->t_player);
	image->floor = mlx_texture_to_image(vars->mlx, tileset->t_floor);
	image->wall = mlx_texture_to_image(vars->mlx, tileset->t_wall);
	image->wall_l = mlx_texture_to_image(vars->mlx, tileset->t_wall_l);
	image->wall_r = mlx_texture_to_image(vars->mlx, tileset->t_wall_r);
	image->corner_l_u = mlx_texture_to_image(vars->mlx, tileset->t_corner_l_u);
	image->corner_l_d = mlx_texture_to_image(vars->mlx, tileset->t_corner_l_d);
	image->corner_r_d = mlx_texture_to_image(vars->mlx, tileset->t_corner_r_d);
	image->corner_r_u = mlx_texture_to_image(vars->mlx, tileset->t_corner_r_u);
	image->collec = mlx_texture_to_image(vars->mlx, tileset->t_collec);
}

int	main(void)
{
	t_vars		vars;
	t_map		map;
	t_texture	tileset;
	t_img		image;
	int			fd;

	vars.tileset = &tileset;
	vars.image = &image;
	vars.map = &map;
	fd = open("./map.ber", O_RDONLY);
	if(!fd)
	{
		printf("fd error\n");
		return(0);
	}
	map.tab_map = create_map(fd, &map.height, &map.width);
	if (map.tab_map == NULL)
	{
		printf("format error\n");
		return(0);
	}
	vars.mlx = mlx_init((map.width + 1) * 32, (map.height + 1) * 32, "hello word", true);
	set_texture(&vars, &tileset);
	set_image(&vars, &image, &tileset);
	//mlx_key_hook(vars.mlx, &close_window, &vars);
	//mlx_key_hook(vars.mlx, &deplacement, &vars);
	map_to_img(&vars, &map, &tileset);
	mlx_image_to_window(vars.mlx, image.player, vars.player_x, vars.player_y);
	mlx_loop(vars.mlx);
}
