/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:57:04 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:58:34 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	set_player_info(t_map_info *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->cmap[i])
	{
		j = 0;
		while (map->cmap[i][j])
		{
			if (ft_strchr("WESN", map->cmap[i][j]))
			{
				if (map->dir_ch == '\0')
					set_player(map, i, j);
				else
					return (FAILURE);
			}
			else if (!ft_isdigit(map->cmap[i][j]) && !ft_isspace(map->cmap[i][j])
				return (FAILURE);
			++j;
		}
		++i;
	}
	if (map->dir_ch == '\0')
		return (FAILURE);
	return (SUCCESS);
}
