/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:37:15 by seunlee2          #+#    #+#             */
/*   Updated: 2023/12/16 19:41:20 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->p.move.key_w = 1;
	if (keycode == KEY_S)
		game->p.move.key_s = 1;
	if (keycode == KEY_A)
		game->p.move.key_a = 1;
	if (keycode == KEY_D)
		game->p.move.key_d = 1;
	if (keycode == KEY_LEFT)
		game->p.move.key_l = 1;
	if (keycode == KEY_RIGHT)
		game->p.move.key_r = 1;
	if (keycode == KEY_ESC)
		key_exit(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->p.move.key_w = 0;
	if (keycode == KEY_S)
		game->p.move.key_s = 0;
	if (keycode == KEY_A)
		game->p.move.key_a = 0;
	if (keycode == KEY_D)
		game->p.move.key_d = 0;
	if (keycode == KEY_LEFT)
		game->p.move.key_l = 0;
	if (keycode == KEY_RIGHT)
		game->p.move.key_r = 0;
	if (keycode == KEY_ESC)
		key_exit(game);
	return (0);
}

int	key_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}
