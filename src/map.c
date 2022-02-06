/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 06:22:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_stc *stc, void *img, int x, int y)
{
	mlx_put_image_to_window(stc->game.mlx, stc->game.win,
		img, x * 32, y * 32);
}

int	draw(t_stc *stc, int x, int y)
{
	if (stc->cam.cam_m[y][x] == '0')
		put_img(stc, stc->tile.floor, x, y);
	else if (stc->cam.cam_m[y][x] == '1')
		put_img(stc, stc->tile.wall, x, y);
	else if (stc->cam.cam_m[y][x] == 'P')
		put_img(stc, stc->player.sprite, x, y);
	else if (stc->cam.cam_m[y][x] == 'E')
		put_img(stc, stc->tile.exit, x, y);
	else if (stc->cam.cam_m[y][x] == 'C')
		put_img(stc, stc->tile.colec, x, y);
	return (0);
}

int	draw_map(t_stc *stc)
{
	int	x;
	int	y;

	y = 0;
	while (y < stc->map.y / 2)
	{
		x = 0;
		while (x < stc->map.x / 2)
		{
			if (stc->game.c_count == 0)
			{
				mlx_destroy_image(stc->game.mlx, stc->tile.exit);
				exit_sprites(stc, 1);
			}
			draw(stc, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
