#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// #define _POSIX_C_SOURCE 199309L

void my_func(int signal, siginfo_t *siginfo, void *context)
{
    if(signal == SIGUSR1)
        write(1, "SIGUSR1\n", 9);
    else if(signal == SIGUSR2)
        write(1, "SIGUSR2\n", 9);
    else
        write(1, "UNDEFINED SIGNAL\n", 18);
}

int main()
{
    pid_t pid = getpid();
    printf("PID = %d\n", pid);

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_func;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1) 
    {
        wait(NULL);
    }
}

