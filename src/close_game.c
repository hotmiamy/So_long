/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:27:40 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 20:48:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	inx;

	inx = 0;
	while (map[inx])
	{
		free(map[inx]);
		inx++;
	}
	free(map);
}

void	exit_game(t_stc *stc, char *error)
{
	if (*error != 0)
		printf("Error\n%s\n", error);
	free_map(stc->map.map);
	mlx_destroy_image(stc->game.mlx, stc->tile.floor);
	mlx_destroy_image(stc->game.mlx, stc->tile.wall);
	mlx_destroy_image(stc->game.mlx, stc->tile.exit);
	mlx_destroy_image(stc->game.mlx, stc->tile.colec);
	mlx_destroy_image(stc->game.mlx, stc->player.sprite);
	mlx_destroy_window(stc->game.mlx, stc->game.win);
	mlx_destroy_display(stc->game.mlx);
	free(stc->game.mlx);
	exit (1);
}
