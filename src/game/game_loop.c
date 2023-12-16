/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:50:26 by seunlee2          #+#    #+#             */
/*   Updated: 2023/12/16 21:52:10 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	set_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREENHEIGHT / 2)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			game->img.buffer[y][x] = game->map.ceiling;
			game->img.buffer[SCREENHEIGHT - y - 1][x] = game->map.floor;
			x++;
		}
		y++;
	}
}

void	put_img(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			game->img.data[y * SCREENWIDTH + x] = game->img.buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.image, 0, 0);
}

int	game_loop(t_game *game)
{
	set_floor(game);
	raycasting(game);
	put_img(game);
	key_hook(game);
	return (0);
}
