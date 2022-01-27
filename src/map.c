/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/01/27 20:44:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_module *module, void *img, int x, int y)
{
	mlx_put_image_to_window(module->game.mlx, module->game.win,
		img, x * 32, y * 32);
}

void	draw_map(t_module *module, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
				put_img(module, module->tile.floor, x, y);
			else if (map->map[y][x] == '1')
				put_img(module, module->tile.wall, x, y);
			x++;
		}
		y++;
	}
}
