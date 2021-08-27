#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "arguments", 10);
        return(0);
    }
    pid_t server = atoi(argv[1]);
    char *msg = argv[2];
    kill(server, SIGUSR2);

}