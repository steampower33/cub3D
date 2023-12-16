/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:00:11 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 16:15:48 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_empty_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] || ft_isspace(str[index]))
		++index;
	if (str[index] == '\0')
		return (FALSE);
	return (TRUE);
}

static int	any_empty_line(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		if (is_empty_str(map->cmap[row]) == TRUE)
			return (TRUE);
		++row;
	}
	return (FALSE);
}

static void	dfs(t_map *map, int row, int col, char **cmap)
{
	static const int	delta[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	size_t				index;
	int					next_row;
	int					next_col;

	index = 0;
	while (index < 4)
	{
		next_row = row + delta[0][index];
		next_col = col + delta[1][index];
		if (0 <= next_row && next_row < map->height
			&& 0 <= next_col && next_col < (int)ft_strlen(cmap[next_row])
			&& cmap[next_row][next_col] == '1')
		{
			cmap[next_row][next_col] = map->dir_ch;
			dfs(map, next_row, next_col, cmap);
		}
		++index;
	}
}

static void	change_fence_ch(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (map->cmap[row][col] && map->cmap[row][col] == ' ')
			++col;
		if (col == (int)ft_strlen(map->cmap[row]))
			return ;
		while (col < (int)ft_strlen(map->cmap[row]))
		{
			if (map->cmap[row][col] == '1' && is_fence(map, row, col) == TRUE)
				dfs(map, row, col, map->cmap);
			++col;
		}
		++row;
	}
}

int	is_valid_map(t_map *map)
{
	if (any_empty_line(map) == TRUE)
		return (FALSE);
	change_fence_ch(map);
	if (check_fence(map) == FAILURE)
		return (FALSE);
	return (TRUE);
}
