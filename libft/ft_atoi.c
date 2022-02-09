/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:25:26 by llopes-n          #+#    #+#             */
/*   Updated: 2021/10/01 14:40:09 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_isspace(char *number)
{
	while ((*number >= '\a' && *number <= '\r') || *number == ' ')
		number++;
	return (number);
}

static int	ft_isoverload(int number, char lastdig, int sig)
{
	if (number > INT_MAX / 10 || (number == INT_MAX / 10 && lastdig - '0' > 7))
	{
		if (sig == -1)
			return (INT_MIN);
		else
			return (INT_MAX);
	}
	return (0);
}

int	ft_atoi(const char *numstr)
{
	int	index;
	int	sig;
	int	num_int;

	index = 0;
	num_int = 0;
	sig = 1;
	numstr = ft_isspace((char *)numstr);
	if (numstr[index] == '-' || numstr[index] == '+')
	{
		sig = 1 - 2 * (numstr[index] == '-');
		index++;
	}
	while (ft_isdigit(numstr[index]) != 0)
	{
		if (ft_isoverload(num_int, numstr[index], sig) != 0)
			return (ft_isoverload(num_int, numstr[index], sig));
		num_int = num_int * 10 + (numstr[index++] - '0');
	}
	if (num_int > 0)
		return (num_int * sig);
	return (0);
}
