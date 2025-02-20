# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:34:25 by mkerrien          #+#    #+#              #
#    Updated: 2025/02/19 19:48:33 by mkerrien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= push_swap 

LIBPATH = -Llibft

LIBNAME = -lft

SRC		= 	$(addprefix srcs/, \
			main.c \
			parsing/parsing.c \
			parsing/parsing_utils.c \
			create_lists.c \
			list_basics.c \
			list_utils.c \
			instructions/instructions_rotate.c \
			instructions/instructions_push.c \
			instructions/instructions_swap.c \
			instructions/instructions_reverse_rotate.c \
			sort/simple_sort.c \
			sort/sorting1.c \
			sort/sorting2.c \
			sort/cost_and_target.c)

INCLUDE	= -Ilibft -Iincludes

OBJ		= $(SRC:.c=.o)

all		: $(NAME)

%.o 			: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ >>/dev/null

$(NAME)	: $(OBJ)
	@echo "Launching compilation..."
	@make -sC libft >>/dev/null
	@$(CC) $(CFLAGS) $(SRC) $(LIBPATH) $(INCLUDE) $(LIBNAME) -o $(NAME)
	@echo "\nCompilation done !\n"

clean	:
	@make clean -sC libft/
	rm -f $(OBJ)

fclean	: clean
	@make fclean -sC libft/
	rm -f $(NAME) ./libft/*.a

re		: fclean all

.PHONY	: all clean fclean re
