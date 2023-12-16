/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:23:25 by seunlee2          #+#    #+#             */
/*   Updated: 2023/12/16 18:41:31 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	key_hook_w(t_player *p, t_mapinfo *map)
{
	if (!map->matrix[(int)(p->pos_y + p->dir_y * p->move_speed * WALLDIST)] \
		[(int)(p->pos_x + p->dir_x * p->move_speed * WALLDIST)])
	{
		p->pos_x += p->dir_x * p->move_speed;
		p->pos_y += p->dir_y * p->move_speed;
	}
}

void	key_hook_s(t_player *p, t_mapinfo *map)
{
	if (!map->matrix[(int)(p->pos_y - p->dir_y * p->move_speed * WALLDIST)] \
		[(int)(p->pos_x - p->dir_x * p->move_speed * WALLDIST)])
	{
		p->pos_x -= p->dir_x * p->move_speed;
		p->pos_y -= p->dir_y * p->move_speed;
	}
}

void	key_hook_a(t_player *p, t_mapinfo *map)
{
	if (!map->matrix[(int)(p->pos_y - p->plane_y * p->move_speed * WALLDIST)] \
		[(int)(p->pos_x - p->plane_x * p->move_speed * WALLDIST)])
	{
		p->pos_x -= p->plane_x * p->move_speed;
		p->pos_y -= p->plane_y * p->move_speed;
	}
}

void	key_hook_d(t_player *p, t_mapinfo *map)
{
	if (!map->matrix[(int)(p->pos_y + p->plane_y * p->move_speed * WALLDIST)] \
		[(int)(p->pos_x + p->plane_x * p->move_speed * WALLDIST)])
	{
		p->pos_x += p->plane_x * p->move_speed;
		p->pos_y += p->plane_y * p->move_speed;
	}
}
