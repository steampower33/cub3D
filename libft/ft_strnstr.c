/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:52:41 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 09:09:11 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_index;
	size_t	nd_index;

	if (*needle == '\0')
		return ((char *)haystack);
	hs_index = 0;
	while (hs_index < len && haystack[hs_index])
	{
		nd_index = 0;
		while (needle[nd_index] && hs_index + nd_index < len && \
				needle[nd_index] == haystack[hs_index + nd_index])
			nd_index++;
		if (needle[nd_index] == '\0')
			return ((char *)haystack + hs_index);
		hs_index++;
	}
	return (0);
}
