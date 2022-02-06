/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:46:15 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 06:31:42 by coder            ###   ########.fr       */
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
	if (key == KEY_W && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.y++;
		return (0);
	}
	if (key == KEY_S && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.y--;
		return (0);
	}
	if (key == KEY_D && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.x--;
		return (0);
	}
	if (key == KEY_A && ft_strrchr("1E", stc->player.posix))
	{
		stc->player.x++;
		return (0);
	}
	mlx_destroy_image(stc->game.mlx, stc->player.sprite);
	return (1);
}

void	player_move(t_stc *stc, int key)
{
	if (key == KEY_W && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y + 1][stc->player.x] = '0';
		player_sprite(stc, 1);
	}
	if (key == KEY_S && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y - 1][stc->player.x] = '0';
		player_sprite(stc, 0);
	}
	if (key == KEY_D && is_free(stc, key) == 1)
	{
		stc->map.map[stc->player.y][stc->player.x] = 'P';
		stc->map.map[stc->player.y][stc->player.x - 1] = '0';
		player_sprite(stc, 3);
	}
	if (key == KEY_A && is_free(stc, key) == 1)
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
		exit_game(stc, "");
	player_move(stc, key);
	stc->cam.cam_m = load_cam(stc, stc->player.x - 1, stc->player.y - 1);
}
