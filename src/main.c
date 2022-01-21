/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/01/21 01:18:47 by coder            ###   ########.fr       */
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
	t_module	module;

	module.game->width = 800;
	module.game->height = 480;
	module.game->mlx = mlx_init();
	module.game->window = mlx_new_window(module.game->mlx,
			module.game->width, module.game->height, "teste");
	module.game->map = open ("./maps/map.ber", O_RDONLY);
	if (module.game->map < 0)
		return (0);
	draw_map(module.game->map, &module);
	mlx_key_hook(module.game->window, key_hook, (void *)0);
	mlx_destroy_image(module.game->mlx, module.tile->floor);
	mlx_destroy_image(module.game->mlx, module.tile->wall);
	mlx_destroy_window(module.game->mlx, module.game->window);
	mlx_destroy_display(module.game->mlx);
	free(module.game->mlx);
	close(module.game->map);
	mlx_loop(module.game->mlx);
	return (0);
}
