/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:17 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 10:29:42 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: push_a
 * ----------------
 * Description:
 *   Moves the top element from stack_b to stack_a.
 *   If stack_b is empty, the function returns immediately.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. Checks that stack_b is non-empty.
 *   2. Saves the top element of stack_b in a temporary node.
 *   3. Advances stack_b to its next node and resets its prev pointer.
 *   4. Inserts the temporary node at the beginning of stack_a.
 *   5. Sets the moved node's name to 'a'.
 *   6. Reassigns indices for both stacks.
 *   7. Prints "pa" to indicate the push operation.
 *
 * Returns:
 *   - void.
 */
void	push_a(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = tmp;
	*stack_a = tmp;
	(*stack_a)->name = 'a';
	reassign_index(stack_a, stack_b);
	ft_printf("pa\n");
}

/*
 * Function: push_b
 * ----------------
 * Description:
 *   Moves the top element from stack_a to stack_b.
 *   If stack_a is empty, the function returns immediately.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. Checks that stack_a is non-empty.
 *   2. Saves the top element of stack_a in a temporary node.
 *   3. Advances stack_a to its next node and resets its prev pointer.
 *   4. If stack_b is empty:
 *        a. Sets the temporary node's next and prev to NULL.
 *        b. Sets its name to 'b' and assigns it as the head of stack_b.
 *      Otherwise:
 *        a. Inserts the temporary node at the beginning of stack_b.
 *        b. Updates the old head's prev pointer.
 *        c. Sets the moved node's name to 'b'.
 *   5. Reassigns indices for both stacks.
 *   6. Prints "pb" to indicate the push operation.
 *
 * Returns:
 *   - void.
 */
void	push_b(t_dlist **stack_a, t_dlist **stack_b)
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
	ft_printf("pb\n");
}
