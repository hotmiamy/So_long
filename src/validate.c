/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:31:54 by coder             #+#    #+#             */
/*   Updated: 2022/01/27 20:40:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid(t_map *map)
{
	int	x;
	int	y;
	int	is_wall;

	x = 0;
	y = 0;
	is_wall = 0;
	while (map->map[0][x] == '1' && map->map[y][0] == '1'
	&& map->map[y][map->x] == '1' && map->map[map->y][x] == '1')
	{
		x++;
		y++;
	}
	if (x == map->x && y == map->y)
		is_wall = 1;
	if (is_wall == 1)
		return (1);
	return (0);
}
