/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:12:28 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 16:56:42 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	str_to_int(int *dest, char *src, char p)
{
	int	index;

	index = 0;
	while (src[index])
	{
		if (src[index] == p)
			dest[index] = 1;
		else if (ft_isdigit(src[index]))
			dest[index] = (int)(src[index] - '0');
		++index;
	}
}

int	get_fd(char *file)
{
	int	fd;

	if (is_valid_file_name(file) == FALSE)
		return (FAILURE);
	fd = open(file, O_RDONLY, 644);
	return (fd);
}

void	free_list(t_node *list)
{
	t_node	*node;

	while (list)
	{
		node = list;
		list = list->next;
		free(node->content);
		free(node);
	}
}

int	is_empty(char *line)
{
	int	index;

	index = 0;
	while (ft_isspace(line[index]) || line[index] == '\n')
		++index;
	if (ft_strlen(&line[index]) == 0)
	{
		free(line);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_strtrim(char *str)
{
	int		index;

	if (str == NULL)
		return (FAILURE);
	index = ft_strlen(str);
	if (index == 0)
		return (SUCCESS);
	--index;
	while (index)
	{
		if (ft_isspace(str[index]))
		{
			str[index] = '\0';
			--index;
		}
		else
			break ;
	}
	return (SUCCESS);
}
