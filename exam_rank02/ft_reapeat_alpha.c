#include <unistd.h>

int    repeat_alpha(char c)
{
    int     repeat;

    if (c >= 'a' && c <= 'z')
        repeat = c - 'a' + 1;
    else if (c >= 'A' && c <= 'Z')
        repeat = c - 'A' + 1;
    else 
        repeat = 1;
    return (repeat);
}

int main(int argc, char **argv)
{
    int     i;
    int     j;
    int     count;
    if (argc != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        count = repeat_alpha(argv[1][i]);
        j = 0;
        while (j < count)
        {
            write (1, &argv[1][i], 1);
            j++;
        }
        i++;
    }
    write (1, "\n", 1);
}