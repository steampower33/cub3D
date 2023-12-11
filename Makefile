# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:17:38 by wooseoki          #+#    #+#              #
#    Updated: 2023/12/11 16:08:51 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

include inc/flag_mkfile
include inc/parse_mkfile

$(LIBFT) :
	@$(MAKE) -C $(LIB_DIR)

all : $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME) : $(ALL_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@ -g

$(MLX) :
	$(MAKE) -I $(INC_DIR) -I ../libft/ -C $(LIBFT) $(MLX_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : 
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@$(RM) $(RMFLAGS) $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re :
	@$(MAKE) fclean
	@$(MAKE) all
