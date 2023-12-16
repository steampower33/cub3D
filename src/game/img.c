/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:42:16 by seunlee2          #+#    #+#             */
/*   Updated: 2023/12/16 21:09:18 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	fill_texture(t_img *img, int idx)
{
	int	w;
	int	h;

	h = 0;
	while (h < img->h)
	{
		w = 0;
		while (w < img->w)
		{
			img->texture[idx][img->w * h + w] = img->data[img->w * h + w];
			w++;
		}
		h++;
	}
}

void	set_wall_img(t_game *game, t_img *img, t_mapinfo *map, int idx)
{
	while (idx < 4)
	{
		if (idx == 0)
			img->image = mlx_xpm_file_to_image \
				(game->mlx, map->info[3], &img->w, &img->h);
		else if (idx == 1)
			img->image = mlx_xpm_file_to_image \
				(game->mlx, map->info[2], &img->w, &img->h);
		else if (idx == 2)
			img->image = mlx_xpm_file_to_image \
				(game->mlx, map->info[1], &img->w, &img->h);
		else if (idx == 3)
			img->image = mlx_xpm_file_to_image \
				(game->mlx, map->info[0], &img->w, &img->h);
		if (img->w != TEXWIDTH || img->h != TEXHEIGHT || img->image == NULL)
			return ;
		img->data = (int *)mlx_get_data_addr \
			(img->image, &img->bpp, &img->line_size, &img->endian);
		fill_texture(&game->img, idx);
		mlx_destroy_image(game->mlx, game->img.image);
		idx++;
	}
}
