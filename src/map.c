/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/02/03 06:12:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_stc *stc, void *img, int x, int y)
{
	mlx_put_image_to_window(stc->game.mlx, stc->game.win,
		img, x * 32, y * 32);
}

void	draw_map(t_stc *stc)
{
	int	x;
	int	y;

	y = 0;
	while (y < stc->map.y)
	{
		x = 0;
		while (x < stc->map.x)
		{
			if (stc->map.map[y][x] == '0')
				put_img(stc, stc->tile.floor, x, y);
			else if (stc->map.map[y][x] == '1')
				put_img(stc, stc->tile.wall, x, y);
			else if (stc->map.map[y][x] == 'P')
				put_img(stc, stc->player.sprite, x, y);
			else if (stc->map.map[y][x] == 'E')
				put_img(stc, stc->tile.exit, x, y);
			else if (stc->map.map[y][x] == 'C')
				put_img(stc, stc->tile.colec, x, y);
			x++;
		}
		y++;
	}
}
