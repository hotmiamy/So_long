/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:27:40 by coder             #+#    #+#             */
/*   Updated: 2022/02/01 07:04:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_module *module, char *error)
{
	if (*error != 0)
		printf("Error\n%s\n", error);
	mlx_destroy_image(module->game.mlx, module->tile.floor);
	mlx_destroy_image(module->game.mlx, module->tile.wall);
	mlx_destroy_window(module->game.mlx, module->game.win);
	mlx_destroy_display(module->game.mlx);
	free(module->game.mlx);
	exit (1);
}
