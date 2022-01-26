/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/01/26 00:37:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_module *module, void *img)
{
	mlx_put_image_to_window(module->game.mlx, module->game.win,
		img, module->tile.x * 32, module->tile.y * 32);
}

void	draw_map(t_module *module)
{
	module->tile.y = 0;
	while (module->game.map[module->tile.y])
	{
		module->tile.x = 0;
		while (module->game.map[module->tile.y][module->tile.x])
		{
			if (module->game.map[module->tile.y][module->tile.x] == '0')
				put_img(module, module->tile.floor);
			else if (module->game.map[module->tile.y][module->tile.x] == '1')
				put_img(module, module->tile.wall);
			module->tile.x++;
		}
		module->tile.y++;
	}
}
