#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i;
	unsigned char bit;

	bit = 1;

	i = 8;
	while (i >= 0)
	{
		bit = octet;
		bit = (bit >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);

}
int	main(int argc, char **argv)
{
	int i = 0;
	while (i <= 20)
	{
		print_bits(i);
		i++;
	}
	printf("\n");
}
