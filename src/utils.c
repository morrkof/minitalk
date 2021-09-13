/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:17:51 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 12:28:44 by ppipes           ###   ########.fr       */
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
	static char	*message[8] = {"     :wrong arguments (0)",
	"     :can't open the file (1)", "     :failed to create window (2)",
	"     :invalid map (3)", "     :invalid resolution (4)",
	"     :invalid color (5)", "     :invalid texture (6)",
	"     :memory allocation error (7)"};

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
