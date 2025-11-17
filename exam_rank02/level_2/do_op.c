#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int result, n1, n2;

	if (argc != 4)
	{
		printf("\n");
		return (0);
	}
	result = 0;
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);

	if (*argv[2] == '+')
		result = n1 + n2;
	else if (*argv[2] == '-')
		result = n1 - n2;
	else if (*argv[2] == '*')
		result = n1 * n2;
	else if (*argv[2] == '/')
		result = n1 / n2;
	else if (*argv[2] == '%')
		result = n1 % n2;
	printf("%i\n", result);
	return (0);
	

}