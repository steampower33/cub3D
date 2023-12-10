/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:15:15 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 22:15:43 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	mirror(t_map *map)
{
	int	row;
	int	col;
	int	temp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width / 2)
		{
			temp = map->matrix[row][col];
			map->matrix[row][col] = map->matrix[row][map->width - col - 1];
			map->matrix[row][map->width -col - 1] = temp;
			++col;
		}
		++row;
	}
	map->player_row = map->width - map->player_row;
}
