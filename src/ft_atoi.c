/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:27:11 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 12:27:34 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_skip_start(const char *nptr, int *minus)
{
	int	i;

	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f' || \
	nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*minus = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				minus;
	unsigned long	result;

	minus = 1;
	result = 0;
	i = ft_skip_start(nptr, &minus);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (!(ft_isdigit(nptr[i + 1])))
			return (result * minus);
		i++;
	}
	return (0);
}
