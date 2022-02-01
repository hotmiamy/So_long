/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/02/01 07:27:34 by coder            ###   ########.fr       */
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

	load_game(&module, &map, "./maps/map.ber");
	if (is_valid(&module, &map) == 1)
	{
		draw_map(&module, &map);
		mlx_loop(module.game.mlx);
	}
	else
		exit_game(&module, "map is invalid");
	return (0);
}
