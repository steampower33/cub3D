/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:09:06 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 16:14:04 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_delta_empty(t_map *map, int row, int col)
{
	static const int	delta[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	char				**matrix;
	char				c;
	int					index;

	index = 0;
	matrix = map->cmap;
	while (index < 4)
	{
		if (col + delta[1][index] >= \
			(int)ft_strlen(matrix[row + delta[0][index]]))
			c = ' ';
		else
			c = matrix[row + delta[0][index]][col + delta[1][index]];
		if (ft_isspace(c))
		{
			if (matrix[row][col] == map->dir_ch)
				return (FALSE);
			return (TRUE);
		}
		++index;
	}
	return (FALSE);
}

static int	is_valid_wall(t_map *map, int row, int col)
{
	char	**matrix;

	matrix = map->cmap;
	if (row == 0 || col == 0 || row == map->height - 1
		|| col == ((int)ft_strlen(matrix[row]) - 1))
	{
		if (matrix[row][col] == map->dir_ch)
			return (TRUE);
		return (FALSE);
	}
	if (is_delta_empty(map, row, col) == TRUE)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	is_fence(t_map *map, int row, int col)
{
	static const int	delta[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	size_t				index;
	char				**matrix;

	matrix = map->cmap;
	if (row == 0 || col == 0 || row == map->height - 1
		|| col == (int)ft_strlen(matrix[row]) - 1)
		return (TRUE);
	index = 0;
	while (index < 4)
	{
		if (ft_isspace(matrix[row + delta[0][index]][col + delta[1][index]]))
			return (TRUE);
		++index;
	}
	return (FALSE);
}

int	check_fence(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < (int)ft_strlen(map->cmap[row]))
		{
			if (ft_isspace(map->cmap[row][col]))
			{
				if (is_fence(map, row, col) == FALSE)
					return (FAILURE);
			}
			else if (is_valid_wall(map, row, col) == FALSE)
				return (FAILURE);
			++col;
		}
		++row;
	}
	return (SUCCESS);
}
