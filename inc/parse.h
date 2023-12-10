/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:18:03 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/10 23:02:47 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "struct.h"

/* init_map.c */
int	init_map(t_map *map, char *file);

/* set_texture.c */
int	set_texture_info(t_map *map, int fd);

/* set_map.c */
int	get_length(t_node *list);
int	set_map(t_map *map, t_node *list);

/* set_map_info.c */
int	set_map_info(t_map *map, int fd);

/* set_player_info.c */
int	set_player_info(t_map *map);

/* is_valid_map.c */
int	is_valid_map(t_map *map);

/* check_fence.ca */
int	check_fence(t_map *map);
int	is_fence(t_map *map, int row, int col);

/* utils.c */
int	is_valid_file_name(char *file);
int	get_fd(char *file);
int	is_empty(char *line);
int	ft_strtrim(char *str);
char	**list_to_str(t_node *list);
void	error_exit(char*message, int status);
void	free_double_pointer(char **string);
void	str_to_int(int *dest, char *src, char p);
void	free_list(t_node *list);
#endif
