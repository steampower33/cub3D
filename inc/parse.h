/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:18:03 by wooseoki          #+#    #+#             */
/*   Updated: 2023/12/16 18:22:58 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "struct.h"

int		init_map(t_map *map, char *file);
int		set_texture_info(t_map *map, int fd);
int		get_length(t_node *list);
int		set_map(t_map *map, t_node *list);
int		set_map_info(t_map *map, int fd);
int		set_player_info(t_map *map);
int		is_valid_map(t_map *map);
int		check_fence(t_map *map);
int		is_fence(t_map *map, int row, int col);
int		is_valid_file_name(char *file);
int		get_fd(char *file);
int		is_empty(char *line);
int		ft_strtrim(char *str);
char	**list_to_str(t_node *list);
void	error_exit(char*message, int status);
void	free_double_pointer(char **string);
void	str_to_int(int *dest, char *src, char p);
void	free_list(t_node *list);
#endif
