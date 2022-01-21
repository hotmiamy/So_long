/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/01/21 01:17:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_sprites(t_module *module)
{
	module->tile->floor = mlx_xpm_file_to_image(module->game->mlx,
			"./images/floor_tile.xpm", &module->cord->x, &module->cord->y);
	module->tile->wall = mlx_xpm_file_to_image(module->game->mlx,
			"./images/wall_tile.xpm", &module->cord->x, &module->cord->y);
}

char	**set_map(int map_fd, t_module *module)
{
	char	**buffer_tile;
	char	*line;

	line = ft_get_next_line(map_fd);
	module->cord->col = 0;
	while (line != 0)
	{
		free(line);
		module->cord->col++;
		line = ft_get_next_line(map_fd);
		if (line == 0)
			buffer_tile = ft_calloc(module->cord->col, sizeof(char *));
	}
	free(line);
	close(map_fd);
	map_fd = open ("./maps/map.ber", O_RDONLY);
	module->cord->col = 0;
	buffer_tile[module->cord->col] = ft_get_next_line(map_fd);
	while (buffer_tile[++module->cord->col] != 0)
		buffer_tile[module->cord->col] = ft_get_next_line(map_fd);
	return (buffer_tile);
}

void	draw_map(int map_fd, t_module *module)
{
	char		**map;

	map = set_map(map_fd, module);
	load_sprites(module);
	module->tile->y = 0;
	module->tile->x = 0;
	while (map[module->tile->y][module->tile->x] != 0)
	{
		while (map[module->tile->y][module->tile->x] != 0 &&
		map[module->tile->y][module->tile->x] != '\n')
		{
			if (map[module->tile->y][module->tile->x] == '0')
			{
				mlx_put_image_to_window(module->game->mlx, module->game->window,
					module->tile->floor, module->tile->x * 32,
					module->tile->y * 32);
			}
			else if (map[module->tile->y][module->tile->x] == '1')
			{
				mlx_put_image_to_window(module->game->mlx, module->game->window,
					module->tile->wall, module->tile->x * 32,
					module->tile->y * 32);
			}
			module->tile->x++;
		}
		module->tile->y++;
	}
	free(map);
}
