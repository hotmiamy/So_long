/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:44:14 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:43:12 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big_str, const char *little_str, size_t len)
{
	size_t	litt_len;

	litt_len = ft_strlen(little_str);
	if (*little_str == '\0')
		return ((char *)big_str);
	while (*big_str != '\0' && len)
	{
		if (*big_str == *little_str)
		{
			if (len >= litt_len)
			{
				if (ft_strncmp(big_str, little_str, litt_len) == 0)
					return ((char *)big_str);
			}
			else
				return (NULL);
		}
		big_str++;
		len--;
	}
	return (0);
}
