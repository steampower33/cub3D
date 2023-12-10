/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:49:23 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 22:48:51 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_node	*create_node(char *line)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->content = ft_strdup(line);
	if (node->content == NULL)
		return (NULL);
	node->next = NULL;
	return (node);
}

static int	lstadd_node(struct s_node **list, char *line)
{
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	head = *list;
	node = create_node(line);
	if (node == NULL)
		return (FAILURE);
	if (head == NULL)
	{
		*list = node;
		return (SUCCESS);
	}
	tail = head;
	while (tail->next)
		tail = tail->next;
	tail->next = node;
	return (SUCCESS);
}

int	set_map_info(t_map *map, int fd)
{
	char	*line;
	t_node	*list;

	list = NULL;
	line = get_next_line(fd);
	while (line && is_empty(line))
		line = get_next_line(fd);
	if (line == NULL)
		error_exit("Can't read map content\n", 1);
	while (line)
	{
		if (ft_strtrim(line) == SUCCESS || lstadd_node(&list, line) == FAILURE)
		{
			free_list(list);
			return (FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (set_map(map, list));
}
