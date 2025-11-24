#include "../includes/so_long.h"

int key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	if (key == KEY_W)
	{
		game->total_moves++;
		move_player(game, -1, 0);
	}
	if (key == KEY_S)
	{
		game->total_moves++;
		move_player(game, 1, 0);
	}
	if (key == KEY_A)
	{
		game->total_moves++;
		move_player(game, 0, -1);
	}
	if (key == KEY_D)
	{
		game->total_moves++;
		move_player(game, 0, 1);
	}
	return (0);
}
