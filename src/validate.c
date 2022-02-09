/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:31:54 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 17:21:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_chars(t_stc *stc, int x, int y)
{
	if (stc->map.map[y][x] == 'P')
	{
		stc->player.x = x;
		stc->player.y = y;
		stc->map.ch_p = 1;
	}
	else if (stc->map.map[y][x] == 'E')
		stc->map.ch_e = 1;
	else if (stc->map.map[y][x] == 'C')
		stc->game.c_count += 1;
	else if (stc->map.map[y][x] != '1' && stc->map.map[y][x] != '0')
		exit_error(stc, "invalid char on map");
	return (1);
}

int	is_valid(t_stc *stc)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	if (stc->map.x == stc->map.y)
		exit_error(stc, "The map is not a rectangle");
	if (stc->map.ch_p != 1 || stc->map.ch_e != 1 || stc->game.c_count == 0)
		exit_error(stc, "Is missing some char on the map");
	while (stc->map.x > x)
	{
		if (stc->map.map[0][x] != '1' || stc->map.map[stc->map.y - 1][x] != '1')
			exit_error(stc, "Missing walls, first or last line of map");
		x++;
	}
	while (stc->map.y > y)
	{
		if (ft_strlen(stc->map.map[y]) != (unsigned int)stc->map.x)
			exit_error(stc, "the lines on the map have different lengths");
		if (stc->map.map[y][0] != '1' || stc->map.map[y][stc->map.x - 1] != '1')
			exit_error(stc, "Missing wall, first or last column of map");
		y++;
	}
	return (1);
}

void	validate_map(t_stc *stc, char *str)
{
	if (ft_strnstr(str, "\n\n", ft_strlen(str)))
	{
		exit_error(stc, "map is invalid");
	}
}
