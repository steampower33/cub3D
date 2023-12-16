/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:22:51 by seunlee2          #+#    #+#             */
/*   Updated: 2023/12/16 19:43:27 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	key_hook_l(t_player *p)
{
	p->dir_x = p->dir_x * cos(-p->rot_speed) - p->dir_y * sin(-p->rot_speed);
	p->dir_y = p->dir_x * sin(-p->rot_speed) + p->dir_y * cos(-p->rot_speed);
	p->plane_x = \
		p->plane_x * cos(-p->rot_speed) - p->plane_y * sin(-p->rot_speed);
	p->plane_y = \
		p->plane_x * sin(-p->rot_speed) + p->plane_y * cos(-p->rot_speed);
}

void	key_hook_r(t_player *p)
{
	p->dir_x = p->dir_x * cos(p->rot_speed) - p->dir_y * sin(p->rot_speed);
	p->dir_y = p->dir_x * sin(p->rot_speed) + p->dir_y * cos(p->rot_speed);
	p->plane_x = \
		p->plane_x * cos(p->rot_speed) - p->plane_y * sin(p->rot_speed);
	p->plane_y = \
		p->plane_x * sin(p->rot_speed) + p->plane_y * cos(p->rot_speed);
}

void	key_hook(t_game *game)
{
	if (game->p.move.key_w)
		key_hook_w(&game->p, &game->map);
	if (game->p.move.key_s)
		key_hook_s(&game->p, &game->map);
	if (game->p.move.key_a)
		key_hook_a(&game->p, &game->map);
	if (game->p.move.key_d)
		key_hook_d(&game->p, &game->map);
	if (game->p.move.key_l)
		key_hook_l(&game->p);
	if (game->p.move.key_r)
		key_hook_r(&game->p);
}
