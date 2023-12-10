/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:13:59 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 22:15:12 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_player(t_map *map)
{
	map->plain_row = 0;
	map->plain_col = 0.67;
	map->dir_row = -1;
	map->dir_col = 0;
	/*
	if (map->dir_ch == 'S')
		change_dir(map, K_RIGHT, M_PI_2);
	else if (map->dir_ch == 'W')
		change_dir(map, K_RIGHT, M_PI_2 * 2);
	else if (map->dir_ch == 'N')
		change_dir(map, K_RIGHT, M_PI_2 * 3);
		*/
}
