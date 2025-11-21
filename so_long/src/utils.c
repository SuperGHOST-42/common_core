#include "../includes/so_long.h"

void	error_exit(t_game *game, char *msg)
{
	if (game)
		free_all(game);

	ft_printf("%s\n", msg);
	exit(1);
}
