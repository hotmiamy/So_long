/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:06:17 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 03:38:35 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *byte, int chr, size_t len)
{
	unsigned char	*cast_byte;

	cast_byte = (unsigned char *)byte;
	while (len--)
	{
		if (*cast_byte == (unsigned char)chr)
			return (cast_byte);
		cast_byte++;
	}
	return (0);
}
