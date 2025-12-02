#include "../includes/so_long.h"

static void	move_player(t_game *game, int move_y, int move_x)
{
	int new_y;
	int new_x;

	new_y = game->player.y + move_y;
	new_x = game->player.x + move_x;
	if (new_y < 0 || new_y >= game->map.height ||
    new_x < 0 || new_x >= game->map.width)
    	return;
	if (game->map.grid[new_y][new_x] == '1')
		return;
	if (game->map.grid[new_y][new_x] == 'C')
		game->map.collectibles--;
	if (game->map.grid[new_y][new_x] == 'E' && game->map.collectibles != 0)
		return ;
	if (game->map.grid[new_y][new_x] == 'E' && game->map.collectibles == 0)
	{
		ft_printf("YOU WON!\n");
		close_window(game);
	}
	game->map.grid[game->player.y][game->player.x] = '0';
	game->player.y = new_y;
	game->player.x = new_x;
	game->map.grid[new_y][new_x] = 'P';
	render_map(game);
}

int key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	if (key == KEY_W)
	{
		game->total_moves++;
		ft_printf("move %i\n", game->total_moves);
		move_player(game, -1, 0);
	}
	if (key == KEY_S)
	{
		game->total_moves++;
		ft_printf("move %i\n", game->total_moves);
		move_player(game, 1, 0);
	}
	if (key == KEY_A)
	{
		game->total_moves++;
		ft_printf("move %i\n", game->total_moves);
		move_player(game, 0, -1);
	}
	if (key == KEY_D)
	{
		game->total_moves++;
		ft_printf("move %i\n", game->total_moves);
		move_player(game, 0, 1);
	}
	return (0);
}
