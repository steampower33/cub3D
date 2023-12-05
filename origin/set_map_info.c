/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:42:08 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:55:06 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_node	*create_node(char *line)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (node == NULL)
		return (FAILURE);
	node->content = ft_strdup(line);
	if (node->content == NULL)
		return (FAILURE);
	node->next = NULL;
	node->length = 1;
	return (node);
}

int	lstadd_node(struct s_node **list, char *line)
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
	head->length += 1;
	return (SUCCESS);
}

int	set_map_info(t_map_info *map, int fd)
{
	// exit here
	char	*line;
	t_node	*list;

	list = NULL;
	line = get_next_line(fd);
	while (line && is_empty(line))
		line = get_next_line(fd);
	if (line == NULL)
		error_exit("Failed set map\n", 1);
	while (line)
	{
		if (is_empty(line) == TRUE || lstadd_node(&list, line) == FAILURE)
		{
			free_list(list);
			return (FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	set_map(map, list);
}
