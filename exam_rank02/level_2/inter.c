#include <unistd.h>

int	ft_double(char c, char *s1, char *s2)
{
	int i = 0;
	int doubles = 0;

	while(s2[i])
	{
		if (c == s2[i])
		{
			doubles++;
		}
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (c == s1[i])
		{
			doubles++;
		}
		i++;	
	}
	if (doubles == 2)
		return (2);
	return (0);
}
int	main(int argc, char **argv)
{
	int i;

	i = 0;
	while (argv[1][i])
	{
		if ((ft_double(argv[1][i], argv[1], argv[2])) == 2)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		else
			i++;
	}
	write(1, "\n", 1);
	return (0);
}