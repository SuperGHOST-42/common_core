#include "../includes/so_long.h"

static int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (file[len - 1] != 'r'
		|| file[len - 2] != 'e'
		|| file[len - 3] != 'b'
		|| file[len - 4] != '.')
		return (0);
	return (1);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(NULL, "Erro: nao consegui abrir o mapa");
	count = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	load_map(t_game *game, char *file)
{
	int		fd;
	int		i;

	if (!check_extension(file))
		error_exit(NULL, "Erro: o ficheiro deve terminar em .ber");

	game->map.height = count_lines(file);
	if (game->map.height == 0)
		error_exit(NULL, "Erro: mapa vazio");

	game->map.grid = malloc(sizeof(char *) * game->map.height);
	if (!game->map.grid)
		error_exit(game, "Erro: malloc falhou");

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Erro: nao consegui abrir o mapa");

	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = get_next_line(fd);
		if (!game->map.grid[i])
			error_exit(game, "Erro: atribuicao de linha falhou");
		i++;
	}
	close(fd);
	game->map.width = ft_strlen_no_nl(game->map.grid[0]);
}