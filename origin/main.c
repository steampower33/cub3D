/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:48:25 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/05 20:49:05 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
