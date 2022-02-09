/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:31:40 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:46:05 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	strlen;
	char			*substr;

	if (!str)
		return (0);
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	else if (strlen <= len)
		len = strlen - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
