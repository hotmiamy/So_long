/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:46:15 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 17:35:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_sprite(t_stc *stc, int inx)
{
	stc->player.sprite = mlx_xpm_file_to_image(stc->game.mlx,
			stc->player.spr_fl[inx],
			&stc->player.sprt_w, &stc->player.sprt_h);
}

int	is_free(t_stc *stc, int key)
{
	if ((key == KEY_W || key == UP) && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.y++;
		return (0);
	}
	if ((key == KEY_S || key == DOWN) && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.y--;
		return (0);
	}
	if ((key == KEY_D || key == RIGHT) && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.x--;
		return (0);
	}
	if ((key == KEY_A || key == LEFT) && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.x++;
		return (0);
	}
	mlx_destroy_image(stc->game.mlx, stc->player.sprite);
	return (1);
}

void	player_move(t_stc *stc, int key)
{
	if ((key == KEY_W || key == UP) && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y + 1][stc->player.x] = '0';
		player_sprite(stc, 1);
	}
	if ((key == KEY_S || key == DOWN) && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y - 1][stc->player.x] = '0';
		player_sprite(stc, 0);
	}
	if ((key == KEY_D || key == RIGHT) && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y][stc->player.x - 1] = '0';
		player_sprite(stc, 3);
	}
	if ((key == KEY_A || key == LEFT) && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y][stc->player.x + 1] = '0';
		player_sprite(stc, 2);
	}
}

void	player_update(t_stc *stc, int key)
{
	stc->player.posix = stc->map.map[stc->player.y][stc->player.x];
	if (stc->player.posix == 'C')
		stc->game.c_count--;
	else if (stc->game.c_count == 0 && stc->player.posix == 'E')
		exit_game(stc);
	player_move(stc, key);
	if (stc->map.map_type == 1)
		printf("Player moves: %d/27\n", ++stc->player.moves);
	else
		printf("Player moves: %d\n", ++stc->player.moves);
	if (stc->player.moves > 27 && stc->map.map_type == 1)
		exit_error(stc, "Failed: Complete the level in 27 moves");
	if (stc->map.x >= 24 && stc->map.y < 24)
		read_map(stc, stc->player.x - 1, 0);
	if (stc->map.x < 24 && stc->map.y >= 24)
		read_map(stc, 0, stc->player.y - 1);
	if (stc->map.x >= 24 && stc->map.y >= 24)
		read_map(stc, stc->player.x - 1, stc->player.y - 1);
	if (stc->map.x < 24 && stc->map.y < 24)
		read_map(stc, 0, 0);
}
