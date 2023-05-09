/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:30 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/09 13:09:24 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/include/MLX42/MLX42.h"
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
	mlx_image_t		*player;
	mlx_image_t		*floor;
	mlx_image_t		*wall_d;
	mlx_image_t		*wall_u;
	mlx_image_t		*wall_l;
	mlx_image_t		*wall_r;
	mlx_image_t		*corner_l_u;
	mlx_image_t		*corner_l_d;
	mlx_image_t		*corner_r_d;
	mlx_image_t		*corner_r_u;
	mlx_image_t		*collec;
	mlx_image_t		*exit;
}				t_img;

typedef struct s_texture
{
	mlx_texture_t	*t_player;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t_wall_u;
	mlx_texture_t	*t_wall_d;
	mlx_texture_t	*t_wall_l;
	mlx_texture_t	*t_wall_r;
	mlx_texture_t	*t_corner_l_u;
	mlx_texture_t	*t_corner_l_d;
	mlx_texture_t	*t_corner_r_d;
	mlx_texture_t	*t_corner_r_u;
	mlx_texture_t	*t_collec;
	mlx_texture_t	*t_exit;
}				t_texture;

typedef struct s_vars
{
	void		*mlx;
	void		*image_addr;
	int			p_x;
	int			p_y;
	int			image_width;
	int			image_height;
	int			collectible;
	t_texture	*img_t;
	t_img		*img;
	t_map		*map;
}				t_vars;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

void		map_to_img(t_vars *vars, t_map *map);
void		create_map(int fd, t_map *map);
void		deplacement(mlx_key_data_t keycode, void *param);
int			map_checks(t_map *map);
int			path_verif(t_map *map, t_point start, t_point end, t_point col);

#endif