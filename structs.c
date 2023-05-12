/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:30:32 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/12 12:25:49 by cdupuis          ###   ########.fr       */
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

void	set_structs(t_vars *vars, t_img *img, t_texture *img_t)
{
	set_texture(img_t);
	set_img(vars, img, img_t);
	vars->dplcmt = 0;
	ft_printf("deplacements = %d\n", vars->dplcmt);
}
