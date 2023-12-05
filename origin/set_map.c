/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:44:35 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:53:39 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_width(char **line)
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


char	**list_to_str(t_node *list)
{
	char		**result;
	t_node		*node;
	size_t		index;

	node = list;
	result = (char **)malloc(sizeof(char *) * (list->length + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (node)
	{
		result[index] = ft_strdup(node->content);
		if (result[index] == NULL)
		{
			free_double_pointer(result);
			return (NULL);
		}
		node = node->next;
		++index;
	}
	result[index] = NULL;
	return (result);
}

int	set_map(t_map *map, t_node list)
{
	map->height = list->length;
	map->matrix = set_matrix(map);
	if (map->matrix == NULL)
		return (FAIURE);
	map->cmap = list_to_str(list);
	if (map->cmap == NULL)
		return (FAILURE);
	map->width = get_width(map->cmap);
	if (set_player_info(map) == FAILURE)
		return (FAILURE);
	if (is_valid_map(map) == FAILURE)
		return (FAILURE);
}
