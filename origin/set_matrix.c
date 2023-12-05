/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:55:09 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:56:57 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	str_to_int(int	*dest, char *src, char p)
{
	size_t	index;

	index = 0;
	while (src[index])
	{
		if (src[index] == p)
			dest[index] = 1;
		else if (ft_isdigit(src[index]) == TRUE)
			dest[index] = (int)(src[index] - '0');
		++index;
	}
}

int	**set_matrix(t_map *map)
{
	int		**result;
	size_t	index;

	result = (int **)malloc(sizeof(int *) * map->length);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < map->length)
	{
		result[index] = (int *)malloc(sizeof(int) * map->width);
		if (result[index] == NULL)
		{
			free_double_pointer(result);
			return (NULL);
		}
		str_to_int(result[index], map->cmap(index), map->dir_ch);
		++index;
	}
	return (result);
}
