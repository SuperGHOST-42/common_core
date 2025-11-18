#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define TILE 64

typedef struct s_map
{
    char    **grid;     // matriz de chars
    int     width;      // colunas // oTamanho da linha
    int     height;     // linhas
    int     collectibles;
    int     exits;
    int     players;
}   t_map;

typedef struct s_player
{
    int     x;
    int     y;
    int     moves;
    int     collected;
}   t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_player player;
}   t_game;

typedef struct s_flood_fill
{
    int	collectibles;
    int collectibles_found;
    int valid_exit;
}   t_flood_fill;

void    error_exit(t_game *game, char *msg);

// map parsing
void	load_map(t_game *game, char *file);
int     ft_strlen_no_nl(char *s);

// validate map
int	check_rectangular(t_map *map);
int	check_chars(t_map *map);
int	count_elements(t_map *map);
int	check_walls(t_map *map);

// flood fill
int	valid_path(t_game *game);


# endif
