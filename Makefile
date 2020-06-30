# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 15:08:28 by kbessa            #+#    #+#              #
#    Updated: 2020/02/29 19:49:22 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

CFLAGS		=	-g -Wall -Wextra -Werror

FILES		=	belmonford_alg.c 	belmonford_some.c 		change_link.c			\
				collision_remove.c 	pointer_to_extreme.c 	remove_common_edges.c	\
				split_in_out.c 		surrballe_alg.c 		check_duplicates.c 		\
				check_hash.c 		get_ants.c				get_graph.c				\
				graph_delete.c		is_link.c				is_room.c				\
				new_room.c			search_the_same.c		set_links.c				\
				start_solution.c	start_ants.c			sort_paths.c			\
				validation.c		arraylist_func.c		free_functions.c		\
				lem_in.c			length_path.c			lst_rooms.c				\
				main.c				search_links.c			some_func.c				\
				print_ant.c			step_one.c

DIR_SRC		=	./src/

SRC_CHECKER	=	$(addprefix $(DIR_SRC),$(FILES))
OBJECTS     =	$(addprefix $(DIR_SRC),$(FILES:.c=.o))

LIB_DIR		=	libft/
LIBFT		=	$(LIB_DIR)libft.a

.PHONY: all clean fclean re

all:		$(NAME)

lem-in:		$(OBJECTS)
			@echo "Compiling libft"
			@make -C $(LIB_DIR)
			@echo "Compiling lem-in"
			@gcc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
			@echo "Done"

clean:
			@rm -rf $(OBJECTS)
			@make -C $(LIB_DIR) clean

fclean:		clean
			@echo "$(RED)deleting lem-in executable files...$(NC) ✔"
			@rm -rf $(NAME)

debug:
			@echo $(OBJECTS)
			@echo $(SRC_CHECKER)

re:			fclean all