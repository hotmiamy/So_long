/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:50:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/03 06:01:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**load_map(char *path)
{
	int		map_fd;
	char	**map;
	char	*map_line_buff;
	char	*map_gnl_buff;
	char	*map_line;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		return (NULL);
	map_line = ft_strdup("");
	while (1)
	{
		map_gnl_buff = ft_get_next_line(map_fd);
		if (!map_gnl_buff)
			break ;
		map_line_buff = map_line;
		map_line = ft_strjoin(map_line_buff, map_gnl_buff);
		free(map_gnl_buff);
		free(map_line_buff);
	}
	map = ft_split(map_line, '\n');
	free(map_line);
	close(map_fd);
	return (map);
}

void	size_window(t_stc *stc)
{
	stc->map.y = 0;
	while (stc->map.map[stc->map.y])
	{
		stc->map.x = 0;
		while (stc->map.map[stc->map.y][stc->map.x])
		{
			valid_chars(stc, stc->map.x, stc->map.y);
			stc->map.x++;
		}
		stc->map.y++;
	}
	stc->game.wdt = stc->map.x * 32;
	stc->game.hgt = stc->map.y * 32;
}

void	load_static_sprites(t_stc *stc)
{
	stc->tile.floor = mlx_xpm_file_to_image(stc->game.mlx,
			TILE_FLOOR, &stc->tile.wdt, &stc->tile.hgt);
	stc->tile.wall = mlx_xpm_file_to_image(stc->game.mlx,
			WALL_TILE, &stc->tile.wdt, &stc->tile.hgt);
	stc->tile.colec = mlx_xpm_file_to_image(stc->game.mlx,
			COLEC, &stc->tile.wdt, &stc->tile.hgt);
	stc->tile.exit = mlx_xpm_file_to_image(stc->game.mlx,
			EXIT_CLOSE, &stc->tile.wdt, &stc->tile.hgt);
}

void	load_dinamic_sprites(t_stc *stc, int type, int inx)
{
	stc->player.spr_fl[0] = PLAYER_F;
	stc->player.spr_fl[1] = PLAYER_B;
	stc->player.spr_fl[2] = PLAYER_L;
	stc->player.spr_fl[3] = PLAYER_R;
	stc->tile.exit_fl[0] = EXIT_CLOSE;
	stc->tile.exit_fl[1] = EXIT_OPEN;
	if (type == 0)
		stc->player.sprite = mlx_xpm_file_to_image(stc->game.mlx,
				stc->player.spr_fl[inx],
				&stc->player.sprt_w, &stc->player.sprt_h);
	if (type == 1)
		stc->tile.exit = mlx_xpm_file_to_image(stc->game.mlx,
				stc->tile.exit_fl[inx], &stc->tile.wdt, &stc->tile.hgt);
}

void	load_game(t_stc *stc, char *map_path)
{
	stc->map.ch_p = 0;
	stc->map.ch_e = 0;
	stc->map.ch_0 = 0;
	stc->game.c_count = 0;
	stc->map.map = load_map(map_path);
	stc->game.mlx = mlx_init();
	size_window(stc);
	stc->game.win = mlx_new_window(stc->game.mlx, stc->game.wdt,
			stc->game.hgt, "So Long");
	load_static_sprites(stc);
	load_dinamic_sprites(stc, 0, 0);
	load_dinamic_sprites(stc, 1, 0);
}
