# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:34:25 by mkerrien          #+#    #+#              #
#    Updated: 2025/02/22 06:42:30 by mkerrien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g3

NAME			= push_swap

NAME_BONUS 		= checker

LIBPATH 		= -Llibft

LIBNAME 		= -lft

SRC				= $(addprefix srcs/, \
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

SRC_BONUS		= $(addprefix srcs/bonus/, \
				  main_bonus.c \
				  checker_bonus.c \
				  checker_bonus_utils.c \
			  	  parsing/parsing_bonus.c \
			  	  parsing/parsing_utils_bonus.c \
				  create_lists_bonus.c \
				  list_basics_bonus.c \
				  list_utils_bonus.c \
				  instructions/instructions_rotate_bonus.c \
				  instructions/instructions_push_bonus.c \
				  instructions/instructions_swap_bonus.c \
				  instructions/instructions_reverse_rotate_bonus.c \
)

INCLUDE			= -Ilibft -Iincludes

OBJ				= $(SRC:.c=.o)

OBJ_BONUS		= $(SRC_BONUS:.c=.o)

all				: $(NAME)

bonus			: $(NAME_BONUS)

%.o 			: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ >>/dev/null

$(NAME)			: $(OBJ)
	@echo "Launching compilation..."
	@make -sC libft >>/dev/null
	@$(CC) $(CFLAGS) $(SRC) $(LIBPATH) $(INCLUDE) $(LIBNAME) -o $(NAME)
	@echo "\nCompilation done !\n"

$(NAME_BONUS)	: $(OBJ_BONUS)
	@echo "Launching bonus compilation..."
	@make -sC libft >>/dev/null
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBPATH) $(INCLUDE) $(LIBNAME) -o $(NAME_BONUS)
	@echo "\nBonus compilation done !\n"

clean			:
	@make clean -sC libft/
	rm -f $(OBJ) $(OBJ_BONUS)

fclean			: clean
	@make fclean -sC libft/
	rm -f $(NAME) $(NAME_BONUS) ./libft/*.a

re				: fclean all

.PHONY			: all bonus clean fclean re
