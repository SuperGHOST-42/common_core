#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void    handler(int sig, siginfo_t *info, void *context)
{
    static int     bit;
    static unsigned char c;

    c <<= 1;
    if (sig == SIGUSR1)  
        c |= 1;
    bit++;
    if (bit == 8)
    {
        if (c != '\0')
            write (1, &c, 1);
        else
            write(1, "\n", 1);
        bit = 0;
        c = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    ft_printf("PID do Servidor: %i\n", getpid());

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    while (1)
        pause();
    return (0);
}