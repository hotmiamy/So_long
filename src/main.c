/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/02/06 06:16:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_stc *stc)
{
	printf("%d\n", key);
	if (key == XK_Escape)
		exit_game(stc, "");
	else if (key == KEY_W)
	{
		stc->player.y--;
		player_update(stc, key);
	}
	else if (key == KEY_S)
	{
		stc->player.y++;
		player_update(stc, key);
	}
	else if (key == KEY_D)
	{
		stc->player.x++;
		player_update(stc, key);
	}
	else if (key == KEY_A)
	{
		stc->player.x--;
		player_update(stc, key);
	}
	return (0);
}

int	main(void)
{
	t_stc	stc;

	load_game(&stc, "./maps/map.ber");
	if (is_valid(&stc) == 1)
	{
		mlx_key_hook(stc.game.win, key_hook, &stc);
		hooks(&stc);
		mlx_loop(stc.game.mlx);
	}
	else
		exit_game(&stc, "map is invalid");
	return (0);
}

int	cam(int atual, int min, int max)
{
	if (atual < min)
		atual = min;
	if (atual > max)
		atual = max;
	return (atual);
}
