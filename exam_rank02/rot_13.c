#include <unistd.h>

char ft_rot(char c)
{
    return (c += 13);
}

int main(int argc, char **argv)
{
    int i;
    char rot;

    if (argc != 2)
    {
        write (1, "\n", 1);
    }
    i = 0;
    while (argv[1][i])
    {
        rot = ft_rot(argv[1][i]);
        if (rot >= 'z')
        {
            rot -= 13;
        }
        write(1, &rot, 1);
        i++;
    }
    write (1, "\n", 1);
    return (0);
}