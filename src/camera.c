/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:29:03 by coder             #+#    #+#             */
/*   Updated: 2022/02/07 21:49:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_cam(t_stc *stc)
{
	if (stc->map.x >= 24)
		stc->cam.x = stc->map.x / 2;
	else
		stc->cam.x = stc->map.x;
	if (stc->map.y >= 24)
		stc->cam.y = stc->map.y / 2;
	else
		stc->cam.y = stc->map.y;
	stc->cam.cam_m = ft_calloc(stc->cam.y + 1, sizeof(char *));
}

void	read_map(t_stc *stc, int x, int y)
{
	int		array;
	int		index_map;

	array = 0;
	if (x > stc->map.x - stc->cam.x)
		x = stc->map.x - stc->cam.x;
	if (y > stc->map.y - stc->cam.y)
		y = stc->map.y - stc->cam.y;
	index_map = y;
	while (array < stc->cam.y)
	{
		free(stc->cam.cam_m[array]);
		stc->cam.cam_m[array] = ft_substr(stc->map.map[index_map],
				x, stc->cam.x);
		index_map++;
		array++;
		if (index_map == stc->map.y)
			index_map = stc->map.y - 1;
	}
}
