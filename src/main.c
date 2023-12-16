/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:11:38 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 19:48:13 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parse.h"

void	convert_map_game(t_map *map, t_game *game)
{
	game->p.pos_x = map->player_row;
	game->p.pos_y = map->player_col;
	game->map.matrix = map->matrix;
	game->map.info = map->info;
	game->map.dir_ch = map->dir_ch;
	game->map.width = map->width;
	game->map.height = map->height;
	game->map.floor = map->floor;
	game->map.ceiling = map->ceiling;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	ft_bzero(&map, sizeof(map));
	if (argc != 2)
		error_exit("usage: ./cub3d [map file]\n", 1);
	init_map(&map, argv[1]);
	convert_map_game(&map, &game);
	init_game(&game, &game.img);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &key_exit, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
}
