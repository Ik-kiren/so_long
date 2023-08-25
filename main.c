/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:47:51 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/18 14:28:12 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, t_texture *text)
{
	int	i;

	i = -1;
	while (++i <= map->height + 1)
		free(map->tab_map[i]);
	free(map->tab_map);
	if (text != NULL)
	{
		free(text->t_collec);
		free(text->t_corner_l_d);
		free(text->t_corner_l_u);
		free(text->t_corner_r_d);
		free(text->t_corner_r_u);
		free(text->t_exit);
		free(text->t_floor);
		free(text->t_player);
		free(text->t_wall_d);
		free(text->t_wall_l);
		free(text->t_wall_r);
		free(text->t_wall_u);
	}
}

int	format_error(void)
{
	ft_printf("Error\nWrong map format\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		map;
	t_texture	img_t;
	t_img		img;
	int			fd;

	if (argc != 2)
		return (0);
	vars.img_t = &img_t;
	vars.img = &img;
	vars.map = &map;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	create_map(fd, &map, argv[1]);
	if (!map.tab_map)
		return (format_error());
	vars.mlx = mlx_init((map.width + 1) * 32, (map.height + 1) * 32, "s", true);
	set_structs(&vars, &img, &img_t);
	mlx_key_hook(vars.mlx, &deplacement, &vars);
	map_to_img(&vars, &map);
	mlx_image_to_window(vars.mlx, img.player, vars.p_x, vars.p_y);
	mlx_loop(vars.mlx);
	free_map(&map, &img_t);
	mlx_terminate(vars.mlx);
}
