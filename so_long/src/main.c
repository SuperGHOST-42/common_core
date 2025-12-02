#include "../includes/so_long.h"

void	validate_map(t_game *game)
{
	t_map	*m;

	m = &game->map;
	if (check_rectangular(m))
		error_exit(game, "Mapa nao e rectangular");
	if (check_chars(m))
		error_exit(game, "Caracter invalido no mapa");
	if (count_elements(m))
		error_exit(game, "Numero invalido de elementos");
	if (check_walls(m))
		error_exit(game, "Mapa nao esta fechado por paredes");
	if (valid_path(game))
		error_exit(game, "Invalid path");
}

void print_map(t_map *map)
{
	int i;
	i = 0;
	while (i < map->height)
	{
		ft_printf("%s", map->grid[i]);
		i++;
	}
	ft_printf("\n");
}

int main(int argc, char **argv)
{
    t_game	game;
	ft_memset(&game, 0, sizeof(t_game));
	game.total_moves = 0;
	if (argc != 2)
		error_exit(&game, "Use: ./so_long map.ber");
	load_map(&game, argv[1]);
	validate_map(&game);
	print_map(&game.map);
	open_window(&game);
	load_sprites(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game); // close with X
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}