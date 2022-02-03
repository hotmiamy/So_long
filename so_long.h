/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/03 05:56:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define XK_MISCELLANY

# define PLAYER_F "./images/player_front.xpm"
# define PLAYER_B "./images/player_back.xpm"
# define PLAYER_L "./images/player_left.xpm"
# define PLAYER_R "./images/player_right.xpm"
# define TILE_FLOOR "./images/floor_tile.xpm"
# define WALL_TILE "./images/wall_tile.xpm"
# define COLEC "./images/colec_tile.xpm"
# define EXIT_OPEN "./images/op_exit_tile.xpm"
# define EXIT_CLOSE "./images/clo_exit_tile.xpm"

# include <X11/keysymdef.h>
# include <X11/X.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		wdt;
	int		hgt;
	int		c_count;
}	t_game;

typedef struct s_map
{
	char	**map;
	int		ch_p;
	int		ch_e;
	int		ch_0;
	int		x;
	int		y;
}	t_map;

typedef struct s_tile
{
	void	*floor;
	void	*wall;
	void	*colec;
	void	*exit;
	char	*exit_fl[2];
	int		wdt;
	int		hgt;
}	t_tile;

typedef struct s_player
{
	void	*sprite;
	char	*spr_fl[4];
	int		sprt_w;
	int		sprt_h;
	int		x;
	int		y;
}	t_player;

typedef struct s_stc
{
	t_game		game;
	t_tile		tile;
	t_player	player;
	t_map		map;
}	t_stc;

int		main(void);
void	draw(t_stc *stc, int x, int y);
void	draw_map(t_stc *stc);
void	load_game(t_stc *mdl, char *map_path);
int		is_valid(t_stc *module);
void	exit_game(t_stc *module, char *error);
int		valid_chars(t_stc *module, int x, int y);
void	load_dinamic_sprites(t_stc *stc, int type, int inx);

#endif