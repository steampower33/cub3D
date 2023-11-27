/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:45:12 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/06 13:06:55 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		read_file(int fd, char **strg);
char	*gnl_substr(char *str, size_t start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *str, int c);
char	*seperate_str(char **strg);
char	*get_next_line(int fd);
size_t	gnl_strlen(char *str);
#endif
