/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:23:16 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/02 14:51:55 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_map(t_game *game)
{
	t_map	*m;

	m = &game->map;
	if (check_rectangular(m))
		error_exit(game, "Map is not rectangular");
	if (check_chars(m))
		error_exit(game, "Invalid character in map");
	if (count_elements(m))
		error_exit(game, "Invalid number of elements");
	if (check_walls(m))
		error_exit(game, "Map is not surrounded by walls");
	if (valid_path(game))
		error_exit(game, "Invalid path");
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s", map->grid[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		error_exit(&game, "Use: ./so_long map.ber");
	load_map(&game, argv[1]);
	validate_map(&game);
	print_map(&game.map);
	open_window(&game);
	load_sprites(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
