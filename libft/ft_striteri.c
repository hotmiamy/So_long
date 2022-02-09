/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:02:09 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:45:41 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*ft)(unsigned int, char*))
{
	size_t	index;

	if (!str || !*str)
		return ;
	index = 0;
	while (str[index])
	{
		ft(index, &str[index]);
		index++;
	}
}
