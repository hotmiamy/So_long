/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/01/07 01:53:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	game.width = 800;
	game.height = 480;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.width, game.height,
			"teste");
	mlx_key_hook(game.window, key_hook, (void *)0);
	mlx_loop(game.mlx);
}
