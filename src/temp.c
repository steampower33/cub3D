/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:11:38 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 22:18:11 by wooseoki         ###   ########.fr       */
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

int ft_strtrim(char *str)
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
	if (ft_strtrim(token[1]) == FAILURE)
		return (FAILURE);
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

void	test(t_map *map)
{
	printf("width: %d, height: %d, ceil: %d, floor: %d, door: %d\n", map->width, map->height, map->ceiling, map->floor, map->door_status);
	int i = 0;
	while (i < 8)
	{
		printf("%s\n", map->info[i]);
		i++;
	}
	printf("prow: %f, pcol: %f, %c\n", map->player_row, map->player_col, map->dir_ch);
}

t_node	*create_node(char *line)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->content = ft_strdup(line);
	if (node->content == NULL)
		return (NULL);
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

int	**set_matrix(t_map *map)
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

void	set_player(t_map *map, char** row, char *col)
{
	map->dir_ch = *col;
	*col = '0';
	map->player_row = (double)(col - *row) + 0.5;
	map->player_col = (double)(row - map->cmap) + 0.5;
}

int	set_player_info(t_map *map)
{
	char	**row;
	char	*col;

	row = map->cmap;
	while (*row)
	{
		col = *row;
		while (*col)
		{
			if (ft_strchr("WESN", *col))
			{
				if (map->dir_ch == '\0')
					set_player(map, row, col);
				else
					return (FAILURE);
			}
			else if (!ft_isdigit(*col) && !ft_isspace(*col))
				return (FAILURE);
			col += 1;
		}
		row += 1;
	}
	if (map->dir_ch == '\0')
		return (FAILURE);
	return (SUCCESS);
}

void	dfs(t_map *map, int row, int col, char **cmap)
{
	static const int	delta[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	size_t				index;
	int					next_row;
	int					next_col;

	index = 0;
	while (index < 4)
	{
		next_row = row + delta[0][index];
		next_col = col + delta[1][index];
		if (0 <= next_row && next_row < map->height
			&& 0 <= next_col && next_col < (int)ft_strlen(cmap[next_row])
			&& cmap[next_row][next_col] == '1')
		{
			cmap[next_row][next_col] = map->dir_ch;
			dfs(map, next_row, next_col, cmap);
		}
		++index;
	}
}

int	is_fence(t_map *map, int row, int col)
{
	static const int	delta[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	size_t				index;
	char				**matrix;

	matrix = map->cmap;
	if (row == 0 || col == 0 || row == map->height - 1
			|| col == (int)ft_strlen(matrix[row]) - 1)
		return (TRUE);
	index = 0;
	while (index < 4)
	{
		if (ft_isspace(matrix[row + delta[0][index]][col + delta[1][index]]))
			return (TRUE);
		++index;
	}
	return (FALSE);
}

int	is_delta_empty(t_map *map, int row, int col)
{
	static const int	delta[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	char				**matrix;
	char				c;
	int					index;

	index = 0;
	matrix = map->cmap;
	while (index < 4)
	{
		if (col + delta[1][index] >= (int)ft_strlen(matrix[row + delta[0][index]]))
			c = ' ';
		else
			c = matrix[row + delta[0][index]][col + delta[1][index]];
		if (ft_isspace(c))
		{
			if (matrix[row][col] == map->dir_ch)
				return (FALSE);
			return (TRUE);
		}
		++index;
	}
	return (FALSE);
}

int	is_valid_wall(t_map *map, int row, int col)
{
	char	**matrix;

	matrix = map->cmap;
	if (row == 0 || col == 0 || row == map->height - 1
		|| col == ((int)ft_strlen(matrix[row]) - 1))
	{
		if (matrix[row][col] == map->dir_ch)
			return (TRUE);
		return (FALSE);
	}
	if (is_delta_empty(map, row, col) == TRUE)
	{
		return (FALSE);
	}
	return (TRUE);
}

// 
int	check_fence(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < (int)ft_strlen(map->cmap[row]))
		{
			if (ft_isspace(map->cmap[row][col]))
			{
				if (is_fence(map, row, col) == FALSE)
				{
					//테스트
					printf("it happen?\n");
					return (FAILURE);
				}
			}
			else if (is_valid_wall(map, row, col) == FALSE)
				return (FAILURE);
			++col;
		}
		++row;
	}
	return (SUCCESS);
}

void	change_fence_ch(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		// not needed
		//while (map->cmap[row][col] && map->cmap[row][col] == ' ')
			//++col;
		//if (col == (int)ft_strlen(map->cmap[row]))
			//return (FALSE);
		while (col < (int)ft_strlen(map->cmap[row]))
		{
			if (map->cmap[row][col] == '1' && is_fence(map, row, col) == TRUE)
				dfs(map, row, col, map->cmap);
			++col;
		}
		++row;
	}
}

void	test_convert_map(t_map *map)
{
	int row = 0;

	while (map->cmap[row])
	{
		printf("%s\n", map->cmap[row]);
		++row;
	}
	printf("test map\n");
}

int	is_valid_fence(t_map *map)
{
	change_fence_ch(map);
	if (check_fence(map) == FAILURE)
		return (FALSE);
	return (TRUE);

}

int	is_empty_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] || ft_isspace(str[index]))
		++index;
	if (str[index] == '\0')
		return (FALSE);
	return (TRUE);
}

int	any_empty_line(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		if (is_empty_str(map->cmap[row]) == TRUE)
			return (TRUE);
		++row;
	}
	return (FALSE);
}

int	is_valid_map(t_map *map)
{
	if (any_empty_line(map) == TRUE)
		return (FALSE);
	if (is_valid_fence(map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	get_color(char *info)
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

int	set_map(t_map *map, t_node *list)
{
	map->cmap = list_to_str(list);
	if (map->cmap == NULL)
		return (FAILURE);
	map->height = list->length;
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

void	free_list(t_node *list)
{
	t_node	*node;

	while (list)
	{
		node = list;
		list = list->next;
		free(node);
	}
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

void	init_player(t_map *map)
{
	map->plain_row = 0;
	map->plain_col = 0.67;
	map->dir_row = -1;
	map->dir_col = 0;
	/*
	if (map->dir_ch == 'S')
		change_dir(map, K_RIGHT, M_PI_2);
	else if (map->dir_ch == 'W')
		change_dir(map, K_RIGHT, M_PI_2 * 2);
	else if (map->dir_ch == 'N')
		change_dir(map, K_RIGHT, M_PI_2 * 3);
		*/
}

void	mirror(t_map *map)
{
	int	row;
	int	col;
	int	temp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width / 2)
		{
			temp = map->matrix[row][col];
			map->matrix[row][col] = map->matrix[row][map->width - col - 1];
			map->matrix[row][map->width -col - 1] = temp;
			++col;
		}
		++row;
	}
	map->player_row = map->width - map->player_row;
}

int	init_map(t_map *map, char *file)
{
	int	fd;

	fd = get_fd(file);
	if (fd == FAILURE)
		error_exit("Can't open file error\n", 1);
	if (set_texture_info(map, fd) == FAILURE)
		error_exit("Can't read file\n", 1);
	if (set_map_info(map, fd) == FAILURE)
		error_exit("Set map info failed\n", 1);
	init_player(map);
	//test_convert_map(map);
	mirror(map);
	//test_convert_map(map);
	// test
	//test(map);
	close(fd);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(map));
	if (argc != 2)
	{
		printf("usage: ./cub3D [map file]\n");
		return (1);
	}
	init_map(&map, argv[1]);
}
