/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/01/27 18:56:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define XK_MISCELLANY

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
}	t_game;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_tile
{
	void	*floor;
	void	*wall;
	int		wdt;
	int		hgt;
	int		x;
	int		y;
}	t_tile;

typedef struct s_module
{
	t_game	game;
	t_tile	tile;
}	t_module;

int		main(void);
void	draw_map(t_module *module, t_map *map);
void	load_game(t_module *mdl, t_map *map, char *map_path);
int		is_valid(t_map *map);

#endif