/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:14:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/16 10:14:20 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: rotate_a
 * ------------------
 * Description:
 *   Rotates stack_a by moving the first node to the end of the list.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - char name: Operation identifier. If 'a', prints "ra".
 *
 * Behavior:
 *   1. If stack_a is empty or has only one node, does nothing.
 *   2. Stores the first node in 'last' and finds the last node in 
 *      'init_last'.
 *   3. Updates the head pointer to the second node.
 *   4. Sets the former first node's 'prev' to the last node and its 
 *      'next' to NULL.
 *   5. Updates the old last node's 'next' to point to the moved node.
 *   6. If name equals 'a', prints "ra".
 *   7. Reassigns indices for stack_a.
 *
 * Returns:
 *   - void.
 */
void	rotate_a(t_dlist **stack_a, char name)
{
	t_dlist	*init_last;
	t_dlist	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	init_last = *stack_a;
	while (init_last->next)
		init_last = init_last->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last->prev = init_last;
	last->next = NULL;
	init_last->next = last;
	if (name == 'a')
		ft_printf("ra\n");
	reassign_index(stack_a, NULL);
}

/*
 * Function: rotate_b
 * ------------------
 * Description:
 *   Rotates stack_b by moving the first node to the end of the list.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - char name: Operation identifier. If 'b', prints "rb".
 *
 * Behavior:
 *   1. If stack_b is empty or has a single node, does nothing.
 *   2. Stores the first node in 'last' and locates the last node in 
 *      'init_last'.
 *   3. Updates the head pointer to the second node.
 *   4. Sets the former first node's 'prev' to the last node and its 
 *      'next' to NULL.
 *   5. Updates the old last node's 'next' to point to the moved node.
 *   6. If name equals 'b', prints "rb".
 *   7. Reassigns indices for stack_b.
 *
 * Returns:
 *   - void.
 */
void	rotate_b(t_dlist **stack_b, char name)
{
	t_dlist	*init_last;
	t_dlist	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	init_last = *stack_b;
	while (init_last->next)
		init_last = init_last->next;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last->prev = init_last;
	last->next = NULL;
	init_last->next = last;
	if (name == 'b')
		ft_printf("rb\n");
	reassign_index(NULL, stack_b);
}

/*
 * Function: rotate_r
 * ------------------
 * Description:
 *   Rotates both stack_a and stack_b simultaneously.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - char name: Operation identifier. If 'r', performs both rotations.
 *
 * Behavior:
 *   1. If name equals 'r', calls rotate_a() and rotate_b() for the two
 *      stacks.
 *   2. Prints "rr" to indicate the dual rotation.
 *
 * Returns:
 *   - void.
 */
void	rotate_r(t_dlist **stack_a, t_dlist **stack_b, char name)
{
	if (name == 'r')
	{
		rotate_a(stack_a, name);
		rotate_b(stack_b, name);
		ft_printf("rr\n");
	}
}
