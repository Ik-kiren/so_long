/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:47:51 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/09 15:24:40 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_texture(t_texture *img_t)
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
	img_t->t_exit = mlx_load_png("./exit.png");
}

void	set_img(t_vars *vars, t_img *img, t_texture *img_t)
{
	img->player = mlx_texture_to_image(vars->mlx, img_t->t_player);
	img->floor = mlx_texture_to_image(vars->mlx, img_t->t_floor);
	img->wall_d = mlx_texture_to_image(vars->mlx, img_t->t_wall_d);
	img->wall_u = mlx_texture_to_image(vars->mlx, img_t->t_wall_u);
	img->wall_l = mlx_texture_to_image(vars->mlx, img_t->t_wall_l);
	img->wall_r = mlx_texture_to_image(vars->mlx, img_t->t_wall_r);
	img->corner_l_u = mlx_texture_to_image(vars->mlx, img_t->t_corner_l_u);
	img->corner_l_d = mlx_texture_to_image(vars->mlx, img_t->t_corner_l_d);
	img->corner_r_d = mlx_texture_to_image(vars->mlx, img_t->t_corner_r_d);
	img->corner_r_u = mlx_texture_to_image(vars->mlx, img_t->t_corner_r_u);
	img->collec = mlx_texture_to_image(vars->mlx, img_t->t_collec);
	img->exit = mlx_texture_to_image(vars->mlx, img_t->t_exit);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i <= map->height + 1)
		free(map->tab_map[i]);
	free(map->tab_map);
}

int	format_error()
{
	printf("format error\n");
	return (0);
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
	if (!fd)
		return (0);
	create_map(fd, &map);
	if (!map.tab_map)
	{
		format_error(&vars);
		return (0);
	}
	vars.mlx = mlx_init((map.width + 1) * 32, (map.height + 1) * 32, "s", true);
	set_texture(&img_t);
	set_img(&vars, &img, &img_t);
	mlx_key_hook(vars.mlx, &deplacement, &vars);
	map_to_img(&vars, &map);
	mlx_image_to_window(vars.mlx, img.player, vars.p_x, vars.p_y);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
}
