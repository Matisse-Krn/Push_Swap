/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:00:20 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:40:55 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <limits.h>

typedef struct s_dlist
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	int				median;
	char			name;
	struct s_dlist	*target;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

int		parsing_check(char **list);
int		str_is_zero(char *s);
int		real_length(char *s);
char	*delete_surplus(char *s);
int		*convert_str_to_tab(char **s, int *len);
void	free_str(char **tabtab);

t_dlist	*dlst_new(int value, int index, char name);
void	tab_to_list(t_dlist **stack_a, int *tab, int len);
void	dlst_add_last(t_dlist **dlst, t_dlist *new);
void	free_list(t_dlist *head);
int		dlst_size(t_dlist **stack);
void	sort_tab(int *tab, int *sort, int len);

void	reassign_index(t_dlist **stack_a, t_dlist **stack_b);
int		create_lists(t_dlist **stack_a, t_dlist **stack_b, int *tab, int len);
int		check_if_asc_sorted_list(t_dlist *stack);
int		check_if_desc_sorted_list(t_dlist *stack);
int		*set_final_position(int *tab, int len, t_dlist **stack);

void	push_a(t_dlist **stack_a, t_dlist **stack_b);
void	push_b(t_dlist **stack_a, t_dlist **stack_b);
void	swap_a(t_dlist **stack_a, char name);
void	swap_b(t_dlist **stack_b, char name);
void	swap_s(t_dlist **stack_a, t_dlist **stack_b, char name);
void	rotate_a(t_dlist **stack_a, char name);
void	rotate_b(t_dlist **stack_b, char name);
void	rotate_r(t_dlist **stack_a, t_dlist **stack_b, char name);
void	reverse_rotate_a(t_dlist **stack_a, char name);
void	reverse_rotate_b(t_dlist **stack_b, char name);
void	reverse_rotate_r(t_dlist **stack_a, t_dlist **stack_b, char name);

int		checker_instructions(t_dlist **stack_a, t_dlist **stack_b);
void	exec_all(t_dlist **stack_a, t_dlist **stack_b, char **tab);
void	push_a_bonus(t_dlist **stack_a, t_dlist **stack_b);
void	push_b_bonus(t_dlist **stack_a, t_dlist **stack_b);
void	swap_a_bonus(t_dlist **stack_a);
void	swap_b_bonus(t_dlist **stack_b);
void	swap_s_bonus(t_dlist **stack_a, t_dlist **stack_b);
void	rotate_a_bonus(t_dlist **stack_a);
void	rotate_b_bonus(t_dlist **stack_b);
void	rotate_r_bonus(t_dlist **stack_a, t_dlist **stack_b);
void	reverse_rotate_a_bonus(t_dlist **stack_a);
void	reverse_rotate_b_bonus(t_dlist **stack_b);
void	reverse_rotate_r_bonus(t_dlist **stack_a, t_dlist **stack_b);

// TEMPORAIRES :
/*void test_push(t_dlist **stack_a, t_dlist **stack_b);
void	print_stack(t_dlist *stack, char name);
void	print_stacks(t_dlist **stack_a, t_dlist **stack_b);
*/
#endif
