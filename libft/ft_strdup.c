/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:51:41 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:47:08 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		strlen;
	char	*alloc_str;

	strlen = ft_strlen(str) + 1;
	alloc_str = (char *)malloc(strlen * sizeof(char));
	if (!alloc_str)
		return (NULL);
	ft_strlcpy(alloc_str, str, strlen);
	return (alloc_str);
}
