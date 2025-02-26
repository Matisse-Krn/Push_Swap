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
 *   Moves the top element from stack_b to the top of stack_a.
 *   If stack_b is empty, the function does nothing.
 *   The function removes the first node from stack_b and inserts it
 *   at the beginning of stack_a. If stack_a is empty, the moved node
 *   becomes the only element; otherwise, it is linked before the
 *   current head. After insertion, indices in both stacks are updated,
 *   and the operation "pa" is printed.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. If stack_b is empty, returns immediately.
 *   2. Saves the top node of stack_b in a temporary variable.
 *   3. Advances stack_b's head to the next node and, if it exists,
 *      resets its previous pointer.
 *   4. Inserts the saved node at the top of stack_a:
 *        - If stack_a is empty, initializes it with the node.
 *        - Otherwise, links the node before the current head.
 *   5. Reassigns indices in both stacks.
 *   6. Prints "pa" to indicate the push operation.
 *
 * Returns:
 *   void.
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
