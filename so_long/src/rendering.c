# include "../includes/so_long.h"

static void	draw_tile(t_game *game, char c, int y, int x)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.wall, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.floor, x * TILE, y * TILE);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.player, x * TILE, y * TILE);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.collect, x * TILE, y * TILE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.exit, x * TILE, y * TILE);
}
void	render_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, game->map.grid[y][x], y, x);
			x++;
		}
		y++;
	}
}
