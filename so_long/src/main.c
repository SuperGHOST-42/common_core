#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game	game;
	int	y;

	if (argc != 2)
		error_exit(&game, "Use: ./so_long map.ber");

	load_map(&game, argv[1]);

	// TESTE DO PARSER ------------------------
	y = 0;
	while (y < game.map.height)
	{
		ft_printf("%s", game.map.grid[y]);
		y++;
	}
	ft_printf("\nHEIGHT = %i\n", game.map.height);
	ft_printf("WIDTH  = %i\n", game.map.width);

	ft_printf("Mapa rectangular = %i\n", check_rectangular(&game.map));
	ft_printf("Check Chars = %i\n", check_chars(&game.map));
	ft_printf("Count elements = %i\n", count_elements(&game.map));

	return (0);
}