#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void send_str(char *str, int pid)
{
    unsigned char counter;
    while(*str)
    {
        counter = 0;
        while(counter < 8)
        {
            if (1 << counter & *str)
            {
                kill(pid, SIGUSR1);
                usleep (50);
            }
            else
            {
                kill(pid, SIGUSR2);
                usleep (50);
            }
            counter++;
        }
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "arguments", 10);
        return(0);
    }
    send_str(argv[2], atoi(argv[1]));
    send_str("\n\0", atoi(argv[1]));
}