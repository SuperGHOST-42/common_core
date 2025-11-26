# include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	int i = 0;

	while (i < 8)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (result);
}
int main(void)
{
	int c = reverse_bits(0);
	printf("%d\n", c);
}