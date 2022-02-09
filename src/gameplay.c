/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:46:04 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 17:37:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_stc *stc)
{
	if (key == XK_Escape)
		exit_game(stc);
	else if (key == KEY_W || key == UP)
	{
		stc->player.y--;
		player_update(stc, key);
	}
	else if (key == KEY_S || key == DOWN)
	{
		stc->player.y++;
		player_update(stc, key);
	}
	else if (key == KEY_D || key == RIGHT)
	{
		stc->player.x++;
		player_update(stc, key);
	}
	else if (key == KEY_A || key == LEFT)
	{
		stc->player.x--;
		player_update(stc, key);
	}
	return (0);
}

void	hooks(t_stc *stc)
{
	mlx_loop_hook(stc->game.mlx, draw_map, stc);
	mlx_loop(stc->game.mlx);
}

void	map_quest(t_stc *stc, char *map_name)
{
	if (ft_strnstr(map_name, "small_map", ft_strlen(map_name)))
	{
		printf("Complete the level in 27 moves\n");
		stc->map.map_type = 1;
	}
}
