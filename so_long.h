/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/01 06:26:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define XK_MISCELLANY

# define CH_P 0
# define CH_E 0
# define CH_C 0
# define CH_0 0

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
	int		wdt;
	int		hgt;
}	t_tile;

typedef struct s_module
{
	t_game	game;
	t_tile	tile;
}	t_module;

int		main(void);
void	draw_map(t_module *module, t_map *map);
void	load_game(t_module *mdl, t_map *map, char *map_path);
int		is_valid(t_module *module, t_map *map);
void	exit_game(t_module *module, char *error);
int	valid_chars(t_module *module, t_map *map, int x, int y);

#endif