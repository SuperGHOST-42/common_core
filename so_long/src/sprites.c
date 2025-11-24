#include "../includes/so_long.h"

static void	*load_xpm(t_game *game, char *path)
{
    int	width;
    int	heigth;
    void	*img;

    img = mlx_xpm_file_to_image(game->mlx, path, &width, &heigth);
    if (!img)
        error_exit(game, "Erro ao carregar sprite");
    return (img);
}

void    load_sprites(t_game *game)
{
    game->sprite.wall = load_xpm(game, "assets/wall.xpm");
    game->sprite.floor = load_xpm(game, "assets/blue.xpm");
    game->sprite.player = load_xpm(game, "assets/player.xpm");
    game->sprite.collect = load_xpm(game, "assets/collectible.xpm");
    game->sprite.exit = load_xpm(game, "assets/exit.xpm");
}
