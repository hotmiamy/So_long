/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/01/20 01:00:28 by coder            ###   ########.fr       */
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
	void	*window;
	int		width;
	int		height;
	int		map;
}	t_game;

typedef struct s_tile
{
	void			*floor;
	void			*wall;
	int				x;
	int				y;
	struct s_tile	*next;
}	t_tile;

typedef struct s_cord
{
	int	x;
	int	y;
	int	col;
	int	row;
}	t_cord;

int		main(void);
void	draw_map(int map, t_game *game);

#endif