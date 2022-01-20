/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/01/20 00:29:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, char *str)
{
	printf("%s\n", str);
	printf("%i\n", key);
	if (key == XK_Escape)
		exit (1);
	return (0);
}

int	main(void)
{
	t_game	game;
	t_tile	*tile;
	t_cord	cord;

	game.width = 800;
	game.height = 480;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.width, game.height,
			"teste");
	game.map = open ("./maps/map.ber", O_RDONLY);
	if (game.map < 0)
		return (0);
	draw_map(game.map, &game);
	mlx_key_hook(game.window, key_hook, (void *)0);
	mlx_loop(game.mlx);
	close(game.map);
	return (0);
}
