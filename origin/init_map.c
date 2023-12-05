/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:49:38 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:54:05 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_valid_file_name(char *file)
{
	char	*extens;

	extens = file;
	while (extens)
	{
		if (*extens == '.')
			break;
		++extens;
	}
	if (*extens != '.' || ft_strlen(extens) != 4)
		return (FALSE);
	if (extens[1] != 'c' || extens[2] != 'u' || extens[3] != 'b')
		return (FALSE);
	return (TRUE);
}

int	get_fd(char *file)
{
	int	fd;

	if (is_valid_file_name(file) == FALSE)
		return (FAILURE);
	fd = open(file, O_RDONLY, 644);
	return (fd);
}

int	init_map(t_map *map, char *file)
{
	int	fd;

	fd = get_fd(file);
	if (fd == FAILURE)
		error_exit("Can't open file error\n", 1);
	set_texture_info(map, fd);
	set_map_info(map, fd);
	// test
	test(map);
	return (SUCCESS);
}
