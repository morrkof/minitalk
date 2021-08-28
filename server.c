#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

// #define _POSIX_C_SOURCE 199309L

unsigned char counter = 0;
int out_char = 0;

void my_func(int signal, siginfo_t *siginfo, void *context)
{
    
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
    else
        write(1, "UNDEFINED SIGNAL was received\n", 31);
}

int main()
{
    pid_t pid = getpid();
    printf("PID = %d\n", pid);

    // struct sigaction act;
    // memset(&act, 0, sizeof(act));
    // act.sa_handler = hdl;
    // sigset_t   set; 
    // sigemptyset(&set);                                                             
    // sigaddset(&set, SIGUSR1); 
    // sigaddset(&set, SIGUSR2);
    // act.sa_mask = set;
    // sigaction(SIGUSR1, &act, 0);
    // sigaction(SIGUSR2, &act, 0);

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_func;

    while(1) 
    {    
        if (counter >= 8)
        {
            // if (out_char == '\0')
            // {
            //     kill(sa.sa_sigaction.__siginfo_t.si_pid, SIGUSR1);
            // }
            // write(1, "\n", 1);
            write(1, &out_char, 4);
            // write(1, "\n", 1);
            counter = 0;
            out_char = 0;
        }
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        
        wait(NULL);
    }
}

