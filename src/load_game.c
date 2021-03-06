/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:50:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/10 00:40:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**load_map(t_stc *stc, char *path)
{
	int		map_fd;
	char	**map;
	char	*map_line_buff;
	char	*map_gnl_buff;
	char	*map_line;

	map_fd = open(path, O_RDONLY);
	if (map_fd < 0)
		exit_error(stc, "Unable to open the map");
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
	close(map_fd);
	validate_map(stc, map_line);
	map = ft_split(map_line, '\n');
	free(map_line);
	return (map);
}

void	size_window(t_stc *stc)
{
	stc->map.y = 0;
	while (stc->map.map[stc->map.y])
	{
		stc->map.x = 0;
		while (stc->map.map[stc->map.y][stc->map.x])
			stc->map.x++;
		stc->map.y++;
	}
	load_cam(stc);
	stc->game.wdt = stc->cam.x * 32;
	stc->game.hgt = stc->cam.y * 32;
}

void	load_static_sprites(t_stc *stc)
{
	stc->tile.floor = mlx_xpm_file_to_image(stc->game.mlx,
			TILE_FLOOR, &stc->tile.wdt, &stc->tile.hgt);
	stc->tile.wall = mlx_xpm_file_to_image(stc->game.mlx,
			WALL_TILE, &stc->tile.wdt, &stc->tile.hgt);
	stc->tile.colec = mlx_xpm_file_to_image(stc->game.mlx,
			COLEC, &stc->tile.wdt, &stc->tile.hgt);
}

void	exit_sprites(t_stc *stc, int inx)
{
	stc->tile.exit = mlx_xpm_file_to_image(stc->game.mlx,
			stc->tile.exit_fl[inx], &stc->tile.wdt, &stc->tile.hgt);
}

void	load_game(t_stc *stc, char *map_path)
{
	stc->map.ch_p = 0;
	stc->map.ch_e = 0;
	stc->map.ch_0 = 0;
	stc->game.c_count = 0;
	stc->cam.x = 0;
	stc->cam.y = 0;
	stc->game.map_load = 0;
	stc->player.moves = 0;
	stc->map.map_type = 0;
	stc->player.spr_fl[0] = PLAYER_F;
	stc->player.spr_fl[1] = PLAYER_B;
	stc->player.spr_fl[2] = PLAYER_L;
	stc->player.spr_fl[3] = PLAYER_R;
	stc->tile.exit_fl[0] = EXIT_CLOSE;
	stc->tile.exit_fl[1] = EXIT_OPEN;
	stc->map.map = load_map(stc, map_path);
	stc->game.map_load = 1;
	size_window(stc);
	stc->game.mlx = mlx_init();
	load_static_sprites(stc);
	exit_sprites(stc, 0);
	player_sprite(stc, 0);
	read_map(stc, 0, 0);
	stc->game.win = mlx_new_window(stc->game.mlx, stc->game.wdt,
			stc->game.hgt, "So Long");
}
