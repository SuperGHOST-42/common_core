#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void    handler(int sig)
{
    static int     bit;
    static unsigned char c;

    c <<= 1;
    if (sig == SIGUSR1)  
        c |= 1;
    bit++;
    if (bit == 8)
    {
        if (c == 0)
            write (1, "\n", 1);
        else
            write(1, &c, 1);
        bit = 0;
        c = 0;
    }
}

int main(int argc, char **argv)
{
    ft_printf("PID do Servidor: %i\n", getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    
    while (1)
    {
        pause();
    }
    return (0);
}