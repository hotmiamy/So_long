/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/02/03 04:53:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_stc *stc)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(stc->game.mlx, stc->tile.floor);
		mlx_destroy_image(stc->game.mlx, stc->tile.wall);
		mlx_destroy_window(stc->game.mlx, stc->game.win);
		mlx_destroy_display(stc->game.mlx);
		free(stc->game.mlx);
		exit (1);
	}
	return (0);
}

int	main(void)
{
	t_stc	stc;

	load_game(&stc, "./maps/map.ber");
	if (is_valid(&stc) == 1)
	{
		draw_map(&stc);
		mlx_loop(stc.game.mlx);
	}
	else
		exit_game(&stc, "map is invalid");
	return (0);
}
