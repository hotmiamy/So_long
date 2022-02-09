/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:05:17 by llopes-n          #+#    #+#             */
/*   Updated: 2021/11/04 14:20:42 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_converter(unsigned long nbr, char *base)
{
	int		base_len;
	char	*str;
	int		aux;
	int		len;

	aux = nbr;
	base_len = ft_strlen(base);
	if(nbr == 0)
		len = 1;
	while (aux)
	{
		aux /= base_len;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if(!str)
		return (0);
	while(nbr)
	{
		str[--len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (str);
}
