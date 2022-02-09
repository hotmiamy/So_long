/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:57:51 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:02:15 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *byte1, const void *byte2, size_t len)
{
	unsigned char	*cast_byte1;
	unsigned char	*cast_byte2;

	cast_byte1 = (unsigned char *)byte1;
	cast_byte2 = (unsigned char *)byte2;
	if (!len)
		return (0);
	while (--len)
	{
		if (*cast_byte1 != *cast_byte2)
			break ;
		cast_byte1++;
		cast_byte2++;
	}
	return (*cast_byte1 - *cast_byte2);
}
