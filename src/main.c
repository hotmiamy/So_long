/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/01/27 20:33:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_module *module)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(module->game.mlx, module->tile.floor);
		mlx_destroy_image(module->game.mlx, module->tile.wall);
		mlx_destroy_window(module->game.mlx, module->game.win);
		mlx_destroy_display(module->game.mlx);
		free(module->game.mlx);
		exit (1);
	}
	return (0);
}

int	main(void)
{
	t_module	module;
	t_map		map;

	mlx_key_hook(module.game.win, key_hook, (void *)0);
	load_game(&module, &map, "./maps/map.ber");
	draw_map(&module, &map);
	mlx_loop(module.game.mlx);
	return (0);
}
