/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:47:51 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/05 14:50:11 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_texture(t_vars *vars, t_texture *img_t)
{
	img_t->t_player = mlx_load_png("./player.png");
	img_t->t_floor = mlx_load_png("./floor.png");
	img_t->t_wall_u = mlx_load_png("./wall_up.png");
	img_t->t_wall_d = mlx_load_png("./wall_down.png");
	img_t->t_wall_l = mlx_load_png("./wall_left.png");
	img_t->t_wall_r = mlx_load_png("./wall_right.png");
	img_t->t_corner_l_u = mlx_load_png("./corner_l_u.png");
	img_t->t_corner_l_d = mlx_load_png("./corner_l_d.png");
	img_t->t_corner_r_d = mlx_load_png("./corner_r_d.png");
	img_t->t_corner_r_u = mlx_load_png("./corner_r_u.png");
	img_t->t_collec = mlx_load_png("./collec.png");
}

void	set_img(t_vars *vars, t_img *img, t_texture *img_t)
{
	img->player = mlx_texture_to_img(vars->mlx, img_t->t_player);
	img->floor = mlx_texture_to_img(vars->mlx, img_t->t_floor);
	img->wall_d = mlx_texture_to_img(vars->mlx, img_t->t_wall_d);
	img->wall_u = mlx_texture_to_img(vars->mlx, img_t->t_wall_u);
	img->wall_l = mlx_texture_to_img(vars->mlx, img_t->t_wall_l);
	img->wall_r = mlx_texture_to_img(vars->mlx, img_t->t_wall_r);
	img->corner_l_u = mlx_texture_to_img(vars->mlx, img_t->t_corner_l_u);
	img->corner_l_d = mlx_texture_to_img(vars->mlx, img_t->t_corner_l_d);
	img->corner_r_d = mlx_texture_to_img(vars->mlx, img_t->t_corner_r_d);
	img->corner_r_u = mlx_texture_to_img(vars->mlx, img_t->t_corner_r_u);
	img->collec = mlx_texture_to_img(vars->mlx, img_t->t_collec);
}

int	main(void)
{
	t_vars		vars;
	t_map		map;
	t_texture	img_t;
	t_img		img;
	int			fd;

	vars.img_t = &img_t;
	vars.img = &img;
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
		free(map.tab_map);
		mlx_terminate(vars.mlx);
		return(0);
	}
	vars.mlx = mlx_init((map.width + 1) * 32, (map.height + 1) * 32, "hello word", true);
	set_texture(&vars, &img_t);
	set_img(&vars, &img, &img_t);
	mlx_key_hook(vars.mlx, &deplacement, &vars);
	map_to_img(&vars, &map, &img_t);
	mlx_img_to_window(vars.mlx, img.player, vars.player_x, vars.player_y);
	mlx_loop(vars.mlx);
}
