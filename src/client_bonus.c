/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:32:02 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 19:00:27 by ppipes           ###   ########.fr       */
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
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
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
	else if (signal == SIGUSR2)
		write(1, "\nMessage received.\n", 19);
	g_jopa = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	sigset_t			set;

	if (argc != 3)
		ft_error(0);
	sigemptyset(&set);
	ft_memset(&sa, 0, sizeof(sa));
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = my_func;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(argv[2], ft_atoi(argv[1]));
	send_str("\n", ft_atoi(argv[1]));
}
