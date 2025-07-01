#include <unistd.h>

void ft_putnbr(int nbr)
{
    char result;

    result = 0;
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
    }
    result = nbr % 10 + '0';
    write (1, &result, 1);
}

int main(void)
{
    int count;

    count = 1;
    while (count <= 100)
    {
        if (count % 3 == 0 && count % 5 == 0)
            write (1, "fizzbuzz", 8);
        else if (count % 3 == 0)
            write (1, "fizz", 4);
        else if (count % 5 == 0)
            write (1, "buzz", 4);
        else
            ft_putnbr(count);
        count++;
        write (1, "\n", 1);
    }
    write (1, "\n", 1);
    return (0);
}