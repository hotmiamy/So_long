/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 21:24:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define XK_MISCELLANY

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

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
	int		end_game;
	int		wdt;
	int		hgt;
	int		c_count;
	int		map_load;
}	t_game;

typedef struct s_map
{
	char	**map;
	int		map_type;
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

typedef struct s_cam
{
	char	**cam_m;
	int		x;
	int		y;
}	t_cam;

typedef struct s_player
{
	void	*sprite;
	char	*spr_fl[4];
	int		move;
	int		posix;
	int		sprt_w;
	int		sprt_h;
	int		moves;
	int		x;
	int		y;
}	t_player;

typedef struct s_stc
{
	t_game		game;
	t_tile		tile;
	t_player	player;
	t_map		map;
	t_cam		cam;
}	t_stc;

void	load_game(t_stc *mdl, char *map_path);
void	exit_sprites(t_stc *stc, int inx);
void	hooks(t_stc *stc);
void	player_move(t_stc *stc, int key);
void	player_update(t_stc *stc, int key);
void	player_sprite(t_stc *stc, int inx);
void	free_map(char **map);
void	validate_map(t_stc *stc, char *str);
void	load_cam(t_stc *stc);
void	read_map(t_stc *stc, int x, int y);
void	map_quest(t_stc *stc, char *map_name);
void	valid_chars(t_stc *stc);
int		exit_error(t_stc *stc, char *error);
int		main(int argc, char **argv);
int		draw(t_stc *stc, int x, int y);
int		draw_map(t_stc *stc);
int		is_valid(t_stc *stc);
int		is_free(t_stc *stc, int key);
int		cam(int atual, int min, int max);
int		key_hook(int key, t_stc *stc);
int		exit_game(t_stc *stc);
#endif