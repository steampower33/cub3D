/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:00:37 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/01 16:54:37 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*seperate_str(char **strg)
{
	size_t	index;
	char	*line;
	char	*free_strg;

	index = 0;
	while ((*strg)[index] && (*strg)[index] != '\n')
		index++;
	if (!(*strg)[index] && !index)
		return (0);
	free_strg = *strg;
	line = gnl_substr(*strg, 0, index + 1);
	*strg = gnl_substr(*strg, index + 1, gnl_strlen(*strg));
	free(free_strg);
	return (line);
}

int	read_file(int fd, char **strg)
{
	char	*buf;
	char	*temp;
	ssize_t	read_size;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	read_size = 1;
	while (!gnl_strchr(*strg, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		temp = *strg;
		*strg = gnl_strjoin(temp, buf);
		free(temp);
	}
	free(buf);
	if (read_size < 0)
		return (0);
	return (1);
}

char	*init_strg(void)
{
	char	*result;

	result = (char *)malloc(1);
	if (!result)
		return (0);
	*result = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*strg;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!strg)
		strg = init_strg();
	if (!strg)
		return (0);
	if (!read_file(fd, &strg))
	{
		free(strg);
		strg = 0;
		return (0);
	}
	line = seperate_str(&strg);
	if (!line)
	{
		free(strg);
		strg = 0;
		return (0);
	}
	return (line);
}
