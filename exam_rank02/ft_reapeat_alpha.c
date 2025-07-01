#include <unistd.h>

int ft_is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}
int repeat_alpha(char c)
{
    int     repeat;

    repeat = 1;
    if (c >= 'A' && c <= 'Z')
    {
        repeat = c - 'A' + 1;    
    }
    else if (c >= 'a' && c <= 'z')
    {
        repeat = c - 'a' + 1;
    }
    return (repeat);    
}

int main (int argc, char **argv)
{
    int i;
    int repeat;

    i = 0;

    if (argc != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    while (argv[1][i])
    {
        if (ft_is_alpha(argv[1][i]))
        {
            repeat = repeat_alpha(argv[1][i]);
            while (repeat)
            {
                write(1, &argv[1][i], 1);
                repeat--;
            }
        }
        else
        {
            write(1, &argv[1][i], 1);
        }
        i++;
    }
    write (1, "\n", 1);
    return (0);
}