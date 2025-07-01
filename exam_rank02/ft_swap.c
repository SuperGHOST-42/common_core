#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int     main(void)
{
    int a = 10, b = 20;

    ft_swap(&a, &b);
    printf("%i, %i\n", a, b);
}