/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:50:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/01 07:51:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**load_map(char *path)
{
	int		map_fd;
	char	**map;
	char	*map_line_buff;
	char	*map_gnl_buff;
	char	*map_line;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		return (NULL);
	map_line = ft_strdup("");
	while (1)
	{
		map_gnl_buff = ft_get_next_line(map_fd);
		if (!map_gnl_buff)
			break ;
		map_line_buff = map_line;
		map_line = ft_strjoin(map_line_buff, map_gnl_buff);
		free(map_gnl_buff);
		free(map_line_buff);
	}
	map = ft_split(map_line, '\n');
	free(map_line);
	close(map_fd);
	return (map);
}

void	size_window(t_module *module, t_map *map)
{
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[0][map->x])
		{
			valid_chars(module, map, map->x, map->y);
			map->x++;
		}
		map->y++;
	}
	module->game.wdt = map->x * 32;
	module->game.hgt = map->y * 32;
}

void	load_sprites(t_module *module)
{
	module->tile.floor = mlx_xpm_file_to_image(module->game.mlx,
			"./images/floor_tile.xpm", &module->tile.wdt, &module->tile.hgt);
	module->tile.wall = mlx_xpm_file_to_image(module->game.mlx,
			"./images/wall_tile.xpm", &module->tile.wdt, &module->tile.hgt);
}

void	load_game(t_module *mdl, t_map *map, char *map_path)
{
	map->ch_p = 0;
	map->ch_e = 0;
	map->ch_0 = 0;
	mdl->game.c_count = 0;
	map->map = load_map(map_path);
	mdl->game.mlx = mlx_init();
	size_window(mdl, map);
	mdl->game.win = mlx_new_window(mdl->game.mlx, mdl->game.wdt,
			mdl->game.hgt, "So Long");
	load_sprites(mdl);
}
