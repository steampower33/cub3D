# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:17:38 by wooseoki          #+#    #+#              #
#    Updated: 2023/12/16 19:12:22 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

include inc/flag_mkfile
include inc/game_mkfile
include inc/parse_mkfile

all : $(OBJ_DIR) $(NAME)

$(NAME) : $(ALL_OBJS)
	@$(MAKE) -C $(LIB_DIR) all
	@$(MAKE) -C $(MLX_DIR) all
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@ \
	   	$(MLX) -framework OpenGL -framework AppKit

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean

fclean : 
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@$(RM) $(RMFLAGS) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re :
	@$(MAKE) fclean
	@$(MAKE) all
