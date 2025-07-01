#include <unistd.h>

int ft_isspace(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (ft_isspace(argv[1][i]))
        i++;
    while (!ft_isspace(argv[1][i]) && argv[1][i] != '\0')
    {
        write(1, &argv[1][i], 1);
        i++;
    }
    write (1, "\n", 1);
    return (0);
}