/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:27:40 by coder             #+#    #+#             */
/*   Updated: 2022/02/01 20:54:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_stc *stc, char *error)
{
	if (*error != 0)
		printf("Error\n%s\n", error);
	mlx_destroy_image(stc->game.mlx, stc->tile.floor);
	mlx_destroy_image(stc->game.mlx, stc->tile.wall);
	mlx_destroy_window(stc->game.mlx, stc->game.win);
	mlx_destroy_display(stc->game.mlx);
	free(stc->game.mlx);
	exit (1);
}
