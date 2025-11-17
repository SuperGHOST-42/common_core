#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	error_exit(t_game *game, char *msg)
{
	if (game)
		free_map(&game->map);

	ft_printf("%s\n", msg);
	exit(1);
}
