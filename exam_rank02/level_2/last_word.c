#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int end;

	if (argc != 2)
		return (write(1, "\n", 1), 0);

	i = 0;
	while (argv[1][i])
		i++;

	// voltar do fim ignorando espaços/tabs
	while (i > 0 && (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
		i--;

	end = i; // fim da última palavra

	// voltar até encontrar espaço ou início
	while (i > 0 && argv[1][i - 1] != ' ' && argv[1][i - 1] != '\t')
		i--;

	// escrever a palavra
	write(1, &argv[1][i], end - i);
	write(1, "\n", 1);

	return (0);
}
