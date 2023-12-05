/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:51:25 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:53:56 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_token_index(char *token)
{
	if (ft_strncmp(token, "NO", 3) == 0)
		return (NO);
	else if (ft_strncmp(token, "SO", 3) == 0)
		return (SO);
	else if (ft_strncmp(token, "WE", 3) == 0)
		return (WE);
	else if (ft_strncmp(token, "EA", 3) == 0)
		return (EA);
	else if (ft_strncmp(token, "F", 2) == 0)
		return (F);
	else if (ft_strncmp(token, "C", 2) == 0)
		return (C);
	return (-1);
}

int	parse_texture(char **token, char **info)
{
	int	index;
	int	len;

	len = 0;
	while (token[len])
		++len;
	if (len != 2)
		return (FAILURE);
	index = get_token_index(token[0]);
	if (index == FAILURE)
		return (FAILURE);
	if (info[index] != NULL)
		return (FAILURE);
	// need free
	info[index] = ft_strdup(token[1]);
	if (info[index] == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	set_info(char **info, char *line)
{
	char	**token;

	token = ft_split(line, ' ');
	if (token == NULL)
		return (FAILURE);
	if (parse_texture(token, info) == FAILURE)
		return (FAILURE);
	free_double_pointer(token);
	return (SUCCESS);
}

int	set_texture_info(t_map *map, int fd)
{
	int		index;
	char	*line;

	index = 0;
	while (index < INFO_LINE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_empty(line) == TRUE)
			continue ;
		if (set_info(map->info, line) == FAILURE)
			error_exit("Failed set info\n", 1);
		free(line);
		line = NULL;
		++index;
	}
	if (index != INFO_LINE)
		return (SUCCESS);
	if (line != NULL)
		free(line);
	return (FAILURE);
}
