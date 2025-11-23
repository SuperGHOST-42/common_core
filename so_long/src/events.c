#include "../includes/so_long.h"

int key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	if (key == KEY_W)
		move_player(game, -1, 0);
	if (key == KEY_S)
		move_player(game, 1, 0);
	if (key == KEY_A)
		move_player(game, 0, -1);
	if (key == KEY_D)
		move_player(game, 0, 1);
	return (0);
}
