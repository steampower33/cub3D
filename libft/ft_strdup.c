/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:31:42 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 17:08:44 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dst;
	char	*ret;

	s1_len = strlen(s1);
	dst = (char *)malloc(s1_len + 1);
	if (!dst)
		return (0);
	ret = dst;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (ret);
}
