#include "../includes/so_long.h"

int key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	return (0);
}
