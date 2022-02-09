/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:47:11 by llopes-n          #+#    #+#             */
/*   Updated: 2021/08/30 20:48:33 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t maxlen)
{
	unsigned int	destlen;
	unsigned int	srclen;

	srclen = ft_strlen ((char *)src);
	destlen = 0;
	while (dest[destlen] && destlen != maxlen)
		destlen++;
	if (destlen == maxlen)
		return (maxlen + srclen);
	ft_memcpy (dest + destlen, src, srclen + 1);
	dest[maxlen - 1] = '\0';
	return (destlen + srclen);
}
