#ifndef MINITALK_H
#define MINITALK_H

// #include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
// #include <string.h>
#include <signal.h>
// #include <stdio.h>
// #include <limits.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_error(int error);
size_t	ft_strlen(const char *s);

#endif