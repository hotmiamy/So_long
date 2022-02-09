/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:26:57 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:40:09 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	unsigned int	srclen;

	srclen = ft_strlen((char *)src);
	if (srclen < dest_size)
		ft_memcpy(dest, src, srclen + 1);
	else if (dest_size != 0)
	{
		ft_memcpy(dest, src, dest_size);
		dest[dest_size - 1] = '\0';
	}
	return (srclen);
}
