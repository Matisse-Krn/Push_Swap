/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:17 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 05:53:07 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * Function: push_a_bonus
 * ----------------------
 * Description:
 *   Moves the top element from stack B to the top of stack A.
 *   If stack B is empty, the function does nothing.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. If stack B is empty, returns immediately.
 *   2. Saves the top node of stack B in a temporary variable.
 *   3. Moves stack B's head to the next node and resets its previous
 *      pointer if necessary.
 *   4. Inserts the saved node at the top of stack A:
 *      - If stack A is empty, the node is initialized as the only element.
 *      - Otherwise, the node is linked before the current head.
 *   5. Reassigns indices in both stacks to maintain consistency.
 *
 * Returns:
 *   void.
 */
void	push_a_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (!(*stack_a))
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->name = 'a';
		*stack_a = tmp;
	}
	else
	{
		tmp->next = *stack_a;
		(*stack_a)->prev = tmp;
		*stack_a = tmp;
		(*stack_a)->name = 'a';
	}
	reassign_index(stack_a, stack_b);
}

/*
 * Function: push_b_bonus
 * ----------------------
 * Description:
 *   Moves the top element from stack A to the top of stack B.
 *   If stack A is empty, the function does nothing.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. If stack A is empty, returns immediately.
 *   2. Saves the top node of stack A in a temporary variable.
 *   3. Moves stack A's head to the next node and resets its previous
 *      pointer if necessary.
 *   4. Inserts the saved node at the top of stack B:
 *      - If stack B is empty, the node is initialized as the only element.
 *      - Otherwise, the node is linked before the current head.
 *   5. Reassigns indices in both stacks to maintain consistency.
 *
 * Returns:
 *   void.
 */
void	push_b_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (!(*stack_b))
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->name = 'b';
		*stack_b = tmp;
	}
	else
	{
		tmp->next = *stack_b;
		(*stack_b)->prev = tmp;
		*stack_b = tmp;
		(*stack_b)->name = 'b';
	}
	reassign_index(stack_a, stack_b);
}
