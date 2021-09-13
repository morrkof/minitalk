/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:31:55 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 12:36:22 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	my_func(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	out_char;
	static unsigned char	counter;

	(void)context;
	if (signal == SIGUSR1)
	{
		out_char += 1 << counter;
		counter++;
	}
	else if (signal == SIGUSR2)
		counter++;
	kill(siginfo->si_pid, SIGUSR1);
	if (counter >= 8)
	{
		write(1, &out_char, 1);
		if (out_char == '\n')
			kill(siginfo->si_pid, SIGUSR2);
		counter = 0;
		out_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			set;
	pid_t				pid;

	pid = getpid();
	write(1, "PID = ", 6);
	write(1, ft_itoa(pid), ft_strlen(ft_itoa(pid)));
	write(1, "\n", 1);
	sigemptyset(&set);
	ft_memset(&sa, 0, sizeof(sa));
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = my_func;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
