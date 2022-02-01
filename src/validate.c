/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:31:54 by coder             #+#    #+#             */
/*   Updated: 2022/02/01 07:44:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_chars(t_module *module, t_map *map, int x, int y)
{
	if (map->map[y][x] == 'P')
		map->ch_p = 1;
	else if (map->map[y][x] == 'E')
		map->ch_e = 1;
	else if (map->map[y][x] == 'C')
		module->game.c_count += 1;
	else if (map->map[y][x] == '0')
		map->ch_0 = 1;
	else if (map->map[y][x] != '1')
		exit_game(module, "invalid char on map");
	return (1);
}

int	is_valid(t_module *module, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	if (map->x == map->y)
		exit_game(module, "The map is not a rectangle");
	if (map->ch_p != 1 || map->ch_e != 1 || map->ch_0 != 1
		|| module->game.c_count == 0)
		exit_game(module, "Is missing some char on the map");
	while (map->x > x)
	{
		if (map->map[0][x] != '1' || map->map[map->y - 1][x] != '1')
			exit_game(module, "Missing walls, first or last line of map");
		x++;
	}
	while (map->y > y)
	{
		if (ft_strlen(map->map[y]) != (unsigned int)map->x)
			exit_game(module, "map lines have different sizes");
		if (map->map[y][0] != '1' || map->map[y][map->x - 1] != '1')
			exit_game(module, "Missing wall, first or last column of map");
		y++;
	}
	return (1);
}
