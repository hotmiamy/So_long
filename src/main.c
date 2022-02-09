/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:03:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/02/09 22:11:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_stc	stc;

	if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) != 0)
	{
		load_game(&stc, argv[1]);
		if (is_valid(&stc) == 1)
		{
			map_quest(&stc, argv[1]);
			mlx_key_hook(stc.game.win, key_hook, &stc);
			mlx_hook(stc.game.win, 17, 1L << 17, exit_game, &stc);
			hooks(&stc);
		}
		else
			exit_error(&stc, "map is invalid");
		return (0);
	}
	else
	{
		printf("Error\nwrong syntax or wrong map extention\n");
		exit(0);
	}
}
