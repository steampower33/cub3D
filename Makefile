# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:17:38 by wooseoki          #+#    #+#              #
#    Updated: 2023/11/27 21:00:53 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.default_goal = all

NAME = cub3D
# MLX = ./mlx/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
# MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm
RMFLAGS = -rf
LDFLAGS = -L libft/
LIBFT = libft/libft.a
SRC = \
	  main.c

OBJ = $(SRC:.c=.o)
SRC_DIR = src/
OBJ_DIR = obj/
MLX_DIR = mlx/
INC_DIR = inc/
LIB_DIR = libft/

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
SRCS = $(addprefix $(SRC_DIR), $(SRC))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -I $(INC_DIR) $< -o $@

$(LIBFT) :
	@$(MAKE) -C $(LIB_DIR)

all : $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(MLX) :
	$(MAKE) -I $(INC_DIR) -I ../libft/ -C $(LIBFT) $(MLX_DIR)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : 
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@$(RM) $(RMFLAGS) $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re :
	@$(MAKE) fclean
	@$(MAKE) all
