#include <unistd.h>

int	in_s2(char c, char *s2)
{
	int	i = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	seen_before(char *s1, char c, int pos)
{
	int	i = 0;
	while (i < pos)
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	char c;

	if (argc != 3)
		return (write(1, "\n", 1), 0);
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (in_s2(c, argv[2]) && !seen_before(argv[1], c, i)) 
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
