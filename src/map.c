/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/01/20 04:24:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**set_map(int map_fd)
{
	t_cord	cord;
	char	**buffer_tile;
	char	*line;

	line = ft_get_next_line(map_fd);
	cord.row = 0;
	while (line != 0)
	{
		free(line);
		cord.col++;
		line = ft_get_next_line(map_fd);
	}
	free(line);
	buffer_tile = ft_calloc(cord.row + 1, sizeof(char *));
	close(map_fd);
	map_fd = open ("./maps/map.ber", O_RDONLY);
	cord.row = 0;
	buffer_tile[cord.row] = ft_get_next_line(map_fd);
	while (buffer_tile[cord.row++] != 0)
		buffer_tile[cord.row] = ft_get_next_line(map_fd);
	return (buffer_tile);
}

void	draw_map(int map_fd, t_game *game)
{
	t_tile	tile;
	t_cord	cord;
	char	**map;

	map = set_map(map_fd);
	tile.floor = mlx_xpm_file_to_image(game->mlx, "./images/floor_tile.xpm",
			&cord.x, &cord.y);
	tile.wall = mlx_xpm_file_to_image(game->mlx, "./images/wall_tile.xpm",
			&cord.x, &cord.y);
	tile.y = 0;
	while (map[tile.y] != 0)
	{
		tile.x = 0;
		while (map[tile.y][tile.x] != '\n' && map[tile.y][tile.x] != '\0')
		{
			if (map[tile.y][tile.x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->window, tile.floor,
					tile.x * 16, tile.y * 16);
			}
			else if (map[tile.y][tile.x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->window, tile.wall,
					tile.x * 16, tile.y * 16);
			}
			tile.x++;
		}
		tile.y++;
	}
	mlx_destroy_image(game->mlx, tile.floor);
	mlx_destroy_image(game->mlx, tile.wall);
	free(map);
}
