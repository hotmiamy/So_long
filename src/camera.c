/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:29:03 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 06:40:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**load_cam(t_stc *stc, int x, int y)
{
	int		array;
	int		index_map;
	char	**cam_m;

	array = 0;
	cam_m = ft_calloc((stc->map.y / 2) + 1, sizeof(char **));
	index_map = y;
	while (array < stc->map.y / 2)
	{
		cam_m[array] = ft_substr(stc->map.map[index_map], x, stc->map.x / 2);
		if (index_map != stc->map.y)
			index_map++;
		printf("%s\n", stc->map.map[index_map]);
		array++;
	}
	stc->cam.x = stc->map.x / 2;
	stc->cam.y = stc->map.y / 2;
	return (cam_m);
}
