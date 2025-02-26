/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:42:59 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 19:49:55 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: set_final_cost
 * ------------------------
 * Description:
 *   Updates the cost of each node in stack_b by adding the cost
 *   of its target node. It traverses stack_b and, for each node,
 *   accumulates its own cost with the cost from its target.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Returns:
 *   - void.
 */
static void	set_final_cost(t_dlist **stack_b)
{
	t_dlist	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		tmp->cost += tmp->target->cost;
		tmp = tmp->next;
	}
}

/*
 * Function: set_cost_to_top
 * -------------------------
 * Description:
 *   Computes and sets a "cost" for nodes in both stack_a and stack_b.
 *   The cost represents the number of moves needed to bring a node
 *   to the top of its respective stack.
 *
 *   For each node in stack_b, if its index is less than or equal to half
 *   the size of stack_b, its cost is set to its index; otherwise, the cost
 *   is set to (len_b - index). The same logic applies for stack_a.
 *
 *   Finally, set_final_cost() is called to add the target's cost to each
 *   node in stack_b.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Returns:
 *   - void.
 */
void	set_cost_to_top(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;
	int		len_a;
	int		len_b;

	len_a = dlst_size(stack_a);
	len_b = dlst_size(stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index <= (len_b / 2))
			tmp->cost = tmp->index;
		else if (tmp->index > (len_b / 2))
			tmp->cost = (len_b - tmp->index);
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index <= (len_a / 2))
			tmp->cost = tmp->index;
		else if (tmp->index > (len_a / 2))
			tmp->cost = (len_a - tmp->index);
		tmp = tmp->next;
	}
	set_final_cost(stack_b);
}

/*
 * Function: find_minimum_target
 * -----------------------------
 * Description:
 *   Searches through stack_a to find the node with the smallest value.
 *   This node is used as the target for a node in stack_b when no node
 *   in stack_a has a value greater than that node.
 *
 *   The function first determines the minimum value in stack_a, then
 *   returns the node that holds this minimum value.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *
 * Returns:
 *   - Pointer to the node in stack_a with the minimum value.
 */
static t_dlist	*find_minimum_target(t_dlist **stack_a)
{
	t_dlist	*tmp;
	int		min;

	tmp = *stack_a;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp->value != min)
		tmp = tmp->next;
	return (tmp);
}

/*
 * Function: set_target
 * --------------------
 * Description:
 *   Assigns a target node from stack_a to each node in stack_b.
 *   For each node in stack_b, it looks for the node in stack_a with the
 *   smallest value that is greater than the current node's value.
 *
 *   If no such node exists (i.e., the node's value is greater than all
 *   nodes in stack_a), the function assigns the node with the minimum value
 *   from stack_a as the target.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Returns:
 *   - void.
 */
void	set_target(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*to_move;
	t_dlist	*in_a;
	long	nearest_value;

	to_move = *stack_b;
	while (to_move)
	{
		in_a = *stack_a;
		nearest_value = LONG_MAX;
		while (in_a)
		{
			if (in_a->value > to_move->value && nearest_value > in_a->value)
			{
				to_move->target = in_a;
				nearest_value = in_a->value;
			}
			in_a = in_a->next;
		}
		if (nearest_value == LONG_MAX)
			to_move->target = find_minimum_target(stack_a);
		to_move = to_move->next;
	}
}
