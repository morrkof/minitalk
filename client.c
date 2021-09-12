#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int g_jopa = 1;

void send_str(char *str, int pid)
{
    unsigned char counter;
    while(*str)
    {
        counter = 0;
        while(counter < 8)
        {
            usleep(1000);
            if (g_jopa)
            {
                if (1 << counter & *str)
                {
                    kill(pid, SIGUSR1);
                    // usleep (50);
                    g_jopa = 0;
                }
                else
                {
                    kill(pid, SIGUSR2);
                    // usleep (50);
                    g_jopa = 0;
                }
                counter++;
            }
        }
        str++;
    }
}

void my_func(int signal, siginfo_t *siginfo, void *context)
{
    // if (signal == SIGUSR1)
    //     write(1, ".", 1);
    // else if (signal == SIGUSR2)
    //     write(1, "\nMessage received.\n", 19);
    g_jopa = 1;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "arguments", 10);
        return(0);
    }
    struct sigaction sa;
    sigset_t   set;

    sigemptyset(&set);
    memset(&sa, 0, sizeof(sa));

    sigaddset(&set, SIGUSR1); 
    sigaddset(&set, SIGUSR2);

    sa.sa_mask = set;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_func;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    send_str(argv[2], atoi(argv[1]));
    send_str("\n", atoi(argv[1]));
}