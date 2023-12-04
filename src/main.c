/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:11:38 by wooseoki          #+#    #+#             */
/*   Updated: 2023/11/27 21:27:13 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

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

void	error_exit(char *message, int status)
{
	printf("%s", message);
	exit(status);
}

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

void	free_double_pointer(char **string)
{
	size_t	index;

	index = 0;
	while (string[index])
	{
		free(string[index]);
		++index;
	}
	free(string);
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

int	is_space(char c)
{
	if (c == 20 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_empty(char *line)
{
	int	index;

	index = 0;
	while (is_space(line[index]) || line[index] == '\n')
		++index;
	if (ft_strlen(&line[index]) == 0)
	{
		free(line);
		return (TRUE);
	}
	return (FALSE);
}

int	set_texture_info(t_map_info *map, int fd)
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

void	test(t_map_info *map)
{
	printf("width: %d, height: %d, ceil: %d, floor: %d, door: %d\n", map->width, map->height, map->ceilling, map->floor, map->door_status);
	int i = 0;
	while (i < 8)
	{
		printf("%s", map->info[i]);
		i++;
	}
}

int	create_node(char *line)
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
	head->size += 1;
	return (SUCCESS);
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

int	**set_matrix(t_map_info *map)
{
	int		**result;
	size_t	index;

	result = (int **)malloc(sizeof(int *) * list->length);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < list->length)
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

int	set_player_info(t_map_info *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->cmap[i])
	{
		j = 0;
		while (map->cmap[i][j])
		{
			if (ft_strchr("WESN", map->cmap[i][j]))
			{
				if (map->dir_ch == '\0')
					set_player(map, i, j);
				else
					return (FAILURE);
			}
			else if (!ft_isdigit(map->cmap[i][j]) && !ft_isspace(map->cmap[i][j])
				return (FAILURE);
			++j;
		}
		++i;
	}
	if (map->dir_ch == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int	is_valid_map(t_map_info *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (m->cmap[row][col] && m->cmap[row][col] == ' ')
			++col;
		if (col == ft_strlen(map->cmap[row]))
			return (FAILURE);
		while (col < ft_strlen(m->cmap[row]))
		{
			if (map->cmap[row][col] == '1' && is_empty)
		}
	}
}

int	set_map(t_map_info *map, t_node list)
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

int	init_map(t_map_info *map, char *file)
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

int main(int argc, char **argv)
{
	t_map_info	map;

	ft_bzero(&map, sizeof(map));
	if (argc != 2)
	{
		printf("usage: ./cub3D [map file]\n");
		return (1);
	}
	init_map(&map, argv[1]);


}
