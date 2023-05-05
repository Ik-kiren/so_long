/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:48:30 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/05 14:50:09 by cdupuis          ###   ########.fr       */
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
}				t_texture;


typedef struct s_vars
{
	void	*mlx;
	void	*image_addr;
	int		player_x;
	int		player_y;
	int		image_width;
	int		image_height;
	int		collectible;
	t_texture	*img_t;
	t_img		*img;
	t_map	*map;
}				t_vars;

void		map_to_img(t_vars *vars, t_map *map, t_texture *tileset);
char		**create_map(int fd, int *height, int *width);
void		deplacement(mlx_key_data_t keycode, t_vars *vars);

#endif