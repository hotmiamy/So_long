/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:27:40 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 21:13:10 by coder            ###   ########.fr       */
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

int	exit_error(t_stc *stc, char *error)
{
	printf("Error\n%s\n", error);
	if (stc->game.map_load == 1)
	{
		free_map(stc->map.map);
		free_map(stc->cam.cam_m);
		mlx_destroy_image(stc->game.mlx, stc->tile.floor);
		mlx_destroy_image(stc->game.mlx, stc->tile.wall);
		mlx_destroy_image(stc->game.mlx, stc->tile.exit);
		mlx_destroy_image(stc->game.mlx, stc->tile.colec);
		mlx_destroy_image(stc->game.mlx, stc->player.sprite);
		mlx_destroy_window(stc->game.mlx, stc->game.win);
		mlx_destroy_display(stc->game.mlx);
		free(stc->game.mlx);
	}
	exit(0);
	return (0);
}

int	exit_game(t_stc *stc)
{
	if (stc->game.map_load == 1)
	{
		free_map(stc->map.map);
		free_map(stc->cam.cam_m);
		mlx_destroy_image(stc->game.mlx, stc->tile.floor);
		mlx_destroy_image(stc->game.mlx, stc->tile.wall);
		mlx_destroy_image(stc->game.mlx, stc->tile.exit);
		mlx_destroy_image(stc->game.mlx, stc->tile.colec);
		mlx_destroy_image(stc->game.mlx, stc->player.sprite);
		mlx_destroy_window(stc->game.mlx, stc->game.win);
		mlx_destroy_display(stc->game.mlx);
		free(stc->game.mlx);
	}
	exit (0);
	return (0);
}
