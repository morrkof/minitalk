/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:56:51 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 11:58:01 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_error(int error);
size_t	ft_strlen(const char *s);

#endif