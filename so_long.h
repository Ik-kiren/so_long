/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:30 by cdupuis           #+#    #+#             */
/*   Updated: 2023/04/28 13:07:30 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_map
{
	char	**tab_map;
	int		width;
	int		height;
}				t_map;

typedef struct s_img
{
	void	*floor;
	int		floor_w;
	int		floor_h;
	void	*wall;
	int		wall_w;
	int		wall_h;
	void	*wall_l;
	int		wall_l_w;
	int		wall_l_h;
	void	*wall_r;
	int		wall_r_w;
	int		wall_r_h;
	void	*corner_l_u;
	int		corner_l_u_w;
	int		corner_l_u_h;
	void	*corner_l_d;
	int		corner_l_d_w;
	int		corner_l_d_h;
	void	*corner_r_d;
	int		corner_r_d_w;
	int		corner_r_d_h;
	void	*corner_r_u;
	int		corner_r_u_w;
	int		corner_r_u_h;
	void	*collec;
	int		collec_w;
	int		collec_h;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*image_addr;
	int		player_x;
	int		player_y;
	int		image_width;
	int		image_height;
	int		collectible;
	t_img	*tileset;
	t_map	*map;
}				t_vars;

void	map_to_img(t_vars *vars, t_map *map, t_img *tileset);
char	**create_map(int fd, int *height, int *width);
int		deplacement(int keycode, t_vars *vars);
int		close_window(int keycode, t_vars *vars);

#endif