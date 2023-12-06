/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:04:43 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/06 17:24:29 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_neg(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

static int	convert_str(const char *str, size_t index, size_t neg)
{
	long long	number;

	number = 0;
	while (isdigit(str[index]))
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	if (neg)
		number *= -1;
	return (number);
}

int	ft_atoi(const char *str)
{
	size_t		index;
	size_t		neg;
	int			number;

	index = 0;
	while (isspace(str[index]))
		index++;
	neg = is_neg(str[index]);
	if (str[index] == '-' || str[index] == '+')
		index++;
	if (neg)
		return (-1);
	number = convert_str(str, index, neg);
	if (number > 255)
		return (-1);
	return (number);
}
