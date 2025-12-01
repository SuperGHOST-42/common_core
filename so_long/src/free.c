#include "../includes/so_long.h"

void    free_sprite(t_game *game)
{
    if (game->sprite.wall)
        mlx_destroy_image(game->mlx, game->sprite.wall);
    if (game->sprite.floor)
        mlx_destroy_image(game->mlx, game->sprite.floor);
    if (game->sprite.player)
        mlx_destroy_image(game->mlx, game->sprite.player);
    if (game->sprite.collect)
        mlx_destroy_image(game->mlx, game->sprite.collect);
    if (game->sprite.exit)
        mlx_destroy_image(game->mlx, game->sprite.exit);
}

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

void	free_all(t_game *game)
{
	/* 1) Free mapa */
	free_map(&game->map);

	if (game->map.flag_exit != 1)
	{
		return ;	
	}
	/* 2) Free imagens */
	  if (game->mlx)
		free_sprite(game); 

	/* 3) Free janela */
	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}

	/* 4) Free display (apenas no Linux) */
	#ifdef __linux__
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	#endif

	/* 5) Free MLX pointer */
	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
}