/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:56:13 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 12:38:49 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_amount(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_reverse(char *s, int j)
{
	int		i;
	char	c;

	s[j] = '\0';
	i = 0;
	j--;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

static void	ft_negative(int *n, int *min, int *minus)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*min = 1;
	}
	*minus = 1;
	*n = *n * -1;
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		minus;
	int		min;

	i = 0;
	min = 0;
	minus = 0;
	if (n < 0)
		ft_negative(&n, &min, &minus);
	s = (char *)malloc(sizeof(char) * ft_amount(n) + 1 + minus);
	if (!s)
		return (NULL);
	while (n > 0)
	{
		s[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (minus)
		s[i++] = '-';
	if (min)
		s[0] = '8';
	ft_reverse(s, i);
	return (s);
}
