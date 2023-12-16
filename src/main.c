/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:11:38 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 16:52:02 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	test(t_map *map)
{
	printf("width: %d, height: %d, ceil: %d, floor: %d, door: %d\n", map->width, map->height, map->ceiling, map->floor, map->door_status);
	int i = 0;
	while (i < 6)
	{
		printf("%s\n", map->info[i]);
		i++;
	}
	printf("prow: %f, pcol: %f, %c\n", map->player_row, map->player_col, map->dir_ch);
}

void	test_convert_map(t_map *map)
{
	int row = 0;
	int col;

	printf("======================test map===========================\n");
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			printf("%d", map->matrix[row][col]);
			++col;
		}
		printf("\n");
		++row;
	}
	test(map);
	printf("======================test map===========================\n");
}

int	main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(map));
	if (argc != 2)
		error_exit("usage: ./cub3d [map file]\n", 1);
	init_map(&map, argv[1]);
	system("leaks --list -- cub3D");
	//test_convert_map(&map);
}
