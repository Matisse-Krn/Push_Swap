/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:16:11 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/17 20:48:37 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: reverse_rotate_a
 * --------------------------
 * Description:
 *   Performs a reverse rotation on stack_a by moving the last element
 *   to the front of the list.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - char name: Identifier; if 'a', prints "rra".
 *
 * Behavior:
 *   1. If stack_a is empty or has a single element, does nothing.
 *   2. Traverses the list to find the last node.
 *   3. Detaches the last node from its previous position.
 *   4. Inserts it at the beginning of the list.
 *   5. Updates pointers of the new second node.
 *   6. If name is 'a', prints the command "rra".
 *   7. Reassigns indices for stack_a.
 *
 * Returns:
 *   - void.
 */
void	reverse_rotate_a(t_dlist **stack_a, char name)
{
	t_dlist	*first;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	while (first->next)
		first = first->next;
	first->prev->next = NULL;
	first->next = *stack_a;
	first->prev = NULL;
	*stack_a = first;
	(*stack_a)->next->prev = first;
	if (name == 'a')
		ft_printf("rra\n");
	reassign_index(stack_a, NULL);
}

/*
 * Function: reverse_rotate_b
 * --------------------------
 * Description:
 *   Performs a reverse rotation on stack_b by moving the last element
 *   to the front of the list.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - char name: Identifier; if 'b', prints "rrb".
 *
 * Behavior:
 *   1. If stack_b is empty or has only one element, does nothing.
 *   2. Traverses the list to find the last node.
 *   3. Detaches the last node from its current position.
 *   4. Inserts it at the beginning of the list.
 *   5. Updates the previous pointer of the new second node.
 *   6. If name is 'b', prints the command "rrb".
 *   7. Reassigns indices for stack_b.
 *
 * Returns:
 *   - void.
 */
void	reverse_rotate_b(t_dlist **stack_b, char name)
{
	t_dlist	*first;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	while (first->next)
		first = first->next;
	first->prev->next = NULL;
	first->next = *stack_b;
	first->prev = NULL;
	*stack_b = first;
	(*stack_b)->next->prev = first;
	if (name == 'b')
		ft_printf("rrb\n");
	reassign_index(NULL, stack_b);
}

/*
 * Function: reverse_rotate_r
 * --------------------------
 * Description:
 *   Performs a reverse rotation on both stack_a and stack_b.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - char name: Identifier; if 'r', performs both rotations.
 *
 * Behavior:
 *   1. If name is 'r', calls reverse_rotate_a() on stack_a and
 *      reverse_rotate_b() on stack_b.
 *   2. Prints the command "rrr" after both rotations.
 *
 * Returns:
 *   - void.
 */
void	reverse_rotate_r(t_dlist **stack_a, t_dlist **stack_b, char name)
{
	if (name == 'r')
	{
		reverse_rotate_a(stack_a, name);
		reverse_rotate_b(stack_b, name);
		ft_printf("rrr\n");
	}
}
