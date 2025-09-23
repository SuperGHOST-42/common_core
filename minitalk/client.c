#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void    send_bits(int pid, char c)
{
    int bit;
    int i;

    i = 7;
     while (i >= 0)
    {
        bit = (c >> i) & 1;
        if (bit == 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1500);
        i--;
    }
}

int main(int argc, char **argv)
{
    int i;
    int pid;

    pid = ft_atoi(argv[1]);
    i = 0;
    while (argv[2][i] != '\0')
    {
        send_bits(pid, argv[2][i]);
        i++;
    }
    send_bits(pid, '\0');
    return (0);
}