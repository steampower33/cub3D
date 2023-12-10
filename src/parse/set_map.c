/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:50:50 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 22:58:47 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	get_color(char *info)
{
	char	**token;
	int		index;
	int		value;
	int		result;

	token = ft_split(info, ',');
	index = 0;
	while (token[index])
		++index;
	if (index != 3)
		error_exit("Color not valid\n", 1);
	index = 0;
	result = 0;
	while (index < 3)
	{
		value = ft_atoi(token[index]);
		if (value == -1)
			error_exit("Color not valid\n", 1);
		result = (result << 8) | value;
		++index;
	}
	free_double_pointer(token);
	return (result);
}

int	get_length(t_node *list)
{
	t_node	*node;
	int		len;

	node = list;
	len = 0;
	while (node)
	{
		++len;
		node = node->next;
	}
	return (len);
}

static int	get_width(char **line)
{
	int		max_width;
	int		len;
	size_t	index;

	max_width = 0;
	index = 0;
	while (line[index])
	{
		len = ft_strlen(line[index]);
		if (max_width < len)
			max_width = len;
		++index;
	}
	return (max_width);
}

static int	**set_matrix(t_map *map)
{
	int	**result;
	int	index;

	result = (int **)malloc(sizeof(int *) * map->height);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < map->height)
	{
		result[index] = (int *)malloc(sizeof(int) * map->width);
		if (result[index] == NULL)
			error_exit("Set matrix failed\n", 1);
		str_to_int(result[index], map->cmap[index], map->dir_ch);
		++index;
	}
	return (result);
}

int	set_map(t_map *map, t_node *list)
{
	map->cmap = list_to_str(list);
	if (map->cmap == NULL)
		return (FAILURE);
	map->height = get_length(list);
	map->width = get_width(map->cmap);
	map->matrix = set_matrix(map);
	if (map->matrix == NULL)
		return (FAILURE);
	if (set_player_info(map) == FAILURE)
		return (FAILURE);
	if (is_valid_map(map) == FALSE)
		return (FAILURE);
	map->floor = get_color(map->info[F]);
	map->ceiling = get_color(map->info[C]);
	return (SUCCESS);
}
