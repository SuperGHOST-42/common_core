#include "../includes/so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	first_line_lenght;
	int	next_line;

	i = 1;
	first_line_lenght = ft_strlen_no_nl(map->grid[0]);
	while(i < map->height)
	{
		next_line = ft_strlen_no_nl(map->grid[i]);
		if (next_line != first_line_lenght)
			return (1);
		i++;
	}
	return (0);
}
int	check_chars(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			c = map->grid[i][j];
			if (c != '0' && c != '1' && c != 'C'
				&& c != 'E' && c != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_elements(t_map *map)
{
	int	i;
	int	j;
	char	c;

	map->players = 0;
	map->exits = 0;
	map->collectibles = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			c = map->grid[i][j];
			if (c == 'P')
				map->players++;
			else if (c == 'E')
				map->exits++;
			else if (c == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	return (!(map->players == 1 && map->exits == 1 && map->collectibles > 0));
}

static int	is_wall_row(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	last;

	last = map->height - 1;
	if (!is_wall_row(map->grid[0]) || !is_wall_row(map->grid[last]))
		return (1);
	i = 1;
	while (i < last)
	{
		if (map->grid[i][0] != '1'
			|| map->grid[i][map->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
