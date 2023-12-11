# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 16:31:06 by wooseoki          #+#    #+#              #
#    Updated: 2023/12/11 19:48:14 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc
RM = rm
RMFLAGS = -f
SRCS = ft_split.c \
		ft_substr.c \
		ft_strncmp.c \
		ft_strjoin.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_strchr.c \
		ft_isspace.c \
		ft_atoi.c \
		ft_memset.c \
		get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE)	all

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
