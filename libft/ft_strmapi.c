/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:04:05 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/09 20:44:20 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*ft)(unsigned int, char))
{
	char	*newstr;
	int		index;

	if (!str || !ft)
		return (0);
	newstr = (char *)ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	index = 0;
	while (str[index])
	{
		newstr[index] = ft(index, str[index]);
		index++;
	}
	return (newstr);
}
