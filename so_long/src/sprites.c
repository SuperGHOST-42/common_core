/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:56 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/02 14:37:07 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*load_xpm(t_game *game, char *path)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
		error_exit(game, "Erro ao carregar sprite");
	return (img);
}

void	load_sprites(t_game *game)
{
	game->sprite.wall = load_xpm(game, "assets/wall.xpm");
	game->sprite.floor = load_xpm(game, "assets/floor.xpm");
	game->sprite.player = load_xpm(game, "assets/player.xpm");
	game->sprite.collect = load_xpm(game, "assets/collectible.xpm");
	game->sprite.exit = load_xpm(game, "assets/exit.xpm");
}
