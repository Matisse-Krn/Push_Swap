/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:36:49 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 11:18:06 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Return 0 if no need to move, return -1 if reverse_rotate_b is needed, else
 * return 1 if rotate_b is needed
*/
int	move_to_top(t_dlist *to_move, t_dlist **stack)
{
	int	len;

	if (!to_move)
		return (0);
	len = dlst_size(stack);
	if (to_move->index != 0)
	{
		if (to_move->index <= (len / 2))
			return (1);
		else
			return (-1);
	}
	return (0);
}

static void	optimize_movements(t_dlist **stack_a, t_dlist **stack_b,
								int action_a, int action_b)
{
	if (action_a == action_b)
	{
		if (action_a == -1)
			reverse_rotate_r(stack_a, stack_b, 'r');
		else if (action_a == 1)
			rotate_r(stack_a, stack_b, 'r');
		else if (action_a == 0 && action_b == 0)
			push_a(stack_a, stack_b);
	}
	else
	{
		if (action_a == -1)
			reverse_rotate_a(stack_a, 'a');
		else if (action_a == 1)
			rotate_a(stack_a, 'a');
		if (action_b == -1)
			reverse_rotate_b(stack_b, 'b');
		else if (action_b == 1)
			rotate_b(stack_b, 'b');
	}
}

static t_dlist	*find_cost_min(t_dlist **stack_b)
{
	t_dlist	*to_move;
	int		cost_min;

	cost_min = INT_MAX;
	to_move = *stack_b;
	while (to_move)
	{
		if (to_move->cost < cost_min)
			cost_min = to_move->cost;
		to_move = to_move->next;
	}
	to_move = *stack_b;
	while (to_move && cost_min != to_move->cost)
		to_move = to_move->next;
	return (to_move);
}

void	determine_next_movement(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*to_move;
	int		action_b;
	int		action_a;

	to_move = find_cost_min(stack_b);
	if (!to_move)
		return ;
	action_a = INT_MAX;
	action_b = INT_MAX;
	while (!(action_a == 0 && action_b == 0))
	{
		action_b = move_to_top(to_move, stack_b);
		if (to_move->target)
			action_a = move_to_top(to_move->target, stack_a);
		else
			action_a = 0;
		optimize_movements(stack_a, stack_b, action_a, action_b);
	}
}

void	finish_sort(t_dlist **stack_a)
{
	t_dlist	*tmp;
	int		i;
	int		len;

	tmp = *stack_a;
	i = 0;
	while (tmp->next && tmp->value < tmp->next->value)
	{
		i++;
		tmp = tmp->next;
	}
	len = dlst_size(stack_a);
	if (tmp->index <= (len / 2))
	{
		while (i-- >= 0)
			rotate_a(stack_a, 'a');
	}
	else
	{
		while (i++ != len - 1)
			reverse_rotate_a(stack_a, 'a');
	}
}
