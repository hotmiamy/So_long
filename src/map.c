/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:11 by coder             #+#    #+#             */
/*   Updated: 2022/01/19 02:34:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map(void)
{
	void	*wall;
	void	*floor;
	int		map;
	int		read_tile;
	char	*buffer_tile;

	map = open ("../maps/map.ber", O_RDONLY);
	buffer_tile = ft_get_next_line(map);
	
}
