/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 20:23:55 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 14:35:25 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str_conca;
	int		str1len;
	int		str_concalen;

	if (!str1)
		return (0);
	str1len = ft_strlen(str1);
	str_concalen = str1len + ft_strlen(str2) + 1;
	str_conca = (char *)malloc(str_concalen * sizeof(char));
	if (!str_conca)
		return (0);
	ft_strlcpy(str_conca, str1, str1len + 1);
	ft_strlcat(str_conca, str2, str_concalen);
	return (str_conca);
}
