/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:46:31 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 11:18:59 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_dlist **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value \
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		rotate_a(stack_a, 'a');
	else if ((*stack_a)->next->value > (*stack_a)->value \
			&& (*stack_a)->next->value > (*stack_a)->next->next->value)
		reverse_rotate_a(stack_a, 'a');
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a, 'a');
}

static void	loop_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_b)
	{
		set_target(stack_a, stack_b);
		set_cost_to_top(stack_a, stack_b);
		determine_next_movement(stack_a, stack_b);
	}
}

void	sort_stacks(t_dlist **stack_a, t_dlist **stack_b, int len)
{
	int		i;
	int		median;
	t_dlist	*tmp;

	tmp = *stack_a;
	while (tmp->median == 0)
		tmp = tmp->next;
	median = tmp->value;
	i = -1;
	while (++i < len - 3)
	{
		push_b(stack_a, stack_b);
		if ((*stack_b)->value > median)
			rotate_b(stack_b, 'b');
	}
	if (!check_if_asc_sorted_list(*stack_a))
		sort_three(stack_a);
	else if (!(*stack_b))
		return ;
	loop_sort(stack_a, stack_b);
	finish_sort(stack_a);
}
