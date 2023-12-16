/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:59:21 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 16:16:53 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	set_player(t_map *map, char **row, char *col)
{
	map->dir_ch = *col;
	*col = '0';
	map->player_row = (double)(col - *row) + 0.5;
	map->player_col = (double)(row - map->cmap) + 0.5;
}

int	set_player_info(t_map *map)
{
	char	**row;
	char	*col;

	row = map->cmap;
	while (*row)
	{
		col = *row;
		while (*col)
		{
			if (ft_strchr("WESN", *col))
			{
				if (map->dir_ch == '\0')
					set_player(map, row, col);
				else
					return (FAILURE);
			}
			else if (!ft_isdigit(*col) && !ft_isspace(*col))
				return (FAILURE);
			col += 1;
		}
		row += 1;
	}
	if (map->dir_ch == '\0')
		return (FAILURE);
	return (SUCCESS);
}
