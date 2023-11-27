/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:11:04 by wooseoki          #+#    #+#             */
/*   Updated: 2023/01/19 15:42:22 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *str, char delimiter)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (!flag && *str == delimiter)
			flag = 1;
		else if (flag && *str != delimiter)
		{
			flag = 0;
			count++;
		}
		str++;
	}
	return (count);
}

char	*duplicate_str(char	const *str, size_t start_index, size_t end_index)
{
	char	*mock;
	size_t	index;

	mock = (char *)malloc((end_index - start_index + 1));
	if (!mock)
		return (0);
	index = 0;
	while (start_index + index < end_index)
	{
		mock[index] = str[start_index + index];
		index++;
	}
	mock[index] = '\0';
	return (mock);
}

static void	seperate_str(char **dest, char const *str, char delimiter)
{
	size_t	start_index;
	size_t	str_index;
	size_t	dst_index;
	size_t	flag;

	flag = 0;
	str_index = 0;
	dst_index = 0;
	while (str[str_index])
	{
		if (!flag && (str[str_index] != delimiter))
		{
			flag = 1;
			start_index = str_index;
		}
		else if (flag && (str[str_index] == delimiter))
		{
			flag = 0;
			dest[dst_index++] = duplicate_str(str, start_index, str_index);
		}
		if (flag && !str[str_index + 1])
			dest[dst_index++] = duplicate_str(str, start_index, str_index + 1);
		str_index++;
	}
	dest[dst_index] = 0;
}

static size_t	free_memory(char ***result, size_t len)
{
	char	**temp;
	size_t	index;
	size_t	index2;

	temp = *result;
	index = 0;
	while (index < len)
	{
		if (!temp[index])
		{
			index2 = 0;
			while (index2 < len)
			{
				if (temp[index2])
					free(temp[index2]);
				index2++;
			}
			free(temp);
			return (1);
		}
		index++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_len;

	word_len = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (word_len + 1));
	if (!result)
		return (0);
	seperate_str(result, s, c);
	if (free_memory(&result, word_len))
		return (0);
	return (result);
}
