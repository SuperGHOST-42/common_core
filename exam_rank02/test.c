# include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	char c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'a' && c <= 'z')
		{
			if (c + 13 > 'z')
				c = c - 13;
			else
				c = c + 13; 
		}
		else if(c >= 'A' && c <= 'Z')
		{
			if (c + 13 > 'Z')
				c = c - 13;
			else
				c = c + 13; 
		}
		i++;
		write (1, &c, 1);
	}
	write (1, "\n", 1);
	return (0);
	
}