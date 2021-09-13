/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:32:02 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 19:45:07 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_jopa = 1;

void	send_str(char *str, int pid)
{
	unsigned char	counter;

	while (*str)
	{
		counter = 0;
		while (counter < 8)
		{
			if (g_jopa)
			{
				g_jopa = 0;
				if (1 << counter & *str)
				{
					if (kill(pid, SIGUSR1) < 0)
						ft_error(5);
				}
				else
					if (kill(pid, SIGUSR2) < 0)
						ft_error(5);
				counter++;
			}
		}
		str++;
	}
}

void	my_func(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signal == SIGUSR1)
		write(1, ".", 1);
	g_jopa = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	sigset_t			set;

	if (argc != 3)
		ft_error(0);
	if (sigemptyset(&set) < 0)
		ft_error(3);
	ft_memset(&sa, 0, sizeof(sa));
	if (sigaddset(&set, SIGUSR1) < 0 || sigaddset(&set, SIGUSR2) < 0)
		ft_error(4);
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = my_func;
	if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
		ft_error(1);
	send_str(argv[2], ft_atoi(argv[1]));
	send_str("\n", ft_atoi(argv[1]));
	usleep(50);
	write(1, "\nMessage received.\n", 19);
}
