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

/*
 * Function: sort_three
 * ----------------------
 * Description:
 *   Sorts a stack of exactly three elements in ascending order.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head of stack A.
 *
 * Behavior:
 *   1. If the first element is the largest, it rotates the stack.
 *   2. Else if the second element is the largest, it reverse rotates.
 *   3. Finally, if the first element is greater than the second, it swaps them.
 *
 * Returns:
 *   - void.
 */
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

/*
 * Function: loop_sort
 * -------------------
 * Description:
 *   Repeatedly performs sorting steps until stack B is empty.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head of stack A.
 *   - t_dlist **stack_b: Pointer to the head of stack B.
 *
 * Behavior:
 *   Loops while stack B is non-empty, and in each iteration:
 *     - Sets the target node for each node in stack B.
 *     - Computes the cost to bring nodes to the top.
 *     - Determines the next movement to perform.
 *
 * Returns:
 *   - void.
 */
static void	loop_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_b)
	{
		set_target(stack_a, stack_b);
		set_cost_to_top(stack_a, stack_b);
		determine_next_movement(stack_a, stack_b);
	}
}

/*
 * Function: sort_stacks
 * ---------------------
 * Description:
 *   Main sorting routine that organizes both stacks using a mix of
 *   strategies based on the number of elements.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head of stack A.
 *   - t_dlist **stack_b: Pointer to the head of stack B.
 *   - int len: Total number of elements in stack A.
 *
 * Behavior:
 *   1. Finds the median value in stack A by locating the node whose
 *      median flag is set.
 *   2. Pushes (len - 3) elements from stack A to stack B.
 *      a. After each push, if the pushed value exceeds the median,
 *         rotates stack B.
 *   3. If stack A is not sorted in ascending order, sorts the three
 *      remaining elements.
 *   4. If stack B is empty after pushing, exits early.
 *   5. Calls loop_sort to process the remaining elements.
 *   6. Finishes the sorting with finish_sort.
 *
 * Returns:
 *   - void.
 */
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
		if (!(*stack_b))
			return ;
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
