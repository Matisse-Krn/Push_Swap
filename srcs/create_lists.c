/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:21:16 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 11:19:45 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlist	*init_stack_a(int *tab, int len, t_dlist *stack_b)
{
	t_dlist	*stack_a;

	tab_to_list(&stack_a, tab, len);
	if (check_if_asc_sorted_list(stack_a) == 1)
	{
		free_list(stack_a);
		stack_a = NULL;
		free(tab);
		return (NULL);
	}
	else if (check_if_desc_sorted_list(stack_a) == 1)
	{
		reverse_list(&stack_a, &stack_b, len);
		free_list(stack_a);
		free(tab);
		exit(0);
	}
	return (stack_a);
}

static void	set_median(int *sort, int len, t_dlist **stack_a)
{
	int		i;
	t_dlist	*tmp;

	if (!stack_a || !sort || len < 2)
		return ;
	i = -1;
	while (++i != (len / 2))
		;
	tmp = *stack_a;
	while (tmp->value != sort[i])
		tmp = tmp->next;
	tmp->median = 1;
}

void	create_lists(t_dlist **stack_a, t_dlist **stack_b, int *tab, int len)
{
	int		*sort;

	*stack_a = init_stack_a(tab, len, *stack_b);
	if (!(*stack_a))
	{
		free_list(*stack_b);
		return ;
	}
	sort = ft_calloc(len, sizeof(int));
	if (!sort)
		return ;
	sort_tab(tab, sort, len);
	if (!sort)
		free(stack_a);
	set_final_position(sort, len, stack_a);
	set_median(sort, len, stack_a);
	free(sort);
}
