/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:17:51 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 19:35:42 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_error(int error)
{
	static char	*message[6] = {"     :wrong arguments (0)",
	"     :sigaction failed (1)", "     :memory allocation failed (2)",
	"     :sigemptyset failed (3)", "     :sigaddset failed (4)",
	"     :kill failed (5)"};

	write(2, "Error\n", 6);
	write(2, message[error], ft_strlen(message[error]));
	write(2, "\n", 1);
	exit(0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = s;
	while (n != 0)
	{
		s2[i] = c;
		i++;
		n--;
	}
	return (s);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
