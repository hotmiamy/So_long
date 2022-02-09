/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:35:38 by llopes-n          #+#    #+#             */
/*   Updated: 2021/09/14 04:46:59 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cont_digits(int nbr)
{
	int	nbr_count;

	nbr_count = 0;
	if (nbr < 0)
		nbr_count = 1;
	while (nbr)
	{
		nbr_count++;
		nbr /= 10;
	}
	return (nbr_count);
}

char	*ft_itoa(int nbr)
{
	char	*nbr_str;
	int		nbr_digits;

	if (nbr == 0)
		return (ft_strdup("0"));
	nbr_digits = ft_cont_digits(nbr);
	nbr_str = ft_calloc((nbr_digits + 1), (sizeof(char)));
	if (!nbr_str)
		return (0);
	if (nbr < 0)
		nbr_str[0] = '-';
	while (nbr)
	{
		if (nbr > 0)
			nbr_str[--nbr_digits] = '0' + (nbr % 10);
		else
			nbr_str[--nbr_digits] = '0' - (nbr % 10);
		nbr /= 10;
	}
	return (nbr_str);
}
