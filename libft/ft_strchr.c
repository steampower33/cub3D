/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:42:49 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 09:03:11 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char *)s;
	while (*s_ptr)
	{
		if (*s_ptr == (char)c)
			return (s_ptr);
		s_ptr++;
	}
	if (*s_ptr == (char)c)
		return (s_ptr);
	return (0);
}
