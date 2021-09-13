/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:31:55 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 19:36:03 by ppipes           ###   ########.fr       */
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
	if (kill(siginfo->si_pid, SIGUSR1) < 0)
		ft_error(5);
	if (counter >= 8)
	{
		write(1, &out_char, 1);
		counter = 0;
		out_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			set;
	char				*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		ft_error(2);
	write(1, "PID = ", 6);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
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
	while (1)
		pause();
}
