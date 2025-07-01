#include <unistd.h>

int ft_strlen(char *str)
{
    size_t len;

    len = 0;
    while(str[len])
        len++;
    return (len);
}

int main(int argc, char **argv)
{
    int lenght;
    int i;

    if ( argc != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    lenght = ft_strlen(&argv[1][0]);
    i = 0;
    while (lenght >= 0)
    {
        write(1, &argv[1][lenght], 1);
        lenght--;
    }
    write (1, "\n", 1);
    return (0);
}