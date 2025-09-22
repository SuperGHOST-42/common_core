#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void handler(int sig)
{
    
    ft_printf("Recebi, SIGUSER1: %i\n", sig);
}

int main(int argc, char **argv)
{
    ft_printf("PID do Servidor: %i\n", getpid());
    signal(SIGUSR1, handler);

    while (1)
    {
        pause();
    }
    return (0);
}