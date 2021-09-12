/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <morrkof@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:18:01 by ppipes            #+#    #+#             */
/*   Updated: 2021/09/13 02:51:27 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

// unsigned char counter = 0;
// int out_char = 0;

void my_func(int signal, siginfo_t *siginfo, void *context)
{
    (void)context;
    static unsigned char out_char;
    static unsigned char counter;
    if(signal == SIGUSR1)
    {
        out_char += 1 << counter;
        counter++;
        // write(1, "SIGUSR1 was received\n", 22);
    }
    else if(signal == SIGUSR2)
    {
        counter++;
        // write(1, "SIGUSR2 was received\n", 22);
    }
    // else
    //     write(1, "UNDEFINED SIGNAL was received\n", 31);
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

int main()
{
    pid_t pid = getpid();
    // printf("PID = %d\n", pid);
    write(1, "PID = ", 6);
    write(1, ft_itoa(pid), ft_strlen(ft_itoa(pid)));
    write(1, "\n", 1);

    struct sigaction sa;
    sigset_t   set;

    sigemptyset(&set);
    ft_memset(&sa, 0, sizeof(sa));

    sigaddset(&set, SIGUSR1); 
    sigaddset(&set, SIGUSR2);

    sa.sa_mask = set;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_func;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1) 
    {    
        pause();
    }
}

