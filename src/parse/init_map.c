/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:43:17 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 22:16:39 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	init_player(t_map *map)
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

static void	mirror(t_map *map)
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

int	init_map(t_map *map, char *file)
{
	int	fd;

	fd = get_fd(file);
	if (fd == FAILURE)
		error_exit("Can't open file error\n", 1);
	if (set_texture_info(map, fd) == FAILURE)
		error_exit("Can't read file\n", 1);
	if (set_map_info(map, fd) == FAILURE)
		error_exit("Set map info failed\n", 1);
	init_player(map);
	//test_convert_map(map);
	mirror(map);
	//test_convert_map(map);
	// test
	//test(map);
	close(fd);
	return (SUCCESS);
}
