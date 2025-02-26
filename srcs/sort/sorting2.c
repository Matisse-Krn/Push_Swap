/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:36:49 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/26 01:11:06 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: move_to_top
 * ---------------------
 * Description:
 *   Determines the movement direction required to bring a given node
 *   to the top of its stack.
 *
 * Parameters:
 *   - t_dlist *to_move: The node that needs to be moved.
 *   - t_dlist **stack: Pointer to the head pointer of the stack.
 *
 * Returns:
 *   - 1 if the node is in the upper half (rotate is needed).
 *   - -1 if the node is in the lower half (reverse_rotate is needed).
 *   - 0 if the node is already at the top (no need to move) or is NULL.
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

/*
 * Function: optimize_movements
 * ----------------------------
 * Description:
 *   Optimizes the movement operations for two stacks based on
 *   provided action values. If both actions are the same, a
 *   simultaneous rotation is performed; otherwise, individual
 *   rotations are applied.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - int action_a: Movement directive for stack A (1, -1, or 0).
 *   - int action_b: Movement directive for stack B (1, -1, or 0).
 *
 * Returns:
 *   - void.
 */
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

/*
 * Function: find_cost_min
 * -----------------------
 * Description:
 *   Searches stack B for the node with the smallest cost.
 *   First determine the minimum cost value, then returns
 *   the first node that matches this cost.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Returns:
 *   - Pointer to the node with the minimum cost.
 */
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


/*
 * Function: determine_next_movement
 * ---------------------------------
 * Description:
 *   Determines the next movement to perform by selecting the node
 *   in stack B with the minimum cost and calculating the movements
 *   needed for both that node and its target in stack A.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Returns:
 *   - void.
 */
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
		action_a = move_to_top(to_move->target, stack_a);
		optimize_movements(stack_a, stack_b, action_a, action_b);
	}
}

/*
 * Function: finish_sort
 * ---------------------
 * Description:
 *   Finalizes the sorting of stack A by rotating it until the entire
 *   stack is in ascending order.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *
 * Behavior:
 *   1. Traverses stack A until a disruption in ascending order is found.
 *   2. Determines if the rotation should be performed forwards or
 *      backwards based on the node's index.
 *   3. Rotates stack A accordingly to complete the sort.
 *
 * Returns:
 *   - void.
 */
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
