/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:26:41 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:02:48 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	cast_dst = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if (dest > src)
	{
		while (len--)
		{
			cast_dst[len] = cast_src[len];
		}
		return (cast_dst);
	}
	else
	{
		return (ft_memcpy (dest, src, len));
	}
}
