#include "../includes/so_long.h"

void	open_window(t_game *game)
{
	int w;
	int h;

	w = game->map.width * TILE;
	h = game->map.height * TILE;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "Erro ao iniciar MLX");
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
		error_exit(game, "Erro ao criar window");
}
/*
int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	game->mlx = NULL;
	exit(0);
	return (0);
}*/

int	close_window(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}
