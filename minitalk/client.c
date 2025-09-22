#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
    int pid;

    pid = ft_atoi(argv[1]);

    if (kill(pid, SIGUSR1) == -1)
        perror("erro ao enviar sinal\n");
    else
        ft_printf("Enviei sinal para o pid: %i\n", pid);
    return (0);
}