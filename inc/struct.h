/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:20:41 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/06 17:27:32 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

#define FAILURE		-1
#define SUCCESS		1
#define TRUE		1
#define	FALSE		0
#define INFO_LINE 	6

enum	e_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	LINE_INFO,
};

enum	e_dir
{
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_Q = 12,
	K_W = 13,
	K_E = 14,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT = 124
};

typedef struct	s_node
{
	char*			content;
	size_t			length;
	struct s_node	*next;
}t_node;

typedef struct s_map
{
	int		width;
	int		height;
	int		ceiling;
	int		floor;
	int		door_status;
	char	dir_ch;
	double	player_row;
	double	player_col;
	double	plain_row;
	double	plain_col;
	double	dir_row;
	double	dir_col;
	int		**matrix;
	char	*info[8];
	char	**cmap;

}t_map;

int	set_info(char **info, char *line);
int	parse_texture(char **token, char **info);
int	is_valid_file_name(char *file);
int	is_empty(char *line);
int	get_token_index(char *token);
int	set_map_info(t_map *map, int fd);

#endif
